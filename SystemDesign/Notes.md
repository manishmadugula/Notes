# Notes


# Netflix Talk on Microservices
## Advantages
  - Separation of concerns
  - Horizontal Scaling
  - Workload Partitioning
  - Automated operations
  - On demand provisioning
  - Context bound and data separation


## Challenges - Dependency
### Intra Service communications
- Network Latency
- Network Congestion
- Network Failure
- Logical or Scaling Failure
- Even if a single service has 99.99 availability, all services as a whole will have a lot less. Say 10 services =~ 99.9 Availability.
- ### Cascading Failures, one service fails and as a result a lot more services are failed.
  - Use hystrix to give out a fallback response so the client doesn't have to recieve an error but is given some default response.
    - ![](res/hystrix.jpg)
  - Testing using fault injection in production(FIT)
    - Throughout the call path.
    - Mock live traffic.
  - Identify critical services and isolate them, make sure the application functions if everything is down.


### Persistence
#### CAP Theorem
- In the presense of network partition you must choose between consistency and availability.
#### Consistency vs Availability in Cassandra
- Using Quorum, you can choose level of consistency and trade of with availability in your system.

### Infrastructure
- Infrastructure can fail
- So better to have a multi region architecture


### Solutions
- Circuit breakers, fallbacks, chaos testing
- Simple clients
- Eventual Consistency
- Multi-region failover

## Challenges - Scale

### For Stateless Service

#### Defination of stateless
- Not a cache/database.
- Frequently accessed meta data.
- No instance affinity of client.
- Loss of a node is a non event.

#### Solution for Scale for stateless service
- Autoscaling Group helps scaling very easily, nodes get replaced easily
  - Helps absorb, DDOS Attacks, performance hits etc.
  - Test using chaos testing.


### For Stateful Service

#### Defination of stateful service
- Databases and cache
- Avoid storing business logic and state in one application.
- Loss of a node is a notable event, it may take hours to replace a node.

#### Solution for Scale for stateful service

- Dedicated Shards (Single Point of Failure) ANTI PATTERN
- Redundancy using EVCache (Wrapper around Memcached, sharded but multiple copies are written to multiple nodes and different AZs).
  - Reads are local.
- EXCESSIVE LOAD IN SINGLE CACHE CLUSTER
  - IF CACHE CLUSTER GOES DOWN, THE ENTIRE load will be on the service and database, which will then fail due to so much requests.
    - Have different systems for batch processing and realtime processing
    - Chaos testing
    - Request level caching??


## Challenges - Variance/ Variaty in your architecture
### Operational drift
- Unintentional, happens naturally.
- Overtime throughput changes
- Untuned timeouts and retries and fallback. 
#### Solutions
- #### CONTINUOS LEARNING AND AUTOMATION
  - Incident review and remediation and analysis of the pattern.
  - And then automate and drive adoption.
  - Squeeze testing to make sure throughput is same
  - Tune the timouts, retries and fallback etc.
  - Alerts
  - Proper configuration of apache and tomcat
  - automated canary analysis
  - autoscaling
  - chaos testing
  - ELB Configs
  - Healthchecks
  - Immutable machine images/AMI
  - Stages, red/black deployments
  - Staging deployment so you don't deploy bad code to all the places simultaneously.


### Polyglot & Containers 
- Introduce new technologies.

#### Solutions
- Raise awareness of cost beforehand.
- Constrain centralized support.
- Prioritize by impact.
- Use GRPC type code generation for multiple client libraries.

## How to get velocity in development with confidence
Use integrated and automated pipelines (spinnaker)
- Conformity Checks
- Red/Black Pipeline
- Automated Canaries
- Staged Deployment to multiple regions
- Squeeze tests


## CONWAY'S LAW
- Any piece of software reflects the organizational structure that produced it. If you have 4 teams working on compiler, you will end up with 4 pass compiler.
- It should be solution's first, team second.
- Reconfigure teams to best support your architecture.

# Source -> Gaurav-Sen

* ## XMPP -> peer to peer protocol. Extensible Messaging and Presence Protocol 

* ## Websockets

