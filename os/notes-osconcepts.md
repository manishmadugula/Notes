# Chapter - 1
## Interrupts
- Hardware may trigger an interrupt at any time by sending a signal to the CPU, usually by way of the system bus.
- When the CPU is interrupted, it stops what it is doing and immediately transfers execution to a fixed location. The fixed location usually contains the starting address where the service routine for the interrupt is located.
- Generally, the table of pointers is stored in low memory (the first hundred or so locations). These locations hold the addresses of the interrupt service routines for the various devices.
- Interrupt handlers run asynchronously, and must respond to time-critical inputs quickly. Therefore, interrupt handler is divided into top half and bottom half. First half was executed by the kernel immediately after a hardware interrupt, whereas bottom half are the tasks that can be deferred to execute later

## CPU Protection Rings
- Typically in x86 architecture, there are 4 rings of protection. Ring 0 (kernel mode), Ring 1 (may be used by virtual machine hypervisors or drivers), Ring 2 (may be used by drivers, I am not so sure about that though). Ring 3 is what typical applications run under. It is the least privileged ring, and applications running on it have access to a subset of the processor's instructions. Ring 0 (kernel space) is the most privileged ring, and has access to all of the machine's instructions. For example to this, a "plain" application (like a browser) can not use x86 assembly instructions lgdt to load the global descriptor table or hlt to halt a processor.
- The multiple mode of operation provides us with the means for protecting the operating system from errant users—and errant users from one another.

## Data Structures used in OS
### Lists, Stacks, and Queues
- Queues are also quite common in operating systems—jobs
that are sent to a printer are typically printed in the order in which they were submitted. Tasks that are waiting to be run on an available CPU are often organized in queues.
- Linux uses a balanced binary search tree (known as a red-black tree) as part its CPU-scheduling algorithm.
- A medium-sized disk drive might be divided into several thousand individual units, called disk blocks. A bitmap can be used to indicate the availability of each disk block.


# Chapter - 2


## High memory vs Low Memory
- On a 32-bit architecture, the address space range for addressing RAM is  (4 GB):
- The linux kernel splits that up 3/1 into user space (high memory) and kernel space (low memory) respectively.
- User processes are generally untrusted and therefore are forbidden to access the kernel space. Further, they are considered non-urgent, as a general rule, the kernel tries to defer the allocation of memory to those processes.
- Processes spawned in kernel space are trusted, urgent and assumed error-free, the memory request gets processed instantaneously.
- Every kernel process can also access the user space range if it wishes to. And to achieve this, the kernel maps an address from the user space to its kernel space.
- However, many operating systems (including Linux and Windows) place the operating system in high memory

## Linkers and Loaders
- Have a look at this section
### Symbol Resolution
Symbol resolution, the process of searching files and libraries to replace symbolic references or names of libraries with actual usable addresses in memory before running a program

## Relocation
- Relocation is the process of assigning load addresses for position-dependent code and data of a program and adjusting the code and data to reflect the assigned addresses.
- Relocation is typically done by the linker at link time, but it can also be done at load time by a relocating loader, or at run time by the running program itself. 
## Base and Limit Register
- used so that each process has a separate memory space.
- For every memory access
  - Base address is added to the address
  - Result is compared to the limit register.
## Object Files
### Relocatable object file
- They are “relocatable” because the functions and variables are not bound to any specific address. Instead, the addresses are still symbols.
- This file contains binary code and data that can be combined with other relocatable object files at compile time to create an executable object file.
- math.o is a relocatable file.
- Relocatable object files are linked together during compile time. 

### Executable Object Files
- an executable object file is simply a relocatable object file with the addresses assigned so that it can be placed into memory for execution.

### Shared Object Files
- shared object files are linked into programs during runtime. This is also known as dynamic linking.

## How to run applications on multiple os
- Use interpreter like Ruby or Python (slower than native)
- Use a VM based language, like Java (slower than native)
- Application programmer has to build binaries manually and test for all os. (lot of work for programmer).

## Application Binary Interface
- Each hardware architecture(ARM/x86) specifies certain standards at hardware level, including address width, methods of passing parameters to system calls etc.

## Kernel
- The kernel provides the file system, CPU scheduling, memory management, and other operating system functions through system calls.
- Applications typically use the glibc standard C library when communicating with the system call interface to the kernel.

## Types of kernel design
### Monolithic
### Layered 
  - (Only a higher layer can call lower layer).
  -  (Bad performance)
  -  Each layer has it's own defined and protected interface for debugging.
### Microkernel based.
  - Stripped off monolithic kernel 
  - certain components are moved from kernel space to user space. 
  - Bad performance.
### LKM Modules (LOADABLE KERNEL MODULES)
  - LKMs allow a dynamic and modular kernel, while maintaining the performance benefits of a monolithic system.
  - Here, the kernel has a set of core components and can link in additional services via modules, either at boot time or during run time.
  - Resembles layered since, each module has it's own protected interface but unliked layered any module can call any other module.
  - Also is similar to microkernels, in that the primary module has only core functions, but unlike microkernels, more efficient since the modules don't need to invoke message passing in order to communicate.
  - Linux uses loadable kernel modules, primarily for supporting device drivers and file systems.If the Linux kernel does not have the necessary driver, it can be dynamically loaded.

### Hybrid
  - Linux is monolithic, because having the operating system in a single address space provides very efficient performance. However, it also modular, so that new functionality can be dynamically added to the kernel.

## System boot
- The process of starting a computer by loading the kernel is
known as booting the system. 
###  Steps
- Power ON
- BIOS/UEFI
- MBR (First sector of Hard Disk) (Not in UEFI)
- A small piece of code known as the bootstrap program or boot loader(GRUB) locates the kernel.
- The kernel is loaded into memory and started.
- Intial RAM Disk - initramfs is loaded.
  - The kernel initializes hardware.
  - The root file system is mounted.
- /sbin/init or systemmd is spawned.
- Command shell using getty (Get tty)
- Bash opens up/ GUI (X Windows Server)

### Types of boot process
#### BIOS : Multistage boot process (BIOS based boot process) BIOS : Basic Input/Output system
- the Basic Input/Output System (BIOS) initializes the hardware, including the screen and keyboard, and tests the main memory. This process is also called POST (Power On Self Test).
- The BIOS software is stored on a ROM chip on the motherboard. After this, the remainder of the boot process is completely controlled by the operating system.
- Typically located in ROM/EPROM known as firmware.
- BIOS is not a bootloader, bootloader is a software, BIOS is firmware.

#### UEFI (Unified Extensible Firmware Interface)
- UEFI is a single, complete boot manager and therefore is faster than the multistage BIOS boot process.
- Better multiprocessor support.

### Bootloader

#### First Stage boot loader
- The first stage of PC boot loaders (FSBL, first-stage boot loader) located on fixed disks and removable drives must fit into the first 446 bytes of the Master Boot Record.
- Installed to MBR/master boot block/record or  first sector of the hard disk.
- It just initializes the second stage boot process
- Examples of first-stage bootloaders include coreboot, Libreboot and Das U-Boot.

#### Second Stage Boot loader 
- Example GRUB, Windows's BOOTMGR
- The second stage boot loader resides under /boot.
- Most Linux boot loaders can present a user interface for choosing alternative options for booting Linux,
- Loads file containing the kernel program. 
- run diagnostics to determine state of machine.
- provide booting into recovery mode or single-user mode for diagnosing hardware issues, fixing corrupt file systems, and even reinstalling the operating system.

#### GRUB (second stage boot loader)
- Open source bootstrap program.
- GRUB is flexible and allows changes to be made at boot time, including modifying kernel parameters and even selecting among different kernels that can be booted.


### Boot Loader working.
- Kernels are almost always compressed, so it's first job is to uncompress itself. 
-  During the boot process, the boot loader typically creates a temporary RAM file system, known as **initramfs**.
- This file system contains necessary drivers and kernel modules that must be installed to support the real root file system (which is not in main memory).
- Once the kernel has started and the necessary drivers are installed, the kernel switches the root file system from the temporary RAM location to the appropriate root file system location. 
-  Linux creates the systemd process, the initial process in the system, and then starts other services (for example, a web server and/or database). Most other processes on the system trace their origin ultimately to systemd; the exceptions are kernel processes, started by the kernel directly for managing internal operating system details.
-  Finally user is presented with login screen.


## Core dump
- a capture of the memory of the process—and store it in a file for later analysis, at event of failure.

## Proc in linux
- /proc is a “pseudo” file system that exists only in kernel memory and is used primarily for querying various per-process as well as kernel statistics. 
- the directory entry /proc/2155 would contain per-process statistics for the process with an ID of 2155.


# Chapter - 3

## Program vs Process
- A program becomes a process when an executable file
is loaded into memory

## The process memory layout
![](res/memory_layout.jpg)

Although the stack and heap sections grow toward
one another, the operating system must ensure they do not overlap one another.

### Text section
- the executable code
- Fixed Size.

### Data section
- global variables
- Fixed Size

### Heap section
  - memory that is dynamically allocated during program run time.
### Stack section
  - temporary data storage when invoking functions (such as function parameters, return addresses, and local variables).
#### Activation Record
  - Each time a function is called, an activation record containing function parameters, local variables, and the return address is pushed onto the stack. when control is returned from the function, the activation record is popped from the stack.

## Build Process for various languages
- Machine code is binary (1's and 0's) code that can be executed directly by the CPU. If you were to open a machine code file in a text editor you would see garbage, including unprintable characters (no, not those unprintable characters ;) ). Machine code is pure hexadecimal code: ```5F 3A E3 F1```
- Object code is a portion of machine code not yet linked into a complete program. It's the machine code for one particular library or module that will make up the completed product. It may also contain placeholders or offsets not found in the machine code of a completed program. The linker will use these placeholders and offsets to connect everything together.
- Assembly code is plain-text and (somewhat) human read-able source code that mostly has a direct 1:1 analog with machine instructions. This is accomplished using mnemonics for the actual instructions, registers, or other resources. Examples include JMP and MULT for the CPU's jump and multiplication instructions. Unlike machine code, the CPU does not understand assembly code. You convert assembly code to machine code with the use of an assembler or a compiler, though we usually think of compilers in association with high-level programming language that are abstracted further from the CPU instructions. Assembly code : ```mov eax, 77```

### Compiled Languages
- Building a complete program involves writing source code for the program in either assembly or a higher level language like C++. The source code is assembled (for assembly code) or compiled (for higher level languages) to object code, and individual modules are linked together to become the machine code for the final program. In most cases, a complicated make script or solution file may be used to tell the environment how to build the final application.

### Interpreted Languages
- Interpreted languages rely on the machine code of a special interpreter program. At the basic level, an interpreter parses the source code and immediately converts the commands to new machine code and executes them. Modern interpreters are now much more complicated: evaluating whole sections of source code at a time, caching and optimizing where possible, and handling complex memory management tasks.

