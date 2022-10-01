# Rate Limiter

## Clarifications
- Does the rate limiter throttle API requests based on IP, the user ID, or other properties?
- Do we need to throttle internal requests too?
- Do we also need to implement timeout?
- Is the rate limiter a separate service or should it be implemented in application code?
- Is the rate limiter per global or microservice level?

## Requirements
- Accurately limit excessive requests.
- ### Low latency. The rate limiter should not slow down HTTP response time.
- Use as little memory as possible.
- ### Distributed rate limiting. The rate limiter can be shared across multiple servers or processes.
- ### Exception handling. Show clear exceptions to users when their requests are throttled.
- High fault tolerance. If there are any problems with the rate limiter (for example, a cache server goes offline), it does not affect the entire system.
- Configurable Rate limiting algorithm.

## High Level Design



### Algorithm used for external rate-limiting
#### Token Bucket Algorithm
Look at the insider guide
- For every user/IP there needs to be one bucket, and the total buckets can shoot up, and adding the token to them is going to consume time. CRON job has to be run. some process needs to keep refilling the buckets. With several million users, and each refill operation requiring a write, this would be an unsustainable load on our Redis instance. 
- Also if we set a maximum of 10 message per minute, we didn’t want a user to be able to receive 10 messages at 0:59 and 10 more messages at 1:01. Token bucket doesn't solve this.
- A hefty request can be made to require more than one token too.

#### Modified Token Bucket to solve cron job problem
- Have 2 entries per user in Cache, one is the token bucket and the other is a timestamp it was last filled. If current time stamp - last filled is less than interval, the token bucket wasn't filled and you can simply decrement the token bucket, else token bucket was refilled to the max, so update the timestamp now. [link](https://engineering.classdojo.com/blog/2015/02/06/rolling-rate-limiter/)

#### Leaky Bucket Algorithm (Used by java itself)
Look at the insider guide
- This notion of buffer capacity (but not necessarily the use of leaky buckets) also applies to components adjacent to your service, such as load balancers and disk I/O buffers

#### Fixed window
Fixed-window limits—such as 3,000 requests per hour or 10 requests per day—are easy to state, but they are subject to spikes at the edges of the window, as available quota resets. Consider, for example, a limit of 3,000 requests per hour, which still allows for a spike of all 3,000 requests to be made in the first minute of the hour, which might overwhelm the service.

#### Sliding window
- Sliding windows have the benefits of a fixed window, but the rolling window of time smooths out bursts. Systems such as Redis facilitate this technique with expiring keys. So each user has a sorted set, and on each request, remove all the outdated timestamps. Outdated timestamps are defined as those older than the start of the current time window.

- • It smooths out spikes in traffic because the rate is based on the average rate of the previous window

![](res/rate_limiting_sliding_window.png)

#### Timer Wheel (Also has timeout capability)
- Might be useful for global rate limiting more.
- The wheel has buckets and each bucket can only store limited request.
- When a request arrives we compute, taskArrivalTime mod bucketSize.
- The timer wheel is of size = timeout in seconds.
- When you enter a section of wheel, you kick all the requests in that section (they timed out).
- Also each section of wheel corresponds to a seconds and has a queue = rate-limiting say=3 per second. Then size of linkedlist = 3.
- You get both ratelimiting and timeout capability in this approach.
![](res/gkcs_timer_wheel.jpg)

### Persistent or In Memory storage.
Using the database is not a good idea due to slowness of disk
access. In-memory cache is chosen because it is fast and supports time-based expiration strategy
#### Redis
- INCR :  It increases the stored counter by 1 atomically.
- EXPIRE : It sets a timeout for the counter. If the timeout expires, the counter is automatically deleted.

- #### So for each user there can be a counter with expiration of 1 second, if the counter reaches a value within the expiration the subsequent requests are dropped. This is the fixed window algorithm.

### How to handle internal rate-limiting
- Rate-limiting in service as well. Based on average-response-rate, length of dead letter queue, CPU Usage, Memory Usage.
- Implement patterns like Circuit breaker and Bulk head patterns to prevent cascading failures.

#### Deal with bad actors
- Request queue(Array Blocking Queue) for each server can be partitioned to serve request ID per Hash, each internal server will have unique ID, and the parition for the bad actor will be only blocked, rest of the paritions will be safe.

### How to configure the rate limiting algorithm.
-  Rules are generally written in configuration files and saved on disk.

### What to do with the dropped requests
- Dead letter queue. Notify the subscriber if length is too high, used to monitoring and analysis.
- We can also enqueue these requests to be processed later. If some orders are rate limited due to system overload, we may keep those orders to be processed later.

#### Client side ratelimiting
- Will help with unintentional D-DOS
- Have the client retry with exponential backoff.
- Also have errors divided as retriable and non-retriable errors, so non retriable errors don't bomb the server. 
- The rate limiter can return the following HTTP headers to clients:
    - X-Ratelimit-Remaining
    - X-Ratelimit-Limit
    - X-Ratelimit-Retry-After
- Use client cache to avoid making frequent API calls

#### Exception Handling
-  The HTTP 429 response status code indicates a user has sent too many requests.
- Client's should not retry only on retriable errors.



### Scaling rate-limiting.
- Multiple requests to redis, need thread safety (against race conditions and synchronization issues). So use a single master redis server (maybe do sharding what happens on failure of shard), and also sorted set in redis helps with race condition without locking.