* ## XMPP vs Websockets

* ## Distributed Caching
    * ### Uses
        * Speeds up responses
            1. Save network calls.
            2. Avoiding computations by storing computations in cache.
        * Reduce database load.

    * ### Cache should have relevant information
        * When to load data and erase in cache (cache policies)
            1. Least Recently Used entry (LRU).
            2. Least Frequently Used (LFU).
    
    * ### Things that can go wrong
        * poor policy leads to more cache misses.
        * thrashing, you populate cache with data but before using it you delete it.
        * consistency

    * ### where to place cache
        * Closer to server (Simple and fast response)
            *  easier to implement
            *  low network calls.
            *  memory is shared between server and cache so they will compete

    * ### Distributed global cache (Redis) (Used in real life scenarios).
        * avoiding queries and memory and computations on database.
        * no single point of failure.
        * Scales independently of server.
        
    * ### consistency of cache.
        * Write through -> make all the updates go through cache first then write to database.
            * Problems
                * performance on write.
                * consistently update the data on all caches and entities.

        * Write Back -> hit database directly and then you make sure you either delete or update the entity in cache.
            * Expensive. as once you write to database you need to write back to all the cache in the server of distributed network. this is unnecessary in case of not so important data.
        
        * Hybrid Model ->for not so important data.
            * write on cache of one server, without caring about consistency on other servers, after some time take entries in bulk and persist inthe database.



* ## API Design
    * Good names
    * Parameters
    * No side effects i.e an api function saying setadmins should not also add members if they aren't part of group instead should return an error.
    * Multiple Operations is bad *  don't pass big objects to api.
    * Atomicity is important for some conditions.
    * Relevant error messages.
    * Break response in pieces so small response 
    * Pagination (just get first ten or ten from an offset).
    * Fragmentation (Break response into multiple pieces and give it to next service using packet numbers).
        
    * To cache or not to cache 
        * Perfect consistency 
        * slow, else caching 
        * fast
    
* ## SQL or NoSQL
        



# Indexing -
  
  - https://medium.com/hackernoon/fundamentals-of-system-design-part-3-8da61773a631
  
  - https://stackoverflow.com/questions/7306316/b-tree-vs-hash-table
  
  - https://www.youtube.com/watch?v=aZjYr87r1b8

            
# Apache vs NGINX
- Apache is process driven and create a new thread for each request.
- NGINX is event driven and handles multiple requests within one thread.

![Apache vs NGINX](res/apache_nginx.png)






# Concept of Encryption at motion and encryption at rest
-   Data can be exposed to risks both in transit and at rest and requires protection in both states. As such, there are multiple different approaches to protecting data in transit and at rest. Encryption plays a major role in data protection and is a popular tool for securing data both in transit and at rest. For protecting data in transit, enterprises often choose to encrypt sensitive data prior to moving and/or use encrypted connections (HTTPS, SSL, TLS, FTPS, etc) to protect the contents of data in transit. For protecting data at rest, enterprises can simply encrypt sensitive files prior to storing them and/or choose to encrypt the storage drive itself.

# Connection Pooling
In software engineering, a connection pool is a cache of database connections maintained so that the connections can be reused when future requests to the database are required. Connection pools are used to enhance the performance of executing commands on a database.

# Dynamo DB vs Elastic Cache for Session Storage


# Semaphore vs lock vs Mutex
- A lock allows only one thread to enter the part that's locked and the lock is not shared with any other processes.

- A mutex is the same as a lock but it can be system wide (shared by multiple processes).

- A semaphore does the same as a mutex but allows x number of threads to enter, this can be used for example to limit the number of cpu, io or ram intensive tasks running at the same time. Ex-> Chrome limits only 6 connections per hostname at a time.

- You also have read/write locks that allows either unlimited number of readers or 1 writer at any given time.


# Optimistic Lock vs Pessimistic Lock

