# Notes




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
        



# Useful links
- Indexing -
  
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
- Usual file locking mechanism, where if one thread/process acquires the lock, no one is allowed to update the locked file till the process with the lock/mutex releases the lock
- Used in db and log read write.
- It holds on to resources, no other concurrent actors can modify.
- Useful when more conflicts are there.

## Optimistic Lock
- It is lock based on version number. The process/thread/person first reads both data and version number, he does processing on data and when he goes back to write the updated information, he checks if the version number is same as the time he read the data, if yes he writes the data and increments the version number, else someone else already updated the original data after it has been first read by the process. 
- It is used in wiki pedia, one person can read the data, meanwhile others are also allowed to read and write back before the first person wrote it back, this ensures other users are not blocked till the first user updated the article. 
- Also used in git version control, if someone else already updated before original person wrote back, we get merge conflicts and need to resolve.
- More performant since, optimistic lock won't hold on to resource.
- Useful when few conflicts are the

# Check these algorithms
Count Min Sketch
Consistent Hashing
Bloom Filter
LRU Cache
B-Tree
Merkel Trees
Fenwick Tree
Geohash / S2 Geometry
Quadtree / Rtree
Reverse index
Distributed Rate Limiting
HyperLogLog 
Leaky bucket / Token bucket
Trie algorithm

Rsync algorithm
Frugal Streaming
Loosy Counting
Operational transformation
Ray casting
Alon Matias Szegedy
Hierarchical Timing Wheels

Ref -> https://leetcode.com/discuss/interview-question/547669/Algorithm-you-should-know-before-system-design.




# Blogs to read
- https://medium.com/@Alibaba_Cloud/redis-vs-memcached-in-memory-data-storage-systems-3395279b0941#:~:text=Memcached%20has%20a%20higher%20memory,while%20Memcached%20utilizes%20multiple%20cores.
- https://gist.github.com/vasanthk/485d1c25737e8e72759f
- https://www.evernote.com/shard/s576/client/snv?noteGuid=75fbe53c-baed-47ca-9f58-a44038c63468&noteKey=05d51df458ea2cff&sn=https%3A%2F%2Fwww.evernote.com%2Fshard%2Fs576%2Fsh%2F75fbe53c-baed-47ca-9f58-a44038c63468%2F05d51df458ea2cff&title=2.%2BSystem%2BDesign%2BInterviews%2B-%2BWHERE%252C%2BWHAT%252C%2BHOW