### Virtual machine
- In this situation, a program is first pre-compiled to a lower-level intermediate language or byte code. The byte code is then loaded by the virtual machine, which interprets/compiles(compilation is a optimization ste p for repeated parts of code) it to native code. The advantage here is the virtual machine can take advantage of optimizations available at the time the program runs. A compiler belongs to the developer, and therefore must produce relatively generic (less-optimized) machine code that could run in many places. The runtime environment or virtual machine, however, is located on the end user's computer, and therefore can take advantage of all the features provided in that environment.

## Memory Layout for c program
![](res/c_memory_layout.jpg)

- GNU ```size``` command can be used to determine the size in bytes of the above section.
- The global data section is divided into different sections for (a) initialized data and (b) uninitialized data.
- A separate section is provided for the argc and argv parameters passed to the main() function.

## Build Process for c program
![](res/c_build_process.jpg)

## Process state
It is important to realize that only one process can be running on any processor core at any instant.

![](res/process_state.jpg)

## Process control block Components
- You can get some of this data from ```cat /proc/process_id/status```
- PCB must be kept in an area of memory protected from normal process access. In some operating systems the PCB is placed at the beginning of the kernel stack of the process.
- On systems that support threads, the PCB is expanded to include information for each thread.
- The process control block in the Linux operating system is represented by the C structure task struct, which is found in the <include/linux/sched.h>

### Process State
### Program Counter
### CPU registers
- They include accumulators, index registers, stack pointers, and general-purpose registers, plus any condition-code information. Along with the program counter, this state information must be saved when an interrupt occurs, to allow the process to be continued correctly afterward when it is rescheduled to run. The CPU uses these values to fill it's own register on each context switch.

### Memory-management information.
-  may include such items as the value of the base and limit registers and the page tables, or the segment tables

### I/O status information.
-  This information includes the list of I/O devices allocated to the process, a list of open files, and so on.

### CPU-scheduling information. 
- This information includes a process priority, pointers to scheduling queues, and any other scheduling parameters.

### Memory management information
This information may include such items as the value of the base and limit registers and the page tables, or the segment tables, depending on the memory system used by the operating
system.

### Accounting information.
This information includes the amount of CPU and real time used, time limits, account numbers, job or process numbers.

### I/O status information.
This information includes the list of I/O devices allocated to the process, a list of open files, and so on.


## Scheduling Queues
- As processes enter the system, they are put into a ready queue, where they are ready and waiting to execute on a CPU’s core This queue is generally stored as a linked list; a ready-queue header contains pointers to the first PCB in the list, and each PCB includes a pointer field that points to the next PCB in the ready queue.
![](res/queue_scheduling.jpg)

- Context-switch times are highly dependent on hardware support. For instance, some processors provide multiple sets of registers.

## Process Creation.

-  A child process may be able to obtain its resources directly from
the operating system, or it may be constrained to a subset of the resources
of the parent process, like open files, pipes etc.

- Restricting a child process to a subset of
the parent’s resources prevents any process from overloading the system by
creating too many child processes.

- When a process terminates, its resources are deallocated by the operating system. However, its entry in the process table must remain there until the parent calls wait(), because the process table contains the process’s exit status.

- A process that has terminated, but whose parent has not yet called wait(), is known as a zombie process.

- Now consider what would happen if a parent did not invoke wait() and instead terminated, thereby leaving its child processes as orphans. Traditional UNIX systems addressed this scenario by assigning the init process as the new parent to orphan processes. The init process periodically invokes wait(), thereby allowing the exit status of any orphaned process to be collected and releasing the orphan’s process identifier and process-table entry.

### Fork and Exec
- Fork is an operation whereby a process creates a copy of itself.
- When a process calls fork, it is deemed the parent process and the newly created process is its child. After the fork, both processes not only run the same program, but they resume execution as though both had called the system call. They can then inspect the call's return value to determine their status, child or parent, and act accordingly. (return value is pid of child process for parent and zero for child).
- A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process.
- The fork operation creates a separate address space for the child. The child process has an exact copy of all the memory segments of the parent process. In modern UNIX variants that follow the virtual memory model from SunOS-4.0, copy-on-write semantics are implemented and the physical memory need not be actually copied. Instead, virtual memory pages in both processes may refer to the same pages of physical memory until one of them writes to such a page: then it is copied. This optimization is important in the common case where fork is used in conjunction with exec to execute a new program: typically, the child process performs only a small set of actions before it ceases execution of its program in favour of the program to be started, and it requires very few, if any, of its parent's data structures.
- Then, the copy, called the "child process", calls the exec system call to overlay itself with the other program: it ceases execution of its former program in favor of the other.
- Some UNIX systems have chosen to have two versions of fork(), one that duplicates all threads and another that duplicates only the thread that invoked the fork() system call.
- Which of the two versions of fork() to use depends on the application.
If exec() is called immediately after forking, then duplicating all threads is unnecessary, as the program specified in the parameters to exec() will replace the process. In this instance, duplicating only the calling thread is appropriate. If, however, the separate process does not call exec() after forking, the separate process should duplicate all threads.
## IPC
- There are two fundamental models of interprocess communication: shared memory and message passing.
- Chrome's multiprocess architecture, . If one website crashes, only its renderer process is affected; all other processes remain unharmed.
- Message passing is useful for exchanging smaller amounts of data, because no conflicts need be avoided. Message passing is also easier to implement in a distributed system than shared memory.
- Shared memory can be faster than message passing, since message-passing systems are typically implemented using system
calls and thus require the more time-consuming task of kernel intervention. In shared-memory systems, system calls are required only to establish sharedmemory regions. Once shared memory is established, all accesses are treated as routine memory accesses, and no assistance from the kernel is required.

### Shared Memory
- Interprocess communication using shared memory requires communicating processes to establish a region of shared memory. Typically, a shared-memory region resides in the address space of the process creating the shared-memory
segment.
-  Other processes that wish to communicate using this shared-memory segment must attach it to their address space.
-  They can then exchange information by reading and writing
data in the shared areas. The form of the data and the location are determined by these processes and are not under the operating system’s control. I.e They are responsible for data synchronization.

#### Memory mapped files
- POSIX shared memory is organized using memory-mapped files, which associate the region of shared memory with a file.
-  the mmap() function establishes a memory-mapped file containing
the shared-memory object. It also returns a pointer to the memory-mapped file
that is used for accessing the shared-memory object.

### Message Passing
- A message-passing facility provides at least two operations:
  - send(message)
  - receive(message)
  
- If processes P and Q want to communicate, they must send messages to and receive messages from each other: a communication link must exist between them.
#### Buffering in message systems
Whether communication is direct or indirect, messages exchanged by communicating processes reside in a temporary queue. Basically, such queues can be
implemented in three ways:
- Zero capacity. The queue has a maximum length of zero; thus, the link
cannot have any messages waiting in it. In this case, the sender must block
until the recipient receives the message.
- Bounded capacity. The queue has finite length n; thus, at most n messages
can reside in it. If the queue is not full when a new message is sent, else sender waits.
- Unbounded capacity. The queue’s length is potentially infinite.

### Windows IPC
- The message-passing facility in Windows is called the advanced local procedure call (ALPC) facility. It is used for communication between two processes
on the same machine.
- Windows uses a port object to establish and maintain a connection between two
processes. Windows uses two types of ports: connection ports and communication ports.
- When a client wants services from a subsystem, it opens a handle to the
server’s connection-port object and sends a connection request to that port.
The server then creates a channel and returns a handle to the client.
- The channel consists of a pair of private communication ports: one for client–server
messages, the other for server–client messages.
- Larger messages must be passed through a section object, which is a
region of shared memory associated with the channel.
- It is important to note that the ALPC facility in Windows is not part of the
Windows API and hence is not visible to the application programmer. Rather,
applications using the Windows API invoke standard remote procedure calls.
When the RPC is being invoked on a process on the same system, the RPC is
handled indirectly through an ALPC procedure call. Additionally, many kernel
services use ALPC to communicate with client processes.
![](res/lpc_windows.jpg)

### Pipes

- Example : ```ls | less``` 

#### Ordinary Pipes
- They are unidirectional and
employ parent–child relationships between the communicating processes.
- If two-way communication is required, two pipes must be used, with each pipe sending data in a different direction. 
-  Typically, a parent process creates a pipe and uses it to communicate with
a child process that it creates via fork().
-  a child process inherits open files from its parent. Since a pipe is a special type of file, the child inherits the pipe from its parent process.

- On UNIX systems, ordinary pipes are constructed using the function
```pipe(int fd[])``` This function creates a pipe that is accessed through the int fd[] file descriptors: fd[0] is the read end of the pipe, and fd[1] is the write end. UNIX treats a pipe as a special type of file. 
- Thus, pipes can be accessed using ordinary read() and write() system calls.
- once the processes have finished communicating and have terminated, the ordinary
pipe ceases to exist.

#### Named Pipes
- Named pipes provide a much more powerful communication tool.
- Communication can be bidirectional, and no parent–child relationship is required.
- Once a named pipe is established, several processes can use it for communication. In fact, in a typical scenario, a named pipe has several writers.
- Named pipes are referred to as FIFOs in UNIX systems.


## RPC
- RPC is the service and protocol offered by the operating system to allow code to be triggered for running by a remote application. It has a defined protocol by which procedures or objects can be accessed by another device over a network. An implementation of RPC can be done over basically any network transport (e.g. TCP, UDP).

- Similar to IPC, but because we are dealing with an environment in which the processes are executing on separate systems, we must use a message-based communication scheme to provide remote service. We can't use shared memory communication.
- In contrast to IPC messages, the messages exchanged in RPC communication are well structured and are thus no longer just packets of data.
-  Each message is addressed to an RPC daemon listening to a port on the remote system, and each contains an identifier specifying the function to execute and the parameters to pass to that function. 
- Parameter marshaling addresses the issue concerning differences in data representation(big endian/little) on the client and server machines. . To resolve differences like this, many RPC systems define a machine-independent representation of data. One such representation is known as **external data representation (XDR)**.
- Request handling should be Atmost once i.e, Idempotent.
- The client can know the port to communicate beforehand or can ask a rendezvous (also called a **matchmaker**) daemon on a fixed RPC port.
![](res/rpc.jpg)

## Socket
- The socket is just a programming abstraction such that the application can send and receive data with another device through a particular network transport. You implement protocols (such as RPC) on top of a transport (such as TCP) with a socket.
- sockets packetize communication using IPv4 or IPv6

### Sockets vs Pipes
- pipes only exist within a specific host, and they refer to buffering between virtual files, or connecting the output / input of processes within that host. There are no concepts of packets within pipes.
- sockets packetize communication using IPv4 or IPv6; that communication can extend beyond localhost. Note that different endpoints of a socket can share the same IP address; however, they must listen on different TCP / UDP ports to do so.


# Chapter 4

