# Rate Limiter

## Requirements
- Accurately limit excessive requests.
- ### Low latency. The rate limiter should not slow down HTTP response time.
- Use as little memory as possible.
- ### Distributed rate limiting. The rate limiter can be shared across multiple servers or processes.
- ### Exception handling. Show clear exceptions to users when their requests are throttled.
- High fault tolerance. If there are any problems with the rate limiter (for example, a cache server goes offline), it does not affect the entire system.

## High Level Design