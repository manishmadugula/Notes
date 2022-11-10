# 18.9.22
GeoDNS can be used to direct traffic to the nearest data center depending on where a user is located.
## Mobile app vs web app
- people need to download/update their app and that doesn't always happen at the same time for all usera. While in web context updates are happening instantaneously (mostly) for all customers with the deployment. Backward compatibility for mobile is a big problem, many try to utilise server side rendering for specific mobile app components etc.
- considerations with security with mobile apps too since the client has the compiled code, respectively if they decompile the code they could inject malicious instructions and control the behavior of the app within its business logic.

## Disadvantages of vertical scaling of database
- You can add more CPU, RAM, etc. to your database server, but there are hardware limits. If you have a large user base, a single server is not enough.
- Greater risk of single point of failures.
- The overall cost of vertical scaling is high. Powerful servers are much more expensive.

## Horizontal scaling of databases
- This is sharding.
- Each shard shares the same schema, though the actual data on each shard is unique to the shard.
- Consistent Hashing used to reshard the database.
- This is also called a hotspot key problem. Excessive access to a specific shard could cause server overload. Imagine data for Katy Perry, Justin Bieber, and Lady
Gaga all end up on the same shard. Thundering herd

## How to scale to millions of users basic
- Keep web tier stateless
- Build redundancy at every tier
- Cache data as much as you can
- Support multiple data centers
- Host static assets in CDN
- Scale your data tier by sharding
- Split tiers into individual services
- Monitor your system and use automation tools
- Use better protocols http 2.0, websockets, long polling (don't break connection)
- Compress your request before sending.
- Request collapsing, request condensing/batch fetch from db.

## Latency calculations
- Compress data before sending it over the internet if possible.
- Simple compression algorithms are fast.
- Memory is fast but the disk is slow.




# 20.9.22

## Advantages of using rate-limiting
- Prevent DOS (Security risk).
- Save money, especially for companies using third party infra.
- Predictable behavior.

## Advantages of using API Gateway
- API gateway is a fully managed
service that supports rate limiting.
- SSL termination
- authentication
- IP whitelisting
- servicing static content, etc.

# Techniques
- Instead of putting lock on every request, for some use-cases (where you need to provide a lease/unique Id)
- In chat systems use last seen date, rather than seeing if the user is online or not.
- Same as keeping date-of-birth column rather than age column, no need to update the age by cron job daily.
- Push vs Pull model (Celebrity use-case)
# Misc
- Stackoverflow only uses a single database
- EdgeRank is the name of facebook's feed ranking algorithm.

# Nice blogs
- https://nickcraver.com/blog/2013/11/22/what-it-takes-to-run-stack-overflow/


# 21.10.22
## 

# To-Do
- multi-masters and circular replication
- https://www.youtube.com/watch?v=m4_7W4XzRgk
- Bottlenecks, resource utilization
- https://medium.com/partha-pratim-sanyal/system-design-doordash-a-prepared-food-delivery-service-bf44093388e2
- What is fan-in, fan-out