# Virtual Memory

## Understanding Memory
- Variables are a convenience for programmers: the computer really works on the memory
- In Random Access Memory (RAM), all addresses are equally fast to access
    - Whereas hard drives cannot access all data equally fast
- At any given moment, a program is likely to be accessing only a **small part** of its memory
- **Temporal Locality**: recently used data is likely to be reused
- **Spatial Locality**: the next data you need is likely nearby previous data you used
- Virtual memory is a mechanism to enable:
    - Physical memory sharing between multiple processes
    - Isolation of each process's memory access
    - In other words, a process uses virtual memory instead of physical memory
- Virtual memory needs to be translated to physical memory space
- All memory we've discussed has been virtual memory (fork(), exec(), pointers, etc.)
- Virtual memory size is determined by pointer size
- Only kernel-level components can deal with both virtual and physical addresses
- Each process gets its own virtual address space
- A process only sees its own address space (memory isolation)
- Thanks to temporal and spacial locality, a process likely doesn't need all of its data at
  once
- The **swap drive/space** is where the OS can swap to a file on disk areas that haven't been
  recently used

## Address Translation
- Virtual memory is divided into regions called **pages**
    - Each page is mapped to a physical memory **page frame**
    - Kernel controls the mapping

## Paging
- Virtual address space is divided into fixed-size pages
    - e.g. 4KB
- Physical memory is divided into page frames
    - Each is the same size as a page
    - e.g. 8KB of physical memory -> 2 frames of 4KB each
- A virtual address is divided into two parts: the page number and the offset
- If we have 4 pages, we need 2 bits to pick between the pages
    - 00, 01, 10, 11
- If each page is 16 bytes, we need 4 bits of offset into the page
- When a process accesses a virtual address, paging translates the address's page number into the
  page frame number
- Since there are vastly more virtual pages than physical page frames, we cannot map all pages to
  frame at once
  ## Address Translation
  - Virtual memory is divided into regions called **pages**
    - Each page is mapped to a physical memory **page frame**
    - Kernel controls the mapping

## Paging
- Virtual address space is divided into fixed-size pages
    - e.g. 4KB
- Physical memory is divided into page frames
    - Each is the same size as a page
    - e.g. 8KB of physical memory -> 2 frames of 4KB each
- A virtual address is divided into two parts: the page number and the offset
- If we have 4 pages, we need 2 bits to pick between the pages
    - 00, 01, 10, 11
- If each page is 16 bytes, we need 4 bits of offset into the page
- When a process accesses a virtual address, paging translates the address's page number into the
  page frame number
- Since there are vastly more virtual pages than physical page frames, we cannot map all pages to
  frame at once
  ## Address Translation
  - Virtual memory is divided into regions called **pages**
    - Each page is mapped to a physical memory **page frame**
    - Kernel controls the mapping

## Paging
- Virtual address space is divided into fixed-size pages
    - e.g. 4KB
- Physical memory is divided into page frames
    - Each is the same size as a page
    - e.g. 8KB of physical memory -> 2 frames of 4KB each
- A virtual address is divided into two parts: the page number and the offset
- If we have 4 pages, we need 2 bits to pick between the pages
    - 00, 01, 10, 11
- If each page is 16 bytes, we need 4 bits of offset into the page
- When a process accesses a virtual address, paging translates the address's page number into the
  page frame number
- Since there are vastly more virtual pages than physical page frames, we cannot map all pages to
  frame at once
  ## Address Translation
  - Virtual memory is divided into regions called **pages**
    - Each page is mapped to a physical memory **page frame**
    - Kernel controls the mapping

## Paging
- Virtual address space is divided into fixed-size pages
    - e.g. 4KB
- Physical memory is divided into page frames
    - Each is the same size as a page
    - e.g. 8KB of physical memory -> 2 frames of 4KB each
- A virtual address is divided into two parts: the page number and the offset
- If we have 4 pages, we need 2 bits to pick between the pages
    - 00, 01, 10, 11
- If each page is 16 bytes, we need 4 bits of offset into the page
- When a process accesses a virtual address, paging translates the address's page number into the
  page frame number