- It comprises a thread ID, a program counter (PC), a register set, and a stack.
-  It shares with other threads belonging to the same process its code section, data section, and other operating-system resources, such as open files and signals. Also heap area.
- Context switching a process is slower than context switching a thread belong to same process. Thus threads are called Light Weight Processes.

## Advantages
- Responsive UI
- Resource sharing is easy, don't have to use IPC.
- Thread creation is easier than process creation.
- Greatly helps in case of multiprocessor architecture.

## Concurrency vs Parallelism
- A concurrent system supports more than one task by allowing all the tasks to make progress. By using time multiplexing. This doesn't need multicore architecture.

-  a parallel system can perform more than one task
simultaneously. In a multicore architecture. 

## Amdahl's Law
- Amdahl’s Law is a formula that identifies potential performance gains from adding additional computing cores to an application that has both serial (nonparallel) and parallel components. 
- If S is the portion of the application
that must be performed serially on a system with N processing cores, the formula appears as follows :

![](res/amdahl_1.jpg)
![](res/amdahl_2.jpg)

- One interesting fact about Amdahl’s Law is that as N approaches infinity, the speedup converges to 1/S. You can never go beyond 1/S, no matter the number of cores you add.

## Multithreading Modes
- Support for threads may be provided either at the user level, for user threads, or by the kernel, for kernel threads.
- User threads are supported above the kernel and are managed without kernel support, whereas kernel threads are supported and managed directly by the operating system.
- It is kernel threads that the operating system schedules to run on physical processors.
- Ifk Kernel Thread Blocks(Waiting for an IO Operation) the underlying user thread also blocks.
- See The below section for Scheduler Activations for internal workings.
-  A relationship must exist between user threads and kernel
threads.

### Many-to-One Model
- The many-to-one model maps many user-level threads to one kernel thread.
- The entire process will block if a thread makes a blocking system call. Since only 1 kernel thread is given to a process and that thread is busy in making the system call.
- multiple threads are unable to run in parallel on multicore systems.
- No one uses this nowadays.

### One to One Model
- maps each user thread to a kernel thread.
- It provides more concurrency than the many-to-one model by allowing another thread to run when a thread makes a blocking system call.
- Creating a user thread requires creating the corresponding kernel thread, and a large number of kernel threads may burden the performance of a system.
- Linux, along with the family of Windows operating systems, implement the one-to-one model.

### Many to Many Model
-  Multiplexes many user-level threads to a smaller or equal number of kernel threads.
-  The number of kernel threads may be specific to either a particular application or a particular machine (an application may be allocated more kernel threads on a system with eight
processing cores than a system with four cores).
-  Developers can create as many user threads as necessary, and
the corresponding kernel threads can run in parallel on a multiprocessor. Also, when a thread performs a blocking system call, the kernel can schedule another thread for execution.
- In practice it is difficult to implement.

### Two Level Model
-  still multiplexes many userlevel threads to a smaller or equal number of kernel threads but also allows a user-level thread to be bound to a kernel thread.
![](res/two_level_model.jpg)


## Threading Libraries
- Pthreads, may be provided as either a user-level or a kernel-level library.
- The Windows thread library is a kernel-level library available on Windows systems. Invoking a function in the API for the library typically results in a system call to the kernel.
- Java thread API is generally implemented using a thread library available on the host system. This means that on Windows systems, Java threads are typically implemented using the Windows API; UNIX, Linux, and macOS systems typically use Pthreads.

### Two Types of Thread Creation
- Asynchronous : Once the parent creates a child thread, the parent resumes its execution, example UI app. 
- Synchronous :  Only after all of the children have joined can the parent resume execution, example  the
parent thread may combine the results calculated by its various children.

## Implicit Threading
- These strategies generally require application developers to
identify tasks—not threads— that can run in parallel.
- A task is usually written as a function, which the run-time library then maps to a separate thread.
-  developers only need to identify parallel tasks, and the
libraries determine the specific details of thread creation and management.

### Thread Pool
- The general idea behind a thread pool is to create a number of threads at
start-up and place them into a pool, where they sit and wait for work.
-  If the pool contains no available thread, the task is queued until
one becomes free. 
- Once a thread completes its service, it returns to the pool
and awaits more work.
-  Thread pools work well when the tasks submitted to
the pool can be executed asynchronously.

#### Advantages
- Servicing a request with an existing thread is often faster than waiting to
create a thread.
- Limits threads to a certain limit.
- Allows for task to be executed after time delay or execute periodically, since we separated the logic of creation and exectution.

### Fork Join
- look at fork join in java.

## Threading Design Consideration

### Fork and Exec
- Whether fork copies all threads or not, depends on the application.
If exec() is called immediately after forking, then duplicating all threads is unnecessary. e. If, however, the separate process does not call exec() after forking, the separate process should duplicate all threads.

### Signals
- A signal is used in UNIX systems to notify a process that a particular event has occurred.
- A signal may be received either synchronously or asynchronously.
- Examples of synchronous signals include illegal memory access and division by 0.  Synchronous signals are delivered to the same process that performed
the operation that caused the signal.
- When a signal is generated by an event external to a running process, that
process receives the signal asynchronously. Examples of such signals include
terminating a process with specific keystrokes (such as <control><C>), completion of an IO event.
- Once delivered, the signal must be handled.
  - A default signal handler
  - A user-defined signal handler
- Delivering signals is more complicated in multithreaded programs
  - synchronous signals need to be delivered to the thread causing
the signal and not to other threads in the process.
  - some async signals like terminate, should be sent to all threads.

#### APC (Asynchronous Procedure Calls)
- The APC facility enables a user thread to specify a function that is to be called when the user thread receives notification of a particular event.

### Thread Cancellation
- Two Types of cancellation
#### Async Cancellation
-  One thread immediately terminates the target thread. No chance to clean itself.
- canceling a thread asynchronously may not free a necessary system-wide resource.
#### Deferred Cancellation
- The target thread periodically checks whether it
      should terminate, allowing it an opportunity to terminate itself in an
      orderly fashion.
- cancellation occurs only after the target thread has checked a flag to determine whether or not it should be canceled. When a thread reaches a **cancellation point**.

### Thread Local 
- See Java Multithreading notes

### Scheduler Activations
- #### Only valid for many to many or many to one model.
- There is an intermediate datastructure known as LWP (Light Weight Process) between user thread and kernel thread.
- For User thread library, LWP appears to be a virtual processor on which the application can schedule a user thread to run.
- Each LWP is attached to a kernel thread, and it is kernel threads that the operating system schedules to run on physical processors.
- There is a one-to-one correspondence between LWPs and kernel threads.
- If a kernel thread blocks (such as while waiting for an I/O operation to complete), the LWP blocks as well, as a result the user thread blocks.
  
#### Number of LWPs
- For CPU Bound Application, LWP == No of processors
- IO Bound Application, can require multiple LWP to process. Typically, an LWP is required for each concurrent blocking system call. For example, that five different file-read requests occur simultaneously. Five LWPs are needed, because all could be waiting for I/O completion in the kernel. If a process has only four LWPs, then the fifth request must wait for one of the LWPs to return from the kernel.
#### Working of LWPs
- One scheme of communication between user level thread and kernel thread is scheduler activation : 
- The kernel provides an application with a set of virtual processors (LWPs), and the application can schedule user threads onto an available virtual processor.
- Furthermore, the kernel must inform an application about certain events. This is known as **upcall**. Upcalls are handled by the thread library with an upcall handler, and upcall handlers must run on a virtual processor.
- When a User thread is about to block, the kernel makes an upcall to the application thread library, and the thread library, saves the state of the current blocked thread, and schedules another thread to run on LWP.
- Once the blocking event is fulfilled, the kernel makes another upcall, (which is handled on another LWP) which may allocate a new LWP or may prempt an exisiting user thread. 

### Upcall
- An upcall is a mechanism that allows the kernel to execute a function. in userspace.
- Opposite of system call.

## Threads in Windows
### Components of thread
- A thread ID uniquely identifying the thread
- A register set representing the status of the processor
- A program counter
- A user stack, employed when the thread is running in user mode, and a kernel stack, employed when the thread is running in kernel mode.
- A private storage area used by various run-time libraries and dynamic link libraries.
- The register set, stacks, and private storage area are known as the context of the thread.

![](res/thread_windows.jpg)
- The ETHREAD and the KTHREAD exist entirely in kernel space; this means
that only the kernel can access them. 

## Linux Threads
- ### Linux does not distinguish between processes and threads. Linux uses the term task rather than process or thread when referring to a flow of control within a program.
- Just like fork is used to create a process in Linux, Linux also provides **clone()** to create a thread.
- When clone() is invoked, it is passed a set of flags that determine how much sharing is to take place between the parent and child tasks.
- Based on flags passed to clone, the task can behave as a process/ a thread.
![](res/linux_clone.jpg)
- For example, suppose that clone() is passed the flags CLONE FS, CLONE VM, CLONE SIGHAND, and CLONE FILES. This is equivalent to creating a thread. If none are passed, it is equivalent to calling a fork.
- ### task_struct
  - The varying level of sharing is possible because of the way a task is represented in the Linux kernel.  A unique kernel data structure (specifically, struct task struct) exists for each task in the system.
  - This data structure, instead of storing data for the task, contains pointers to other data structures where these data are stored. For example, data structures that represent the list of open files, signal-handling information, and virtual memory.
  -  The flexibility of the clone() system call can be extended to the concept of **containers** (allows creating multiple Linux systems (containers) under a single Linux kernel).

# Chapter - 5

## CPU Burst
- CPU Bound : few Long CPU Bursts 
- IO Bound : many short CPU Bursts  

## CPU Scheduler
-, a ready queue can be implemented as a FIFO queue, a priority queue, a tree, or simply an unordered linked list. 
- The records in the queues are generally process control blocks (PCBs) of the processes.

## Preemptive vs Non Premptive Schedulers
- CPU Scheduling Decision can take place in 4 circumstances : 
  1. When a process switches from the running state to the waiting state. Example : IO Request.
  2. When a process switches from the running state to the ready state. (Interrupt).
  3. When a process switches from the waiting state to the ready state (Completion of IO Request).
  4. When a process terminates
- Non Premptive : When Scheduling takes place only in case of 1 and 4. Otherwise it is Preemptive.
- Most modern os are completely premptive.

### Challenges in Preemptive
- preemptive scheduling can result in race conditions when
data are shared among several processes.
- #### Preemption also affects the design of the operating-system kernel. During the processing of a system call, the kernel may be busy with an activity on behalf of a process. Say updating a kernel datastructure. When the process is prempted during this change there can be 2 behavior.
  - Kernel can be non-premptive i.e will wait for a system call to complete before doing a context switch. This kernel-execution model is a poor one for supporting real-time computing
  - A preemptive kernel requires mechanisms such as mutex locks to prevent race conditions when accessing shared kernel data structures.
  - Most mordern os have premptive kernels.


