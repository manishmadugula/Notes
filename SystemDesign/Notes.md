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
  
  -  https://medium.com/hackernoon/fundamentals-of-system-design-part-3-8da61773a631
  
  - https://stackoverflow.com/questions/7306316/b-tree-vs-hash-table
  
  - https://www.youtube.com/watch?v=aZjYr87r1b8

            
# Apache vs NGINX
- Apache is process driven and create a new thread for each request.
- NGINX is event driven and handles multiple requests within one thread.

![Apache vs NGINX](res/apache_nginx.png)