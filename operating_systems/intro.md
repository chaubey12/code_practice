Three main concepts : Virtualization, Concurrency and Persistence.
These concepts lay the foundation for understanding how an operating system works.

Basics of CPU virtualization and memory:
- CPU Scheduling
- Process Virtualization
- API Virtualization

Concurrency concepts:
- Locks
- Semaphores
- Triaging concurrency bugs like deadlocks

Persistence
- I/O devices
- File systems


To do:
- How an operating system works
- How OS decides what program to run next on CPU
- How OS handles memory overload in a virtual memory system
- How Virtual Machine Monitor Works
- How to manage information on disks
- How to build distributed system that works when parts have failed


Running a program on Computer
- Billions of instructions run per second
- Instruction : add numbers, access memory, check condition, jump to a function
- Processor : fetch -> decode -> execute
- Processor for efficiency : executing mutiple instructions at once, issuing and completing them out of order.
- OS makes it easy to run programs, allowing programs to share memory, enabling programs to interact with devices
- VIRTUALIZATION
- OS takes a physical resource (processor, memory, disk) and transforms into a more general, powerful, easy-to-use virtual form of itself.
- To enable giving instructions, OS provides APIs.
- Virtualization allows many programs to run (sharing CPU) and many programs to concurrenctly access their instructions and data(sharing memory), and many programs to access devices (sharing disks), the OS is known as resource manager.
- CPU, memory and disk are resources, that are managed by operating systems.