## Pessimistic Lock
- This approach assumes that conflicting operations happen more frequently (that's why it's called pessimistic). Since the conflicts are common, this approach makes use of locks to prevent conflicting operations from executing, assuming that there is no significant overhead from their usage.
- Usual file locking mechanism, where if one thread/process acquires the lock, no one is allowed to update the locked file till the process with the lock/mutex releases the lock
- Used in db and log read write.
- It holds on to resources, no other concurrent actors can modify.
- Useful when more conflicts are there.
- Suceptible to deadlocks.
- Read Lock/Shared Lock -> Concurrent Process can read but can't write
- Write Lock/Exclusive Lock -> Concurrent Process can't read not write.
- Widely known algo for pessimestic lock is 2 Phase Locking (Not to be confused with 2 Phase Commit in Distributed Transaction).



## Optimistic Lock
- It is lock based on version number. The process/thread/person first reads both data and version number, he does processing on data and when he goes back to write the updated information, he checks if the version number is same as the time he read the data, if yes he writes the data and increments the version number, else someone else already updated the original data after it has been first read by the process. 
- It is used in wiki pedia, one person can read the data, meanwhile others are also allowed to read and write back before the first person wrote it back, this ensures other users are not blocked till the first user updated the article. 
- Also used in git version control, if someone else already updated before original person wrote back, we get merge conflicts and need to resolve.
- More performant since, optimistic lock won't hold on to resource.
- Useful when few conflicts are the

## Optimistic Lock Vs MVCC
- I think they are sometimes used interchangeably, and if the transaction only involves one object then they are essentially the same, but MVCC is an extension of optimistic concurrency (or a version of it) that provides guarantees when more than one object is involved. Say that you have two objects, A and B, which must maintain some invariant between them, e.g. they are two numbers whose sum is constant. Now, a transaction T1 subtracts 10 from A and adds it to B, while, concurrently, another transaction T2 is reading the two numbers. Even if you optimistically update A and B independently (CAS them), T2 could get an inconsistent view of the two numbers (say, if it reads A before it's modified but reads B after it's been modified). MVCC would ensure T2 reads a consistent view of A and B by possibly returning their old values, i.e., it must save the old versions.

- To sum up, optimistic locking (or optimistic concurrency control), is a general principle for synchronization w/o locks. MVCC is an optimistic technique which allows isolated transactions which span multiple objects.


# Distributed Transaction/Data Consistency
- 2 Phase Commit
  - Bad since co-ordinator is single point of failure.
- Sagas
  - You have a sub transaction (POST Payment and return ID) and a corresponding compensating transaction (Delete By Payment ID)
  - https://www.youtube.com/watch?v=xDuwrtwYHu8
  - You need an SEC, Stateless co-ordinator
  - You need a commit log/ kafka message bus to keep track of all the events happened
  - You need your comensating transaction to be idempotent.
  - You need your sub transaction to be idempotent too if you are going for forward recovery.
- ACID
  - Atomicity
    - Atomicity requires rolling back to previous state if the transaction wasn't successful.
    - You either have a succesful transaction(unit of work), or you roll back to previous state, there is no intermediate state.
  - Consistency
    - Different meaning than that of the CAP theorem's C.
    - Here it means all the data constraints are valid.
    - In CAP what C means if we are in a master slave architecture, the data should update in slave as soon as it updates in master.  
  - Isolation
    - We can't assume serializability cause concurrent process can also try to access the same resource. Interleaving concurrent transaction should execute as if they came in a serial way, once after the other. You need to use some sort of concurrency control.

    - You can avoid using 2 Phase Locking/ Pessimistic Locks
      - Acquire lock, process then commit/roll back the release the lock.
      - Locking is costly,
    - You can detech using Multi Version Concurrency control.

  - Durability
    - Once we commit, all the changes should be persisted, i.e they shouldnt go away once the power shuts off. Some databases delay the sync between memory and disk since that would lead to a lot of IO operation on disk, and they only write to disk at checkpoints. A solution to this is to use an append only logs, any time there is a write, you write to a commit log along with memory. Commit log append is fast and if the system shuts down with data in memory but not synced with disk, commit log can be used to recover the data.