## Dispatcher
- The dispatcher is the module that gives control of the CPU’s core to the process selected by the CPU scheduler. 
  - Switching context from one process to another, involves reseting CPU registers program counters etc.
  - Switch from kernel to User mode.
  - Jumping to the proper location in the user program to resume that location.
- The time it takes for the dispatcher to stop one process and start another running is known as the dispatch latency

### Scheduler vs dispatcher
- Procedure of selecting a process among various processes is done by the scheduler.
- Once the scheduler has selected a process from the queue, the dispatcher comes into the picture, and it is the dispatcher who takes that process from the ready queue and moves it into the running state. 

### Useful information for context switches
- vmstat
- cat /proc/{{pid}}/status
  - Can see voluntary context switches to get idea of number of IO performed.

## Scheduling Algorithms

### First Come First Served
- Non premptive
- There is a convoy effect as all the other processes wait for the one big process to get off the CPU.
- This effect results in lower CPU and device utilization than might be possible if the shorter processes were allowed to go first.
-  The FCFS algorithm is thus particularly troublesome for interactive systems.

### Shortest Job First Scheduling (Better name : shortest-next-CPU-burst)
- Should be called : Shortest-next-CPU-burst : Scheduling depends on the length of the next CPU burst of
a process, rather than its total length.
- Gives minimum average waiting time for a given set of processes.
- ### Although the SJF algorithm is optimal, it cannot be implemented at the level of CPU scheduling, as there is no way to know the length of the next CPU burst.
- We can approximate, We expect that the next CPU burst will be similar (exponential average) in length to the previous ones.
- We use the following formulae, where τ(n) is the prediction of nth process and t(n) is the actual time taken by nth process and alpha controls the weight that τ has.
![](res/shortest_job_first_eqn.jpg)
- In above equation P(n) and P(n+1) are grouped as similar process based on maybe size, or type etc.
- It can be premptive and non premptive.
- It may cause starvation if shorter processes keep coming. This problem can be solved using the concept of ageing
- Preemptive SJF scheduling is sometimes called shortest-remainingtime-first scheduling.
#### Shortest Remaining time algorithm
- When a new process is added the algorithm only needs to compare the currently executing process with the new process, ignoring all other processes currently waiting to execute. So little overhead.
-  Short processes are handled very quickly.

### Round Robin Scheduling
- Basically a premptive version of FCFS.
- The performance metrics i.e waiting and turn around time depends heavily on the time quantum after which context switch happens.
- If it is too less more context switch will degrade.
- If too less then it is same as FCFS.

### Priority Scheduling
- Example is SJF
- Priorities can be defined either internally or externally.
  - Internal : time limits, memory requirements, the number of open files, and the ratio of average I/O burst to average CPU burst have been used in computing priorities.
  - External : The importance of the process, the type and amount of funds being paid for computer use.
- A major problem with priority scheduling algorithms is indefinit blocking, or **starvation**.
  - A priority scheduling algorithm can leave some lowpriority processes waiting indefinitely.
  - Solution can be **aging** :  gradually increasing the priority of processes that wait in the system for a long time.
  - Another option is to combine round-robin and priority scheduling in such a way that the system executes the highest-priority process and runs processes with the same priority using round-robin scheduling.

### Multi-Level Scheduling
- Instead of a single queue, it is
often easier to have separate queues for each distinct priority, and priority
scheduling simply schedules the process in the highest-priority queue
- You don't have to search for higher priority task O(n) time.
- each queue might have its own scheduling algorithm. The foreground queue might be scheduled by an RR algorithm, for example, while the background queue is scheduled by an FCFS algorithm.
- A process that arrives for queue 1 will preempt a process in queue 2. A process in queue 1 will in turn be preempted by a process arriving for queue 0.
![](res/multi_level_scheduling.jpg)
- Each queue has absolute priority over lower-priority queues.
  - No process can run unless the above queue is empty.
  - Or there can be time slicing within queues based on prioirty (80 for foreground, 20 for background).
- Multilevel queue aren't flexible, a process can't change it's queue. So aging can't be implemented to prevent starvation.



### Multi-Level Feedback Queue
- The multilevel feedback queue scheduling algorithm, in contrast, allows a process to move between queues. The idea is to separate processes according to the characteristics of their CPU bursts.
  - If a process uses too much CPU time,
it will be moved to a lower-priority queue. 
  - Aging can be implemented to avoid starvation
- the most general CPU-scheduling algorithm
#### Parameters
- The number of queues
- The scheduling algorithm for each queue
- The method used to determine when to upgrade a process to a higherpriority queue
- The method used to determine when to demote a process to a lowerpriority queue.
- The method used to determine which queue a process will enter when that process needs service.


## Thread Scheduling Schemes

### Process Contention Scope (Scheduling User Thread to LWP)
- For many to many and many to one models, the thread library is responsible for scheduling user level threads onto available LWPs, this doesn't mean the threads are actually running in the CPU as it is the operating system's responsibility to schedule the LWP(Kernel threads) to the actual CPU. This scheme is known as Process Contention Scope.
- It is user thread library that is scheduling these thread.
- It is important to note that PCS will typically preempt the thread currently running in favor of a higher-priority thread.
- Priority is set by the developer.
- The thread competes for resources with all other threads in the same process that were also created with the PTHREAD_SCOPE_PROCESS contention scope

### System Contention Scope
- To decide which LWP/Kernel Thread to run onto CPU, The kernel uses System Contention scope.
- It is the kernel scheduling these threads.
- Systems using the one-to-one model, such as Windows and Linux schedule threads using only SCS.
- The thread competes for resources with all other threads in all processes on the system that are in the same scheduling allocation domain. 

![](res/contention_scope.jpg)

### Pthreads Set Scope
- The pthread_attr_setscope(pthread_attr_t *attr, int scope) function sets the contention scope attribute of the thread attributes object referred to by attr to the value specified in scope.


## Multi-Processor Scheduling
2 approaches to multi-processor scheduling

- Asymmetric : System activities like scheduling, io processing etc handled by one and the rest handle user tasks
  - System data structures are not shared by all CPUs.
  - master server becomes the bottleneck.


- Symmetric Multiprocessing (SMP)
  - Followed the most.
  - There can be 2 stategies for organizing threads.
    - Shared Queue
      - Problems like no datalocality and synchronization issues
      - Load Balancer not required.
    - Each processor with separate queue.
      - Most followed.
      - Load Balancing is necessary to avoided skewed distribution.

## Chip Multithreading/ Hyper threading/ Simultaneous Multithreading

- when a processor accesses memory, it spends a significant amount of time waiting for the data to become available. This situation, known as a memory stall. Because the mordern processors operate at much faster speeds than the memory clocks. Memory Stall can also occur due to cache miss.

- To optimize this useless time, most chips have capability of utilizing hardware level threading, if one hardware thread stall then other one can execute.

- The resources of the physical core (such as caches and pipelines) must be shared among its hardware threads, and therefore a
processing core can only execute one hardware thread at a time.

### Two ways to implement hardware threading

#### Coarse Grained
- Only switches when a long latency event occurs, the core switches to another hardware level thread.
- Cost of switching is high since the instruction pipeline has to be flushed and filled with other thread.

#### Fine Grained
- Issues instructions for different threads after every cycle,
- Fine-grained (or interleaved) multithreading switches between threads at a much finer level of granularity— typically at the boundary of an instruction. Cost of switching is small.

### Scheduling in hyperthreaded cores
- There are now 2 levels of scheduling, on that is made by the operating system, other at CPU Level(Can be FIFO, or priority based).
- **It is important to note that for mordern systems os are aware of hyperthreading and therefore can optimize the scheduling by not scheduling the threads on the same hardware core, i.e onto logical processors that do not share resources.**

![](res/hyperthreading_scheduling.jpg)

## Load Balancing
- Push Migration : A separate task pushes task to the idle processor from a busy processor
- Pull Migration : An idle processor, pulls the tasks from a busy processor.
- The balanced load, can be number of threads/ priority of each thread etc.

## Processor Affinity/ Data Locality
- The cache of a processor contains the information most required by the thread executed by a particular core.
- If process migration occurs due to load balancing, the cache information is invalidated and has to be moved to another processor, thus incurring an overhead. 
- Thus most os avoid migrating thread to another processor to take advantage of warm cache, this is processor affinity.
- Also use of shared thread queue eliminates advantages of data locality similarly, with private queue, threads are always assigned to same queue so can benifit from warm cache.
-  Load balancing often counteracts the benefits of processor affinity.

### Two types of processor affinity
- Soft affinity : os will attempt to keep thread in same core, but may migrate during load balancing.
- Hard affinity : allow a processor to be only limited to specific CPUs on which they can run.
- Linux is soft by default, but also allows hard using a system call. 

## NUMA
- Non uniform memory access
- harness large numbers of processors in a single system
- Although CPU in NUMA share common address space, the cost to access memory attached to same CPU is less than to different CPU, there also processor affinity kick in.


## Heterogenous Multiprocessing /big.LITTLE architecture.
- Not same as asymmetric multiprocessing, since user task can run on all processor.
- This is particularly useful in mobile systems where battery has to be conserved.
- Use variety of CPU based on their performance.
- For long running, background type task use a slower power efficienct processor.
- For demand and interactive apps use faster power hungry processor.
- In battery saving mode, disable power hungry processor.

## Real Time CPU Scheduling

### Soft real time
- Soft real-time systems provide no guarantee as to when a critical real-time process will be scheduled. They guarantee only that the process will be given preference over noncritical processes.

### Hard real time
- A task must be serviced by its deadline; service after the deadline has expired is the same as no service at all.

### Event Latency
The amount of time that elapses from when an event occurs to when it is serviced.

#### Interrupt Latency
- Period of time from the arrival of an interrupt at the CPU to the start of the routine that services the interrupt.

#### Dispatch Latency
??


### Priority Based Scheduling

#### Admission Control
- For real time systems, the scheduler does one of two
things. It either admits the process, guaranteeing that the process will complete on time, or rejects the request as impossible if it cannot guarantee that the task will be serviced by its deadline.

### Rate Monotonic Scheduling (IMPORTANT)
- The rate-monotonic scheduling algorithm schedules periodic tasks using a static priority policy with preemption.
- each periodic task is assigned a priority inversely based on its period, i.e to assign a higher priority to tasks that require the CPU more often. 
- priorities are fixed.
- ### Rate-monotonic scheduling is considered optimal in that if a set of processes cannot be scheduled by this algorithm, it cannot be scheduled by any other algorithm that assigns static priorities.
- Rate-monotonic scheduling has a limitation:
CPU utilization is bounded, and it is not always possible to maximize CPU resources fully. The worst-case CPU utilization for scheduling N processes is

![](res/rate_ms_worst_case.jpg)

- For more information, see 2 examples on page 232.

