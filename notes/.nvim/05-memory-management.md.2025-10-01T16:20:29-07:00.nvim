# Memory Management
- malloc() uses the heap to dynamically allocate variables

 ## brk() and sbrk()
- The **program break** is used by linux to indicate the address in memory where the heap ends
- In order to get more space, the OS moves the program break higher to expand the heap for us
- **brk** and **sbrk** change the location of the program break
    - syscall
    - sbrk() moves the program break by however many bytes specified
    - brk() takes in how many bytes of memory you want, and moves the program break based on
      that
- malloc() calls sbrk() to get a big block of memory, even if that specific call to malloc()
  doesn't require that much space
    - Does this in order to reduce overhead
    - Hands out small pieces of memory for each request

## Overview of Dynamic Memory
- For each allocation request, malloc (our memory allocator), returns a pointer to an unused
  region inside the heap
- **Fragmentation**: over time, the application allocates and frees memory regions. This
  results in broken up pockets of used and freed memory
- Therefore, we need to track the free blocks in memory using a **linked list**
    - The head of the list points to the most recent free block
- How does malloc() utilize this linked list?:
    - Pick a free block from the linked list and remove it from the linked list
    - Then split the free block into allocated and free blocks
    - Insert the new free block into the linked list, return the allocated block
- To create this linked list without dynamically allocating it:
    - Create a header on each block to track the size of the block we're in and a pointer to
      the next block
- **External Fragmentation** is when free memory is fragmented into smaller blocks
    - We cannot split up allocation across multiple blocks
        - That means that if we have enough *total* memory, it doesn't matter if we don't have
          enough within a *single block*

## Finding a Free Block
- The **First Fit Algorithm** finds the first block that is big enough by starting at the head
- The **Best Fit Algorithm** finds the smallest block that is big enough
    - This reduces wasted memory space
- The **Worst Fit Algorithm** finds the largest free block
    - Produce large leftover blocks that we can use later
