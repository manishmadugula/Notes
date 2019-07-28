# Revise
* ### System call

* ### Process

* ### Address Space 
    > OS abstraction used to encapsulate all of the process state is called a address space.The address space is called virtual address cause they don't have to correspond to actual location in the physical memory instead the memory management hardware and os components(page tables) responsible for memory management like page tables maintain a mapping between virtual and physical address.
 
* ### heap
    > dynamically created during execution. Doesn't have to be contagious

* ### stack 
    > grows and shrinks LIFO queue (think recursion)

* ### process control block program counter
* ### stack pointer
* ### cpu registers

* ### context switch

* ### cold cache

* ### process creation tree fork then exec

* ### init and zygote

* ### preempt, scheduling, dispatch

* ### IPC shared buffers message passing ipc,shared memory IPC which is better?

* ### threads and concurrency

* ### process vs threads (see diagram)

* ### exec context and (code,data, files) together form PCB

* ### multithreaded implementation is better than multiprocess implementation 
    > because in the later the process has to be given a different address space for each process where as in multithreaded address space is shared thus memory efficient and low disk swapping also interprocess communication is more demanding than inter thread communication via shared variables.

* ### time to context switch in threads is less compared to process as there is no need to map virtual address to physical address since threads share address space.

* ### It makes sense to do context switch in case of cpu idle state (incase of io  operations ) if (time_idle) > 2* time to context switch.

* ### In single core cpu too multithreading is useful since the time it takes to context switch is less compared to that of process and while one thread is waiting for some io operation, other thread can perform some useful operation.

* ### even kernel process can have multiple threads.

* ### mutual exclusion

* ###  mutex

* ###  condition variables 

* ###  synchronization mechanisms

* ### thread datastructure
* ###  fork
* ###  join

* ### mutex datastructure

* ### critical section
* ###  lock unlock interface
* ###  pending muxes threads

* ### condition variable
* ### datastructure
* ###  signal
* ###  wait
* ###  broadcast

* ### reader writer problem

* ### enter critical section blocks, exit critical section blocks.

* ### spurious wake ups

* ### dead lock, solutions

* ### user level, kernel level threads

* ### multithreaded models.

* ### multithreaded patterns

* ### boss worker

* ### pipeline

* ### layered

* ### PThreads

* ### POSIX Threads

* ### Detachable

* ### PThread_attributes

* ### race condition

* ### hard process state and light process state

* ### single PCB vs multiple PCB

* ### user level thread datastructures and red zone