### Earliest DeadLine First (IMPORTANT)
- assigns priorities dynamically according to deadline. 
- when a process becomes runnable, it must announce its deadline requirements to the system.
- Priorities may have to be adjusted to reflect the deadline of the newly runnable process, unlike rate monotonic scheduling, where it was fixed.
- Unlike the rate-monotonic algorithm, EDF scheduling does not require that processes be periodic
- Look at the example where EDF was better than RMS, by utilizing dynamic priorities.
- For 2 process P1 & P2, period1=50, timetaken1=25, period2=80,timetaken=35. Using RMS fails but EDF succeeds. since in RMS priority is always P1>P2, but in EDF, priority changes at one point P2>P1.

### Proportional Share Scheduling (IMPORTANT)
- Used in linux
- Proportional share schedulers operate by allocating T shares among all applications. An application can receive N shares of time, thus ensuring that the
application will have N∕T of the total processor time.
- Proportional share schedulers must work in conjunction with an admission-control policy to guarantee that an application receives its allocated
shares of time.

## Linux Scheduler
- Uses Completely Fair Scheduler and Real Time Scheduler.
- Based on scheduling classes, each class is assigned a priority.
- To decide the next task to run, the scheduler selects the highest-priority task belonging to the highest-priority scheduling class.
- Standard Linux kernels implement
two scheduling classes
  - Default CFS
  - Real Time Scheduling

### CFS Scheduler
- The CFS scheduler assigns a proportion of CPU processing time to each task.
- This proportion is based on the task's nice value.(numerically lower nice value indicates a higher relative priority).
- nice value is between -20 to +19.

#### Load balancing
- Supports Load Balancing
- Load is determined as a combination of priority of thread and average rate of CPU Usage.

#### NUMA Aware
- To minimize thread migration, Linux identifies a hierarchical system of scheduling domains.
- ### A scheduling domain is a set of CPU cores that can be balanced against one another.
- In most multicore processors, There is a heirarchy of cache, L1, L2, L3. 
- The cores in each scheduling
domain are grouped according to how they share these caches.
- ### Cores sharing L2 cache are organized into separate domains and the cores sharing L3 cache are organized into processor level domain (also known as NUMA NODE).
- CFS balances loads within domains, beginning at the lowest level of the hierarchy.
![](res/scheduling_domain.jpg) 

#### Target Latency 
- CFS doesn’t use discrete values of time slices and instead identifies a targeted latency, which is an interval of time during which every runnable task should run at least once.
- Proportions of CPU time are allocated
from the value of targeted latency. Targeted latency can increase if the number of active tasks in the system grows beyond a certain threshold.

#### Virtual Run Time
- Insteading of using a numerical priority, the CFS maintains a vruntime(virtual runtime) per each task. lower vruntime higher priority. 
- The virtual run time is associated with a decay factor based on the priority of a task, the vruntime is a combination of cpu burst and nice value. So IO bound operation have low vruntime thus higher priority.
- For tasks at normal priority (nice values
of 0), virtual run time is identical to actual physical run time. 
- To decide which task to run next, the scheduler simply selects the task that has
the smallest vruntime value.

#### Red Black Trees in CFS
- Balanced binary tree (Red Black Tree) is used to keep track of which task to run next.
- key is based on the value of vruntime.
- A task in ready queue is added to this tree.
- O(logn) to determine which is next job to run.
- Leftmost i.e next job is cached for efficiency purpose.


### Real Time Scheduling
- Any task scheduled using either the SCHED FIFO or the SCHED RR real-time policy runs at a higher priority than normal 

### Global Priority.

- Linux uses 2 different priority values/nice value ranges, one for real time and one for normal task(CFS)
- Global priority values range from 0 to 139, Realtime task are assigned (0 to 99)
- CSF Task/ normal tasks are assigned 100-139. 100 mapping to nice value of -20 and 139 to 19.

## Windows
- Uses a 32 level priority scheme
- 

# Chapter 6 (Synchronization Tools)

## Non Atomic Operation
- Instructions like count++ and count--, may seem like a single operation, but are infact a combination of operation
- count++, (reg=count,reg=reg+1,count=reg)
- In these cases if another thread is also modifying count's values, inconsistent count values can result due to race conditions.
- Thus these operations require synchronization protection tools like mutexes.

## Atomic Operation
- Indivisible process
- Typically Won't require mutex, but may require if multiple atomic operation are required to be atomic as a whole(like in pub sub).

## Critical Section
- The critical section is a code segment where the shared variables can be accessed
- Any process can context switch any other process, regardless of it being in critical section.

## Critical Section Problem Criteria (IMPORTANT)
- MUTUAL EXCLUSION : If process Pi is executing in its critical section, then no other processes can be executing in their critical sections.
- PROGRESS : If a process is not using the critical section, then it should not stop any other process from accessing it. Only those processes are competing to go to critical section who wants to. 
- BOUNDED WAITING : There exists a bound, or limit, on the number of times that other processes are allowed to enter their critical sections after a process has made a request to enter its critical section and before that request is granted, so the process has to wait a bounded amount of time.

## Peterson Solution
- Useful for 2 process.
- There are 2 shared variables, flag (bool array) and turn (boolean) 
For Process 0
```c++
  flag[0] = T
  turn = 1;
  //Trap
  while(turn!=0 && flag[1]==T);
  //Critical Section
  flag[0] = F
  //Remaining Sectin
```

and 