![](res/rate_limiting_sdig.png)

## Questions
- In the sliding window log algorithm, Cons it is mentioned The algorithm consumes a lot of memory because even if a request is rejected, its timestamp might still be stored in memory. Why store the timestamp if it is rejected.
- How does token bucket allow burst traffic, but leaky queue prevent it.

## Misc
- Cascading Failures
- Circuit Breaker
- Request Collapsing
- Bulk Head pattern
- Intelligent Routing.
- Layer 4 rate-limiting using IP Tables.


# Design Consistent Hashing
- Ring 0 to Limit of the hashfunction(0 to 2^160 - 1 for SHA-1).
- Servers and requests mapped to this ring, using the above hashfunction.
- Virtual nodes can be used to make sure the servers have uniform load and in the event of server adding or removing only k/n keys needs to be moved, where k is the total keys and n is the total real nodes.
![](res/consistent_hashing.png)
- In the above images s0_0, s0_1, s0_2 are the virtual nodes for 0th server, s1_0, s1_1, s1_2 are for 1st server.
- Once a request/key is mapped to the ring, move clockwise and the first virtual node encountered is the server which should serve the request or the cache with the value corresponding to the key.
- Consistent hashing can be used for load balancing of application servers, sharding of cache and db servers.
- Consistent hashing is widely used in real-world systems, including some notable ones:
    - Partitioning component of Amazon’s Dynamo database
    - Data partitioning across the cluster in Apache Cassandra
    - Discord chat application
    - Akamai content delivery network
    - Maglev network load balancer

# Design Key Value store

## Clarifications
- If the key-value store should be in-memory or persistent?
- Is it distributed and we need to think of concurrency?
- What about availability? On failure what should happen? What happens on network failure during syncing?
- Requests per second.
- Read to write ratio
- What happens in the event of failure and the server comes back up.
- What is the size of value to be stored.

## Requirements
- Horizontal Autoscaling (HAS)
- Tunable Consistency
- Low latency
- size of key-value is 10KB
- Ability to store huge data.

## High level design

### To store huge data
- Data compression
- Store most used in memory and rest in disk
- A distributed key-value store is required to support big data.

### Scalability
- Sharding
- Consistent Hashing
- Horizontal Auto Scaling
- Heterogeneity: Total virtual nodes of a server are proportional to server capacity.

### Consistency
- Quorum, Tunable consistency parameters, Consistency models (Strong vs Eventually consistent), CAP Theorem
- Versioning, Vector clocks, client conflict resolution

### Availability
- Replication
- Cross data-center replication too.

#### Failure Handling
- Detection: Gossip protocol vs Phi Accrual Failure Detection
- Temporary Failure Handling : Sloppy Quorum, Hinted Handoff
- Permanent Failure Handling : Read Repair/Merkle Trees for optimized synching. (When is this used vs when is sloppy quorum used?) Anti-entropy protocol?

### In memory db consideration

#### Durability
- Segmented Write ahead log (Commit log)
- High water mark

#### Low Latency
##### Write Latency
- In memory (memTable)
- SSTable (Sequential Writes)
- Compaction

##### Read latency
- In memory read
- Bloom filters (Why not using hashtable for indexing?)

## Questions
- When is Sloppy Quorum with hinted handoff used vs when is merkle trees used?

# Unique ID Generator

## Clarifications
- Do ID only contain numerical values or alphanumneric?
- What should be the length of the unique ID generated.
- Scalable system.
- Do Ids need to be sortable?
- How many Ids per second?
- Does the Ids need to be strictly sorted i.e a user who came 2 mins earlier should have Id lesser than current user.

## Requirements
- Scalable
    - Concurrency safe
    - High throughput
- Highly Available
- Low latency
- No conflicting ID.
- Ids should increment by time, not necessarily by 1.
- 10000 Ids per second.
- 64 bit length

## High Level Design

### UUID Approach
#### Pros
- No syncronization needed, very low probability of duplicate
- Scalable solution, ideal production solution for ids of tables.
#### Cons 
- 128 bit length
- IDs don't go up with time.
- IDs can be non numeric.

### Ticket Server
- Single ticket server to give the uuids to webservers.
#### Cons
- Single point of failure.

### Twitter snowflake approach
-  Instead of generating an ID directly, we divide an ID into different sections.
![](res/twitter_snowflake.png)
- Signbit : not in use apparently by twitter
- Timestamp : Epoch time in milliseconds. (Max is 2^41 ~ valid for 69 years more)
- datacenterId : Id of the datacenter. (32 datacenter limit)
- machineId : 32 machines from cluster.
- Sequence numbers : For every Id generated the Id in the machine increases by 1. This field is 0 unless more than one ID is generated in a millisecond on the same server. In theory, a machine can support a maximum of 4096 new IDs per millisecond.
-  fewer sequence numbers but more timestamp bits are effective for low concurrency and long-term applications.
### NTP for clock synchronisation
- The Network Time Protocol (NTP) is a networking protocol for clock synchronization between computer systems over packet-switched, variable-latency data networks.
- NTP servers have access to highly precise atomic clocks and GPU clocks.
- NTP is a protocol that works over the application layer, it uses a hierarchical system of time resources and provides synchronization within the stratum servers