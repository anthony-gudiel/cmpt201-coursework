# Threads

- A **thread** is a unit of execution
    - Sometimes called a lightweight process
- Processes have separate virtual address spaces, while threads share the same address space
    - Threads inside of a process share the same address space, but get separate stacks,
      registers, and errno
- Benefits of threads:
    - Data sharing is easy through the use of threads
    - Threads are faster to create than processes
- Benefits of processes:
    - Memory isolation
- When using `pthread_create()`, one of the arguments we pass is a function pointer to tell the thread what to do
- `pthread_exit()` to terminate a thread, or just use `return`
- `pthread_self()` returns the caller's ID, use `gettid()` to be able to print Linux thread ID
  as a number
- `pthread_join()` waits until the provided thread terminates