# Amazon Locking System
- You can discuss 2 concepts, 
  - KD-Tree 
    -  All the lockers can be put in a data structure like (K_dimension tree), to effectively search lockers, based on k dimensions 
    - Implement ```find_Locker(item_id,size_requested,customer_latitude,customer_longitude)```
  - Distributed Transaction 
    -  Locker should only be booked when the payment's service is succeded. This will involve a distributed transaction like SAGAS.

# North South, East West Traffic
North/South traffic is the traffic heading in and out of your network. East/West traffic is the traffic from one server to another inside your network.


# Cache 
Read -> https://roadmap.sh/guides/http-caching

![](Cache.PNG)

## Cache Control

### private
Setting the cache to private means that the content will not be cached in any of the proxies and it will only be cached by the client (i.e. browser)

### public
If set to public, apart from being cached by the client, it can also be cached by the proxies; serving many other users

### no-store
no-store specifies that the content is not to be cached by any of the caches

### no-cache
no-cache indicates that the cache can be maintained but the cached content is to be re-validated (using ETag for example) from the server before being served. That is, there is still a request to server but for validation and not to download the cached content.
```Cache-Control: max-age=3600, no-cache, public```


# UDP Usecases
- For videos and real time gaming, it doesn't make sense to resend the lost packet, since on recieving it you will see things back in time so udp is a good protocol.[Link](https://www.youtube.com/watch?v=oIRkXulqJA4&list=PLIhvC56v63IJVXv0GJcl9vO5Z6znCVb1P&index=6)

# Forward and Reverse Proxy
https://roadmap.sh/guides/proxy-servers

# Using Heterogenous Job Processing Workflow
- For messages in SQS, a lambda can be written which sees if a demanding task is in queue and increase the resources in consumer.

# micro and macro service decisions
![](res/micro_macro%20decisions.jpg)

# Check these algorithms
- Count Min Sketch
- Consistent Hashing
- Bloom Filter
- LRU Cache
- B-Tree
- K-D Tree
- Merkel Trees
- Fenwick Tree
- Geohash / S2 Geometry
- Quadtree / Rtree
- Reverse index
- Distributed Rate Limiting
- HyperLogLog 
- Leaky bucket / Token bucket
- Trie algorithm
- Data lake
- Scale Cube Concept
- Twelve-Factor App
- Event-Sourcing (ES)
- Command Query Separation
- Command and Query Responsibility Segregation (CQRS) 
- Polyglot Persistence (PP)
- Domain Driven Design (DDD)
- Bounded Context (BC)

- Rsync algorithm
- Frugal Streaming
- Loosy Counting
- Operational transformation
- Ray casting
- Alon Matias Szegedy
- Hierarchical Timing Wheels

Ref -> https://leetcode.com/discuss/interview-question/547669/Algorithm-you-should-know-before-system-design.


# Misc
- Browser is sometimes called as **user-agent**.
- **User agent** flag in http request lets server knows from where the request came from operating system browser etc.
- HDFS -> Distributed File System.
- Transaction is a unit of work. And needs to be completed as a whole. The work should only be completed if all instructions inside the work are successful, else if there is some error in one of the instruction, the system should go back to previous state.
- Each transaction should aquire a lock on the db resource which is only to be released when the entire transaction is completed, to prevent concurrent access.
- Most databases implement transaction using a Write Ahead Lock ->


# Blogs to read
- https://medium.com/@Alibaba_Cloud/redis-vs-memcached-in-memory-data-storage-systems-3395279b0941#:~:text=Memcached%20has%20a%20higher%20memory,while%20Memcached%20utilizes%20multiple%20cores.
- https://gist.github.com/vasanthk/485d1c25737e8e72759f
- https://www.evernote.com/shard/s576/client/snv?noteGuid=75fbe53c-baed-47ca-9f58-a44038c63468&noteKey=05d51df458ea2cff&sn=https%3A%2F%2Fwww.evernote.com%2Fshard%2Fs576%2Fsh%2F75fbe53c-baed-47ca-9f58-a44038c63468%2F05d51df458ea2cff&title=2.%2BSystem%2BDesign%2BInterviews%2B-%2BWHERE%252C%2BWHAT%252C%2BHOW
- https://martin.kleppmann.com/2016/02/08/how-to-do-distributed-locking.html