- Since there are vastly more virtual pages than physical page frames, we cannot map all pages to
  frame at once
  ## Address Translation
  - Virtual memory is divided into regions called **pages**
    - Each page is mapped to a physical memory **page frame**
    - Kernel controls the mapping

## Paging
- Virtual address space is divided into fixed-size pages
    - e.g. 4KB
- Physical memory is divided into page frames
    - Each is the same size as a page
    - e.g. 8KB of physical memory -> 2 frames of 4KB each
- A virtual address is divided into two parts: the page number and the offset
- If we have 4 pages, we need 2 bits to pick between the pages
    - 00, 01, 10, 11
- If each page is 16 bytes, we need 4 bits of offset into the page
- When a process accesses a virtual address, paging translates the address's page number into the
  page frame number
- Since there are vastly more virtual pages than physical page frames, we cannot map all pages to
  frame at once
  ## Address Translation
  - Virtual memory is divided into regions called **pages**
    - Each page is mapped to a physical memory **page frame**
    - Kernel controls the mapping

## Paging
- Virtual address space is divided into fixed-size pages
    - e.g. 4KB
- Physical memory is divided into page frames
    - Each is the same size as a page
    - e.g. 8KB of physical memory -> 2 frames of 4KB each
- A virtual address is divided into two parts: the page number and the offset
- If we have 4 pages, we need 2 bits to pick between the pages
    - 00, 01, 10, 11
- If each page is 16 bytes, we need 4 bits of offset into the page
- When a process accesses a virtual address, paging translates the address's page number into the
  page frame number
- Since there are vastly more virtual pages than physical page frames, we cannot map all pages to
  frame at once
  ## Address Translation
  - Virtual memory is divided into regions called **pages**
    - Each page is mapped to a physical memory **page frame**
    - Kernel controls the mapping

## Paging
- Virtual address space is divided into fixed-size pages
    - e.g. 4KB
- Physical memory is divided into page frames
    - Each is the same size as a page
    - e.g. 8KB of physical memory -> 2 frames of 4KB each
- A virtual address is divided into two parts: the page number and the offset
- If we have 4 pages, we need 2 bits to pick between the pages
    - 00, 01, 10, 11
- If each page is 16 bytes, we need 4 bits of offset into the page
- When a process accesses a virtual address, paging translates the address's page number into the
  page frame number
- Since there are vastly more virtual pages than physical page frames, we cannot map all pages to
  frame at once
  ## Address Translation
  - Virtual memory is divided into regions called **pages**
    - Each page is mapped to a physical memory **page frame**
    - Kernel controls the mapping

## Paging
- Virtual address space is divided into fixed-size pages
    - e.g. 4KB
- Physical memory is divided into page frames
    - Each is the same size as a page
    - e.g. 8KB of physical memory -> 2 frames of 4KB each
- A virtual address is divided into two parts: the page number and the offset
- If we have 4 pages, we need 2 bits to pick between the pages
    - 00, 01, 10, 11
- If each page is 16 bytes, we need 4 bits of offset into the page
- When a process accesses a virtual address, paging translates the address's page number into the
  page frame number
- Since there are vastly more virtual pages than physical page frames, we cannot map all pages to
  frame at once
  ## Address Translation
  - Virtual memory is divided into regions called **pages**
    - Each page is mapped to a physical memory **page frame**
    - Kernel controls the mapping

## Paging
- Virtual address space is divided into fixed-size pages
    - e.g. 4KB
- Physical memory is divided into page frames
    - Each is the same size as a page
    - e.g. 8KB of physical memory -> 2 frames of 4KB each
- A virtual address is divided into two parts: the page number and the offset
- If we have 4 pages, we need 2 bits to pick between the pages
    - 00, 01, 10, 11
- If each page is 16 bytes, we need 4 bits of offset into the page
- When a process accesses a virtual address, paging translates the address's page number into the
  page frame number
- Since there are vastly more virtual pages than physical page frames, we cannot map all pages to
  frame at once