```c++
  flag[1] = T
  turn = 0;
  //Trap
  while(turn!=1 && flag[0]==T);
  //Critical Section
  flag[1] = F
  //Remaining Sectin
```
- The variable turn indicates whose turn it is to enter its critical section. See it is imporant to notice that once flag is set to T for 0, turn is given to 1.
- This is done to ensure both process won't be trapped at the same time (deadlock), If both processes try to enter at the same
time, turn will be set to both i and j at roughly the same time.
- [See this to be clear](https://www.youtube.com/watch?v=XAsAAJSotA4&list=PLmXKhU9FNesSFvj6gASuWmQd23Ul5omtD&index=74)

### Peterson Solution won't work in modern machines
- Because of instruction reordering optimizations, (If turn is set to 1 before flag[0] is set to True), there is a chance when both the process enter critical section at the same time.
![](res/peterson_solution_issue.jpg)

## Hardware Support for Synchronization
- We saw we can't simply use software based solution because of instruction reordering.

### Memory Barriers/ Memory Fences
- How a computer architecture determines what memory guarantees it will provide to an application program is known as its
memory model. Computer architectures
provide instructions that can force any changes in memory to be propagated to
all other processors, thereby ensuring that memory modifications are visible to threads running on other processors. Such instructions are known as memory
barriers.
- ### Similar to volatile/Synchronized visibility guarantee in JAVA

#### Solving Instruction Reordering Issue in case of peterson Solution
- If we introduce a memory barrier between setting of flag and turn value assignment, we can guarantee value of flag is stored before the value of turn, thus preventing instruction reordering.

### Hardware Instructions
- These Instructions are atomic and form building blocks of concepts like atomic variables mutex etc.

#### Test and Set (PESSIMESTIC LOCKING)
- If target is true, it returns true and waits, if target is false(lock is unlocked), then test_and_set returns false and exits the trap.
```c++
//Similar function implemented at hardware level.
bool test_and_set(bool *target){
  bool temp = *target;
  *target = true;
  return temp
}

//Function showing use harware level atomic test_and_set.
void func(){
  while(test_and_set(&lock));
  //critical_section
  lock=false;
}
  ``` 

#### Compare And Swap (OPTIMISTIC LOCKING)
- ### a variable is only updated if it still has the same value as at the time we had fetched the value of the variable from the main memory.
- This operation is used to implement synchronization primitives like semaphores and mutexes.
- This is atomic operation supported by hardware.
- **sets to a new_value if current value is same as expected**.
- Does one more compare operation than test_and_set.
```c++
  int compare_and_swap(int *value, int expected, int new_value){
    int temp = *value;
    if(*value==expected)
      *value = new_value;
    return temp;
  }

  //trap or wait
  while(compare_and_swap(&lock,0,1)!=0);
  //critical_section
  lock=0;
  //remainder section
```

#### Compare and swap in Java
- Instead of using synchronised keyword, we can leverage CPU instruction compareAndSwap to write multithreaded code.
- Write this,
  ```java
  public static class MyLock {
      private AtomicBoolean locked = new AtomicBoolean(false);
      public boolean lock() {
          return locked.compareAndSet(false, true);
      }
  }
  ```
  Instead of
  ```java
    class MyLock {
      private boolean locked = false;
      public synchronized boolean lock() {
          if(!locked) {
              locked = true;
              return true;
          }
          return false;
      }
  }
  ```


### Atomic Variables
- Formed using or compare_and_swap hardware instructions.
- They don't entire solve race conditions in all cases.
- Consider a situation in which
the buffer is currently empty and two consumers are looping while waiting for count > 0. 
- If a producer entered one item in the buffer, both consumers could exit their while loops (as count would no longer be equal to 0) and proceed to
consume, even though the value of count was only set to 1.
- atomic integers are much lighter weight than traditional locks, and are generally more appropriate than mutex locks or semaphores for single updates to shared variables such as counters.
- For simple cases, Don't require overhead of locking, since they use mordern cpu instructions.


## Mutexes (Typically refers to locks which puts to suspended state)
- higher level apis to implement synchronization by application developer.
- Calls to either acquire() or release() must be performed atomically. Thus, mutex locks can be implemented using the compare and swap operation.
- alternative to spin lock.
- no busy waiting.

##  Spin locks/using busy waiting
- Type of locks where there is a while trap to see if mutex is unlocked yet.
- Called **SPIN LOCK** since, Process spins while having to wait for the lock, thus consuming useful CPU time. It requires **busy waiting**.
- Useful for systems where locks are held for short time, since there is no context switch(heavy operation) required when a process must wait on a lock.
- Useful for low contention scenarios
-  use a spinlock if the lock will be
held for a duration of less than two context switches.
  ```c++
  //lock
  void acquire(){
    while(!available);
    available = false;
  }

  //unlock
  void release(){
    available = true;
  }
  ```
- alternative to spin lock is suspending the process and waking it up once the lock is available.



## Lock Contention
- A lock is considered contended
if a thread blocks while trying to acquire the lock.
- If a lock is available when
a thread attempts to acquire it, the lock is considered uncontended.
- highly contended locks(a relatively large number of threads attempting to acquire the lock) tend to decrease overall performance of concurrent applications.

## Semaphores (IMPORTANT)
- Nothing but integer values
- 2 Types
  - Binary Semaphores 
    - Can only take 0 or 1, similar to mutexes/spin locks, but not the same.
  - Counting Semaphores
    - Unbounded

### Defination (default busy waiting)
- wait and signal have to be atomic operation.
#### wait / ENTRY SECTION
- Also known as P, Down.
- S is semaphore
```
void wait(S){
  //trap
  while(S<=0);
  S--;
}
```

#### Signal / EXIT SECTION 
- Also known as V, Up, Post, Release.
```
void signal(S){
  S++;
}
```

### Defination (suspended sleep)
- Since the busy waiting takes cpu cycles in wait trap. We try to define a semaphore where threads/processes are put into sleep state and are woken up by the threads exiting from the critical section. The process is then placed in the ready queue.
- To implement semaphores under this definition, we define a semaphore as follows:
  ```c++
    typedef struct {
      int value;
      struct process *list;
    } semaphore;
  ```
- It is a combination of integer value and a list(of process waiting for this semaphore).
- Here value of S can be negative.
- Negative value of S signifies the number of Processes in suspended state.
- SMP systems must provide techniques—such as compare and swap() or spinlocks — to ensure that wait() and signal() are performed atomically.
#### wait/ Entry Section 
- If block says:
  - You go inside if block if critical section is full, and can't have any more process go inside them.
  - Notice there is no equal to here.

```c++
wait(semaphore* S){
  S->value--;
  if(S->value<0){
    S->list->push(P1);
    sleep();
  }
}
```


#### signal/Exit section 

- If block says:
  - If processes are in suspended list, wake them up. 
  - There will only be processes in suspended list if S<=0 . 
  - (notice equal to) Equal to one because you are incrementing S by 1 (so before increment operation, the value of S was negative i.e processes in suspended list).

```c++
signal(S){
  S->value++;
  if(S->value<=0){
    P = S->list->pop();
    wakeup(P);
  }
}
```
- When process wakes up they go to critical section.  They don't again ```wait()```.
### Applications
#### Solve critical Section problem
- Using binary semaphores i.e S=1.

#### As a Conditional Variable.
- Say if you want S1 statement to only execute after S2 statement.
- You can use sempahores, by making semaphore = 0.
```
\\\process 1
S2
signal(semaphore)

\\\process 2
wait(semaphore)
S1
```
- For ordering multiple processes, you can use multiple semaphores.

#### Resource Management
- Say if your browser(chrome), should only have max 6 tcp connections in a single tab. You can set semaphore = 6, such that each request to tcp will call signal(semaphore), which decrements its value after checking for trap. This way only 6 connections are possible.

## Condition Variables
- a way to wait for another thread to do something (e.g., wait for a item to be added to the queue for processing).
- ## Each condition variable is tied to a lock. The thread calling signal/wait must be in the possession of the lock. look at the defination of wait and signal below, it is tied to lock.
- Just like semaphores, each condition variable has an associated queue.
- Condition Variables have 3 methods, wait, signal and signalAll/broadcast.

### wait
- ### wait(condition, lock): release lock. .
- thread is put in a wait set/queue for the condition.
- put thread to sleep until condition is signaled; 
- ### when thread wakes up again, re-acquire lock before returning.

### signal
- signal(condition, lock): if any threads are waiting on condition, wake up one of them.
- ### Caller must hold the lock, which must be the same that was used in the wait call.
- ### after signal, signaling thread keeps lock, waking thread goes on the queue waiting for the lock.
- In java there are 2 queues, wait queue and entry queue(calling signal/notify remove the thread from wait queue and puts it in entry queue(queue waiting to acquire lock)).

### Broadcast
-  same as signal but, wakes up all waiting threads.

### Important Point
- ## when a thread wakes up after cond_wait there is no guarantee that the desired condition still exists: another thread might have snuck in. 
- ## Since on signal, the waiting thread is put into ready queue of scheduler(not in CPU directly), and another process may be ahead in ready queue, which can change the condition. So you must do a while on the condition.
```c++

// Example : Infinite Queue Pub Sub
Lock lock;
Condition cv;
Queue q;

void producer(){
  lock.acquire();
  q.push(item);
  cv.signal(&lock);
  //after signal, lock is still with producer, so relase is necessary.
  lock.release();
}

void consumer(){
  lock.acquire();
  //Notice the while.
  while(q.isEmpty()){
    //it releases the lock on wait.
    cv.wait(&lock)
    //acquires it after wait.
  }
  item. = q.pop();
  lock.release();
}


```


## Mutex vs Binary semaphores
- They are not the same. a mutex is a locking mechanism, Semaphore is signaling mechanism.
- mutex locks are simpler and require less overhead than semaphores .
- A mutex can be released only by the thread that had acquired it. That is mutex has a principle of ownership.
- A binary semaphore can be signaled by any thread (or process).
- so semaphores are more suitable for some synchronization problems like producer-consumer. You can also use mutex with condition variable for this purpose.

## Mutex vs Spinlocks
- spinlocks -> busy waiting. (Useful if mutex is locked for very short time).
- mutex -> puts in wait queue. (Useful if time mutex is locked is very long compared to overhead of context switch, in that case spinlocks will waste cpu cycles).

## Hybrid mutex/critical section object (Windows)
- A hybrid mutex behaves like a spinlock at first on a multi-core system. If a thread cannot lock the mutex, it won't be put to sleep immediately, since the mutex might get unlocked pretty soon, so instead the mutex will first behave exactly like a spinlock. Only if the lock has still not been obtained after a certain amount of time (or retries or any other measuring factor), the thread is really put to sleep. If the same code runs on a system with only a single core, the mutex will not spinlock, though

## Monitors
- Just like synchronised block in java.
- The monitor construct ensures that only one process at a time is active within the monitor. Just like calling sychronised on the class's methods means no other thread can access other methods of the same instance of this class.
- In most implementations monitors along with mutex functionality, also have functionality to signal or wait on a condition variable.
- In the Java virtual machine, every object and class is logically associated with a monitor.


## Liveliness
- Liveness refers to a set of properties that a system must satisfy to ensure that processes make progress during their execution life cycle.

### Challenges to Liveliness

#### Deadlock
- Discussed Later

#### Priority Inversion
- Say if 3 processes have priority L<M<H.
- Say H requires a lock currently held by L. Ideally H will wait till L releases lock, but say M having higher priority process than L is currently executing. As a result, a lower priority process(M) is indirectly able to stop higher priority thread(H) from executing.
- **This can be avoided by priority inheritance, say if L is hold resource needed by H, L's priority is increased to H, till the resource is released.**

## Evaluation

### CAS Based (OPTIMISTIC LOCKING vs Traditional Pessimestic Locking)
- There has been a recent focus
on using the CAS instruction to construct lock-free algorithms that provide protection from race conditions without requiring the overhead of locking.
- CAS(Compare and swap) based approaches are considered an optimistic approach—you  optimistically first update a variable and then use collision detection to see if another thread is updating the variable concurrently.
- Mutual exclusion locking(MUTEX and Semaphores), in contrast, is considered a pessimistic strategy; you assume another thread is concurrently updating the variable, so you pessimistically acquire the lock before making any updates.
- CAS based are good for low and moderate contention loads, while mutex are good for heavy contention loads.

# Chapter 7

## Classical Problems

### The bounded buffer problem

### The reader writer problem

### The dining philosopher's problem

## Synchronization in Kernel


## Java Synchronization
- Refer Java Multithreading notes

## Latest Research in Synchronization

### Transactional Memory
- Similar to database transaction, either a set of instructions (read and write) go throw or it doesn't, i.e the set of instructions are atomic.
- transactional memory system—not the developer—is responsible for guaranteeing atomicity
- Can be implemented using hardware support.
- Software transactional memory is also possible but require the same low level locks.

### Functional Languages
- They don't act on state like imperative languages, i.e they deal with immutable values, so they don't need to be concerned with race conditions and dead locks.


# Chapter 8

## Deadlock
- Sometimes, a waiting thread can never again change state, because the resources it has requested are held by other waiting threads. This situation is called a deadlock.

## Livelock
- Livelock is another form of liveness failure.
- Whereas deadlock occurs when every thread in a set is blocked waiting for an event that can be caused only by another thread in the set, livelock occurs when a thread continuously attempts an action that fails. 
- Like a try-lock example where a process tries to acquire a set resource and if can't acquire all locks it will release all acquired locks, but if both the process tries to acquire locks together at the same time, they will stuck in infinite loop acquiring and releasing locks, this example livelock can be avoided by waiting a random amount of time before trying to acquire the next set of locks.
- This is precisely the approach taken by Ethernet networks when a network collision occurs. Rather than trying to retransmit a packet immediately after a collision occurs, a host involved in a collision will backoff a random period of time before attempting to transmit again.

## Conditions for deadlock (all are necessary)
### Mutual exclusion.
At least one resource must be held in a nonsharable mode; that is, only one thread at a time can use the resource. 
### Hold and wait
A thread must be holding at least one resource and waiting to acquire additional resources that are currently being held by other threads.

### No preemption.
Resources cannot be preempted; that is, a resource can be released only voluntarily by the thread holding it, after that thread has completed its task.

### Circular wait
T0 waiting for T1 waiting for T2....Tn waiting for T0.

## Resource allocation graph (Find if deadlock exists)
- if a resource-allocation graph does not have a cycle, then the system is not in a deadlocked state. 
- If there is a cycle, then the system may or may not be in a deadlocked state. If each resource type has exactly one instance, then a cycle implies that a deadlock has occurred. If each resource type has several instances, then a cycle does not necessarily imply that a deadlock has occurred. 

![](res/resource_allocation_graph.jpg)

## Handle Deadlock

- Ignore the deadlock: Linux and Windows Kernel (More performant)
- Avoid the deadlock : developers have to ensure
- Detect and recover : Databases

## Deadlock Prevention
- Make sure atleast one of the condition for deadlock doesn't hold.  By ensuring that at least one of these conditions
cannot hold, we can prevent the occurrence of a deadlock.

### Mutual Exclution
Remove the dependency of any non sharable data(sharable data : readonly files which don't require mutex).

### Hold and wait
- To ensure that the hold-and-wait condition never occurs in the system, we must guarantee that, whenever a thread requests a resource, it does not hold any other resources.
- This would either require thread to get all resources at once before execution, or before acquiring a new resource release all the ones it has.
- Both these have disadvantage 
  - Can lead to starvation because popular resources are always in use.
  - Can lead to resource underutilization

### No premption
- Kind of like using trylock for deadlock handling
- If a thread is not able to get the resource it is requesting, it should prempt the resource it is already holding if some other thread is asking for it and wait till all the resources are available including the new resource.

### Circular Condiiton
- Practical unlike the rest.
- Requires all the threads to acquire the resources in the same order.
-  Java developers have adopted the strategy of using the method ```System.identityHashCode(Object)``` for 
 ordering lock acquisition. It returns an integer. Here unlike hashCode identity of the object matters, not just the value.


## Deadlock Avoidance Algorithms
- OS needs to have additional information about the resources a thread may need and use this information to decide for each request if a thread should wait or not. 
- Each request requires that in making this decision the system consider the resources currently available, the resources currently allocated to each thread, and the future requests and releases of each thread.

### Safe State
- A state is safe if the system can allocate resources to each thread (up to its maximum) in some order and still avoid a deadlock.
- Not all unsafe states are deadlocks 

### Resource-Allocation-Graph Algorithm
- If we have a resource-allocation system with only one instance of each resource type, we can use a variant of the resource-allocation graph.
- Basically a O(n^2) cycle detection algorithm.
- The resource-allocation-graph algorithm is not applicable to a resource allocation system with multiple instances of each resource type.
-  we introduce a new type of edge, called a claim edge. A claim edge Ti → Rj indicates that thread Ti may request resource Rj at some time in the future.
- When thread Ti requests resource Rj , the claim edge Ti → Rj is converted to a request edge. 
-  The request can be granted only if converting the request edge Ti → Rj to an assignment edge Rj → Ti does not result in the formation of a cycle in the resource-allocation graph.
![](res/resource_allocation_graph_DEADLOCK.jpg)

### Banker's Algorithm
- The resource-allocation-graph algorithm is not applicable to a resourceallocation system with multiple instances of each resource type. But Banker's algorithm is applicable to such systems, it is less efficient though O(m*n^2) m is total threads, and n is total type of resources.
- There are 2 algorithms here, one to determine if a system is in safe state(based on the currently allocated resources, the max number of resources a thread might need in future and currently available resources).
- Second to determine, if a request to set of resources can be granted, for this we try to check if it is even possible to allocate based on number of number of available resources and check if after allocating resources the system might be in safe state or not. If it is going to be in safe state, resources are allocated, else they are not.

## Detecting Deadlocks

### Wait Graph
- Mostly used in Java(In DUMPs) and databases like MySQL
- Useful only in situations, where only a single instance of each resource kind exist.
- Similar to resource allocation graph, edges signifies whether a Thread i is waiting for Thread j to release a resources.
- If there is a cycle in the resource allocation graph, then there exists a deadlock.
![](res/wait_graph.jpg)

## Variant of Banker's Algoritm
- Useful in case of multiple instances of each resource type.
- Similar to the safe state detection.

## Deadlock Recovery

### Kill the process/ thread causing deadlock (to break the circular wait)

#### Abort all deadlocked processs/threads
- partial computations would be discarded.

#### Abort process one at a time, till deadlock is eliminated
- High overhead, since we need to check if deadlock is there or not after each kill

### Resource Premption
- we successively preempt some resources from processes and give these resources to other processes until the deadlock cycle is broken.
- This has challenges like which victim to prempt resources from, and since the process can't continue normal execution how can we roll back etc.


# Chapter 9

## Relocatable Code
- Relocatable code is software whose execution address can be changed. A relocatable program might run at address 0 in one instance, and at 10000 in another. It has to be binded into physically address before execution.

## Address Binding

- Classically, the binding of instructions and data to memory addresses can
be done at any step along the way:
### Compile Time Binding
- Useful in Embedded Systems
- If you know at compile time where the process will reside in memory, then absolute code can be generated.
- If, at some later time, the starting location changes, then it will be necessary to recompile this code.

### Load Time Binding
- If it is not known at compile time where the process will reside in memory, then the compiler must generate relocatable code.
- In this case, final binding is delayed until load time.
- If starting address changes, you only need to load the program again.(No need to compile)

### Execution Time Binding
- In this binding the logical and physical address differs.
- In this binding, the CPU will only see the logical address i.e the relocatable code. It will be the responsibility of the MMU to resolve it to physical address at run-time.
- Most modern os follow this binding.
- Mapping can be done using simple logic in which base/relocation register's value is added to all logical address to get physical address
  - This requires the physical memory to be allocated in contiguos fashion
  - Also causes fragmentation
- Another more popular way to map is Paging.

## Dynamic Loading
- A routine is not loaded by an executable unless it is called, all routines are stored in disk in relocatable load format.
- When a routine is called, the relocatable linker loader is called to load the desired routine in memory and update the program's address table.
- Dynamic loading does not require special support from the operating system. 
- it's the program's job to open that library.

## Dynamic Linking and Shared Libraries (.so and .dll)
- Dynamic linking, in contrast, is similar to dynamic loading. Here, though, linking, rather than loading, is postponed until execution time.
- Unlike dynamic loading, dynamic linking and shared libraries generally require help from the operating system.
- When your program starts it's the system's job to open these libraries, which can be listed using the ldd command.
### Advantages
- Helps to reduce the size of the executable and also in turn the main memory.
- These can be shared by various processes, so if it is already in memory, it doesn't need to be loaded again.
- Any change in dll, doesn't require the executable to be compiled again.

## Contiguous Memory Allocation
-  In contiguous memory allocation, each process is contained in a single section of memory

### Protect Processes from each other in case of Contiguous Memory Allocation
- We first need to make sure that each process has a separate memory space.
- To separate memory spaces, we need the ability to determine the
range of legal addresses that the process may access and to ensure that the process can access only these legal addresses.

#### Base(Relocation) and Limit Registers
- We can provide this protection by using two registers, usually a base and a limit.
- The base register holds the smallest legal physical memory address.
- the limit register specifies the size of the range.
- Any attempt by a program executing in user mode to access memory address that doesn't fall in this limit causes a fatal error.
- only the operating system can load the base and limit registers, it operates on kernel mode.
- On a context switch the os stores the register contents of the currently executing process in memory and loads the register contents of the new process from the memory.

### Memory Allocation in Contiguous Memory
- first-fit 
  - Allocate the first hole that is big enough.
- best-fit 
  - Allocate the smallest hole that is big enough.
  - Need to search the entire list of free holes
- worst-fit 
  - Allocate the largest hole
  - Need to search the entire list of free holes

Both first fit and best fit are better than worst fit in terms of decreasing time and storage utilization.
### Wait queue for memory allocation
- When there isn't enough memory, processes can be put into wait queue.
- When memory is later released, the operating system checks the wait queue to determine if it will satisfy the memory demands of a waiting process.

### Fragmentation in Contiguous Memory Allocations
#### Internal Fragmentation
- unused memory that is internal to a partition.
- Say, a hole is 1002Bytes, and your process is 1001 Bytes, so the overhead of tracking this one byte is way more than one byte, in this case the entire 1002 is allocated thus leading to fragmentation of 1Byte.
- Paging also suffers from this.

#### External Fragmentation
- External fragmentation exists when there is enough total memory space to satisfy a request but the available spaces are not contiguous.
- Solution to solve this is Paging or run compaction on regular intervals.
- It is a general problem that occurs when we have to manage blocks of data, be it in RAM or Harddisk or SSD.

## Paging (Non Contiguous Memory Allocation)
- Permits a process’s physical address space to be noncontiguous.

### Working
- breaking physical memory into fixed-sized blocks called **frames**, and breaking logical memory into blocks of the **same size** called **pages**.
- ### It is important to note Pages are the same size as frames
- The page number is used as an index into a per-process page table.
- The page table contains the mapping of base address of each frame in physical memory to the corresponding page in logical memory.
- Logical address has 2 parts the Virtual Page Number and the offset. Similarly physical address has Physical Frame Number and the same offset.
- the offset is the location in the frame/page being referenced, i.e amount of bytes after the frame.
- #### offset does not change on translation since the size of frame == size of pages.
- Thus, the base address of the frame is combined with the page offset to define the physical memory address.
![](res/paging_hardware.jpg)


### Page Size
- Typically power of 2, varying between 4 KB to 1 GB
- The selection of a power of 2 as a page size makes the translation of a logical address into a page number and page offset particularly easy.
- If the size of the logical address space is 2^m, and a
page size is 2^n bytes.
  - Total number of pages are (2^(m-n)) so total bits to represent frame number or page number is m-n.
  - And n bits are required to represent the offset (since offset can go from 0 to size_of_page -1).

![](res/example_translation_paging.jpg)
- Small pages reduces internal fragmentation, but have overhead in the number of entries in page table.
- Large pages have high internal fragmentation, but the page table overhead is low, also disk I/O is efficient when amount of data being transferred is large. Good for Databases.
- Some CPUs and OS support multiple page sizes.

- ```getconf PAGESIZE``` to get the page table size in linux.



### Frame table
- The operating system is managing physical memory, it must be aware of the allocation details of physical memory—which frames are allocated, which frames are available, how many total frames there are, and so on. This information is generally kept in a single, system-wide data structure called a frame table.
- The frame table has one entry for each physical page frame

### Advantages of Paging
- Paging avoids external fragmentation and the associated need for compaction. (we may have some internal fragmentation. Notice that frames are allocated as units.)
- a process can have a logical 64-bit address space even though the system has less than 2^64 bytes of physical memory.
- Allows to share pages.

### Paging and Context Switch
- The operating system maintains a copy of the page table for each process, just as it maintains a copy of the instruction counter and register contents.
-  It is also used by the CPU dispatcher to define the hardware page table when a process is to be allocated the CPU. Paging therefore increases the context-switch time.


### Protection in Paging
- Page table has bits for memory protection.
- These bits define if the given page is a read only/read-write.
- In case page table has entire physical address space, an additional bit(valid bit) is kept to see if the current page is infact a part of process's logical address page and is legal to access. 
- Some systems provide hardware, in the form of a page-table length register (PTLR), to indicate the size of the page table. This value is checked against every logical address to verify that the address is in the valid range for the process. This concept is similar to base and limit register.

### Shared Pages
- Pages containing the same information and is reentrant(non self modifying) can be shared across multiple process, like there can only be one libc copy in memory and the same copy can be shared across multiple processes by having different page table mappings for each processes.
- compilers, window systems, database systems, and so on can also be shared.
- Some operating systems implement shared memory using shared pages.


## Hardware Support for Paging

### Hardware support for page tables

#### dedicated hardware registers
- It is useful when the size of page table is small. Since access time is really fast
- But this approach increases context switch times.

#### PAGE TABLE BASE REGISTER : In memory page tables
- most cpus support large page tables, which is not possible using hardware registers
- Instead, the page table is kept in memory and a pointer to page table, i.e a page table base register points to the page table location in memory.
- this pointer is stored in the process control block of each process.
- Context switch times are considerably high, and also TLB reduces the time for address resolution.

### Translation Look Aside Buffer
- #### By keeping page table in memory, we increase the time required to access the memory 2 times, (one to fetch the page table entry and then final physical address).
- To reduce this time we can use a hardware cache TLB. (Can be LRU Cache).
- a TLB lookup in modern hardware is part of the instruction pipeline, essentially adding no performance penalty.
-  Some CPUs implement separate instruction and data address TLBs. And also multi-layer TLB (just like multi-layer cache).
-  Some kernel entries can be **wired down** in TLB, meaning they can't be removed.

#### ASIDs : Protection in TLB (IMPORTANT)
- Apart from just containing mapping between logical and physical address, TLB has additional data (address-space identifier) regarding what the current entry's process is. 
- When the TLB attempts to resolve virtual page numbers, it ensures that the ASID for the currently running process matches the ASID associated with the virtual page. 
- If TLB doesn't support ASID, then the entire TLB would have to be flushed on context switch.

## Types of Page Tables

### Hierarchical Page Tables
- A simple page table would be too large for address space in range (2^32 to 2^64)
- For 32 bit architecture, page size : 4KB(2^12), total page size entries are (2^(32-12) = 2^20). Assuming each page table entry is 4 bytes, This means we need 4MB of physical memory just to store page table for each process.
- One solution is to use 2 level paging table, in which page table is also paged in itself. 
- A logical address is divided into a virtual page number (20 Bits) and an offset, by paging the page table we end up with two 10 Bit page number(one for outer page table, one for inner) and an offset.
- Because address translation works from the outer page table inward, this scheme is also known as a forward-mapped page table.
![](res/two_level_page_table.jpg)

- For a system with a 64-bit logical address space, a two-level paging scheme is no longer appropriate. In such cases 7 level page table might be required which increases memory access time(Thus heirarchical page tables are not very suitable for 64Bit Architecture).

### Hashed Page Tables
- For address spaces larger than 32 bit, we can use hashed page tables.
- The logical address is hashed to a key in the hash table, where every key corresponds to a linkedlist of values(to handle collision).
- Each element in linked list has the following values, the virtual page number(p), the page frame number(r) and the pointer to the next element in linkedlist.
- If there is no match, subsequent entries in the linked list are searched for a matching virtual page number

![](res/hashed_page_table.jpg)

#### Clustered Page Tables
- Similar to hashed page tables, but each entry in linked list refers to several page frames.
- Useful in sparse address spaces


### Inverted Page Tables
- An inverted page table has one entry for each real page (or frame) of memory.
- only one page table is in the system, and it has only one entry for each page of physical memory.
- Each entry in the singleton page table has page frame number, virtual page number and also process identifier (which acts as a Address space identifier for security, since there is one page table for system, not one for process).
- This method decreases the amount of memory required to store page table, but increases the time to search for an entry, worst case entire page table might have to be searched before we find an entry(linear).
- We can use hashtable to limit the search to one or few(collision handling). However this approach requires 2 memory access, one for hash-table entry and one for page table.
- Also we can utilize features like shared memory, because one physical page cannot have 2 virtual address.

![](res/inverted_page_table.jpg)

## Swapping
- Swapping makes it possible for the total physical address space of all processes to exceed the real physical memory of the system, thus increasing the degree of multiprogramming in a system.

### Standard Swapping
- Moving entire process between main memory and a backing store(swap space).
- All per-thread data structures must be swapped as well and heap too.
- If a process is idle for long, it can be swapped.

### Swapping with Paging (Demand Paging?)
- It takes a lot of time to perform standard swapping.
- Most modern systems swap individual pages in and out of memory rather than entire processes.
- A page out operation moves a page from memory to the backing store; the reverse process is known as a page in.

### Swapping in mobile systems
- Mobile systems don't support swapping, because of space constraint and limited number of writes in flash memory.
- If memory becomes too low, the os will ask process to voluntarily free up read-only data(such as code, since it can be read back from flash memory). Modified data like stack aren't removed. 
- If any app fails to free up memory, it may be terminated.


## Segmentation and Paging in Intel Architecture
- In Intel memory management unit is divided into 2 components segmentation and paging.
- Logical address from CPU is fed to segmentation unit, which generated linear address, which inturn is fed to paging unit to be converted into physical address.

![](res/segm_paging_interl.jpg)

### Segmentation in IA-32
- Segmentation is a memory management technique in which each job is divided into several segments of different sizes, one for each module.
- The logical address has 2 parts (each of 8K segments).
- Information about First part is stored in  Local Descriptor Table and second in Global Descriptor Table.
- Each entry in descriptor table has information about particular segment and base location of that segments which is used to generate the linear address and check for validation using limit location.

![](res/segmentation_table.jpg)

### Paging in Intel
- Using page tables (2 layer in 32 bit) and 4 layer in 64 bit.
- The x86-64 architecture currently provides a 48-bit virtual address with support for page sizes of 4 KB, 2 MB, or 1 GB using four levels of paging hierarchy.
![](res/pagin_in_intel.jpg)

- ARM also uses 4 layer of page tables.

# Chapter 10

## Advantages of virtual memory
- Virtual memory is a technique that allows the execution of processes that are not completely in memory.
  - Not all parts of code is necessary, like error condition handling etc.
  - Even if needed, they may not be needed at same time.
-  Users would be able to write programs for an extremely large virtual address space, simplifying the programming task.
- Virtual memory also allows processes to share files and libraries, and to implement shared memory.
  ![](res/shared_library.jpg)
- Because each program could take less physical memory, more programs could be run at the same time.

## Virtual Address Space of a process
- Logical view of how process is stored in memory.
- It is contiguous memory.
- we allow the heap to grow upward in memory as it is used for dynamic memory allocation. Similarly, we allow for the stack to grow downward in memory through successive function calls. 
- The large blank space (or hole) between the heap and the stack is part of the virtual address space but will require actual physical pages only if the heap or stack grows.

![](res/virtual_address_space.jpg)
- A detailed view is in notes for Chapter - 2 

## Demand Paging
- Pages are loaded only when they are demanded during program execution.
- Pages that are never accessed are thus never loaded into physical memory.

### Valid-Invalid Bit in Page Table
- This bit is used to identify if the requested page is in memory or in disk.
- #### The valid-invalid bit serves 2 purposes, it is used to denote if a page is legal or not i.e not in the address space of process, and also it is used if the page is not currently in memory.
- Access to a page marked invalid causes a page fault, a trap is raised which then has to be handled by os.
- It is the duty of os to check if the access was legal or not using an internal table (usually kept with the process control block). If not legal terminate the application.
- If legal fetch the page from disk.

### Free Frame List
- To resolve page faults, most operating systems maintain a free-frame list, a pool of free frames for satisfying allocation request for the page in disk.
- Free frames must also be allocated when the stack or heap segments from a process expand.
- When a system starts up, all available memory is placed on the free-frame list and the list shrinks as memory is allocated through say, demand paging.
- Once the list becomes empty or reaches a threshold, it has to be repopulated by analysing free frames in memory and zeroing them out.

#### Zero-Fill-On-Demand 
- Zero-fillon-demand frames are “zeroed-out” before being allocated, thus erasing their
previous contents.
- This is necessary for security reasons.

### Steps in handling page fault.

- Page fault causes trap to the operating system.
- Save the register and process state(PCB). 
- Determine the interrupt was a page fault.
- Check if the reference was legal (using an internal table usually kept with the process control block) or not, if illegal terminate the process.
- If legal, determine the location of the frame in secondary storage.
- Issue a read operation from the disk for the free frame
  - Wait in wait-queue until read IO is complete.
  - This includes device seeks and latency time between memory and secondary storage.
  - Begin transfer of page to a free physical frame.
- Scheduler might allocate CPU core to some other process while waiting for above IO.
- Once IO is complete and the free frame is assigned and filled, an interrupt is raised, which os handles by updating the page table and other tables to show the requested frame is not in memory.
- Move the original process(where page fault occured) from wait queue to ready queue and wait till CPU core is assigned to the original process again.
- Restore the registers, process state, and new page table, and then resume the interrupted instruction.
 

![](res/page_fault_steps.jpg)

### Pure Demand Paging
- pure demand paging: never bring a page into memory until it is required.
- we can start executing a process with no pages in memory.

### Hardware support for Demand Paging
- Page Table
- Secondary Memory 
  - It is known as the swap device, and the section of storage used for this purpose is known as swap space. It is not in file system and is usually faster to read and write than file system.

### Restart after Page Fault.
- A crucial requirement for demand paging is the ability to restart any instruction after a page fault.
- This is achieved by saving the state (registers, condition code, instruction counter) of the interrupted process.
- If page fault occurs in instruction fetch(from memory), we can restart by fetching the instrution again from memory (this time it will be there i.e after page fault interrupt resumes).
- If page fault occurs while fetching operand, we have to fetch and decode the instruction again from memory and then fetch the operand. This case isn't a big concern though.
#### Idempotency in restart.
- Major difficulty arises when an instruction modifies several different location, like a move instruction from source to destination. If source or destination straddles in page boundary, page fault will occur. And if source and destination overlaps, the instruction can't be simply restarted since source might have been partially modified.
-  In one solution, the microcode computes and attempts to access both ends of both blocks. If a page fault is going to occur, it will happen at this step, before anything is modified.
- The other solution uses temporary registers to hold the values of overwritten locations. If there is a page fault, all the old values are written back into memory before the trap occurs.

### Performance of Demand Paging
```effective access time = (1 − p) × ma + p × page fault time.```

- Major portion of servicing a page fault is latency in hard disk (3 ms) and average seek of (5 ms). Thus time for page fault is 8ms.
- Time for memory access time is in order of 200 nano seconds.
- To make sure the performance impact of demand paging is less than 10 percent, probability of page fault should be one out of 4,00,000 memory accesses.

### Demand from file System vs Swap Space (also known as swapping).

- I/O to swap space is generally faster than that to the file system. It is faster because swap space is allocated in much larger blocks, and file lookups and indirect allocation methods are not used.

#### Approaches to demand Paging
- One approach is to copy the entire process into swap space before starting every process (since demand paging from swap space is faster), but the disadvantage is the copy to swap space can significantly slow down startup of a process.
- More popular approach is to demand page from file system at the start, but on page replacement we write to the swap space. This approach will ensure that only needed pages are read from the file system but that all subsequent paging is done from swap space.
- If access to swap space is limited, the read-only part say the code is discarded on page replacement and if their access is required in future they are read directly from file system since they are not modified i.e the file system itself serves as backing store. However here the anonymous memory (modified memory) i.e heap and stack must still use swap space as they are not associated with a file.
- In mobile system, since swapping is disabled (no swap space), so the mobile system demand-page from the file system itself. This implies the anonymous memory is never reclaimed, while the process is running (since there is no swap space).

#### Confusion regarding Demand Paging vs Swapping
- Demand Paging can be achieved by either moving memory to and from swap space (referred as swapping) or directly from file system(swapping is not used to refer to this). 
- It is the above term swapping i.e existence of swap space that is not supported by mobile systems.

# To read
- https://blog.feabhas.com/2009/09/mutex-vs-semaphores-%E2%80%93-part-1-semaphores/
- https://blog.feabhas.com/2009/09/mutex-vs-semaphores-%E2%80%93-part-2-the-mutex/
- https://blog.feabhas.com/2009/10/mutex-vs-semaphores-%E2%80%93-part-3-final-part-mutual-exclusion-problems/


# Misc
- Interrupt Service Routine
- Process Control Block
- spurious wake up
- multithreading vs multiprocessing