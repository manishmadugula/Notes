## System design Framework
### 1. Asking Questions and clarifying ( 3 - 10 minutes)
- Ask all the right questions to understand the requirements.
    - What are the features you are looking for?
    - Is it a mobile app or web app or both?
    - How many daily active users (DAU) will we be supporting.
    - How does the company anticipate to scale up in 3 months, 6 months, 1 year.
    - What is the scale of the system? Is it built for a startup or a big company with a large user base?
    - Will the system work in a distributed environment?
    - Read write ratio of the application.


- Write down requirements
    - Write about latency and throughput.
    - High fault tolerant.

#### News feed example
- How is the news feed ordered? Chronologically or by priority.
- How many friends can the user have?
- Can the feed contain images, videos, text etc?


### 2. Back of the envelope Calculation (5 minutes)
- Communicate with your interviewer if back-of-the-envelope is
necessary before diving into design.
- If yes
    - QPS
    - peak QPS
    - storage
    - Cache

#### Twitter
- 300 million monthly active users.
- 50% of users use Twitter daily.
- Users post 2 tweets per day on average.
- 10% of tweets contain media.
- Data is stored for 5 years.
- QPS = (300 million/2)*2 /24/365 ~ 3500
- Average Tweet size = text : 140 bytes, media 1 MB
- Media storage per day = 150 million * 2 *.1* 1MB ~ 30TB
- Storage for 5 years ~ 30 TB*365*5 ~ 55PB


### 3. Start of with blueprint (10 - 15 minutes)
- Draw box diagrams for clients (mobile/web), APIs, web servers, data stores, cache, CDN, message queue, DNS etc.
- Go through the concrete use-cases and update the blueprint and ask for feedback.
- Go through Security review too authentication, authorization.
- Ask the Interviewer if we should include APIs and DB Schema or is it too low-level.
- Single point of failures identification.
- Design the most critical components first.


### 4. Deep dive (10 - 25 minutes)
- After agreeing on goals and scope.
- After sketching the highlevel design.
- After Feedback from the interviewer on the high-level design.
- Discuss where to deep dive into.
- Suggest multiple approaches if possible.
- There is neither the right answer nor the best answer. A solution designed to solve the problems of a young startup is different from that of an established company with millions of users. Make sure you understand the requirements.
- Never give up.


#### Some things to keep in mind
- Security (Authentication, Authorization)
- Rate limiting
- Caching
- CDN
- Message Queues
- Logging, metrics, deployment CICD pipeline.

#### URL Shortner
- Hash function to convert a long url to short one, concurrency, locking etc to avoid duplicacy.
#### Chat System
- Reduce latency.
- Support online and offline statuses. (Use last-seen time).


### 5. Wrap up ( 3 - 5 minutes)
- Talk about server failure, network loss, bottlenecks.
- How to handle the next scale curve from 1 mil to 10 million users example.




