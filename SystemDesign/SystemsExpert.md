# client-server architecture
- use dig domainame  to get ip for it.
- 16000 ports for each machine.
- ```nc -l port``` listens messages in a specific port, and ```nc ip port``` sends message to that address

# latency
 - 1 mb 250 microsec (RAM)
 - 1 mb 1000 microsec (SSD)
 - 1 mb 10000 microsec (GBit Network)
 - 1 mb 20000 microsec (HDD)
 - 1 mb 150000 microsec (California to Netherlands to California)

# Throughput
- it is the number of bits going in and out of your services.
- Not necessarily correlated to latency.
- You can increase throuput by increasing latency or by increasing the number of servers.

# Availability
- 99% -> 2 Nines
- 99.9% ->3 Nines of availability
- 99.99% -> 4 Nines of availability

- SLA -> Service Level Aggrement -> An explicit guarantee of availability between cloud provider and end user of these services. Pay back customers if they don't make up their end of aggrement.
- SLO -> Service Level Objective

