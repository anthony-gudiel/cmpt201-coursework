# Quiz 2 Review

## A5: Debugging Tools
- **Logging**: Where you insert print statements in your code to trace code flow
    - log.c library is used over printf(), as it provides many additional features like message
      severity, line number, etc.
    - e.g. log_trace(), log_debug()
- **Assertions**: A function that checks if a condition is true, and if not, throws an error
    - Can be used as a precondition or to check return conditions
    - e.g. assert(ret >= 0) throws an error if ret is not greater than or equal to 0
- **Static Checkers**: Perform static checks as you write your code rather than when you run
  your code
    - e.g. the C and bash linters we have enabled for Neovim
- **Sanitizers**: Dynamic tools that perform their checks at run time as compiler options
    - To enable these sanitizers `-fsanitize=undefined` or `-fsanitize=address` for example
- **Fuzzers**: An input generator that keeps running a function or program in order to detect
  any potential problematic inputs that trigger problems
    - Modern fuzzers have clever strategies to decide on which inputs to test
    - Use `int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)` instead of main to
      utilize libFuzzer
    - Limit the duration of the fuzzer with `./program_name -max_total_time=10`
- **Debuggers**: Grants a powerful set of features suited for all debugging tasks
    - When compiling, use `-g` in the compiler options to signify that you may want to debug
      the program later
    - `cgdb main` to open the program main in the debugger (assuming it was tagged with `-g`)
    - `break 11` puts a program break at line 11
    - `next` lets you run line by line in the current scope, `step` follows execution through
      function calls
    - `print var` to show the value of variable 'var'
    - `watch var` notifies you when the value of 'var' has changed
    - `list` shows about 10 lines where the program is currently stopped.
        - `list main` shows lines from function 'main'
    - `run` runs the program
    - `quit` quits the debugger

## A6: Memory Layout
- The **Memory Layout Table** from top to bottom is:
    - Kernel address space
    - Stack (grows downwards)
    - Memory mapping (grows downwards)
    - Heap (grows upwards)
    - BSS (uninitialized global or static data)
    - Data (initialized global or static data)
    - Text (code)
    - Address 0
- **Pointer Arithmetic**: Incrementing/decrementing pointer values to address nearby address spaces
    - Changes the value of the pointer value by size of the pointer type
        - e.g. `ptr + 1` increments by 4 bytes if 'ptr' is `int *ptr`
    - `address[i]` is the same as `address + i` for `int *address`
- The **Text Segment** contains the compiled code of the program; the OS loads the program
  itself into this segment
- `objdump` prints out what is in an executable, organizing it into sections named
  similarly to those in the memory layout table
- The **BSS** segment contains uninitialized global/static data, while the **Data** segment
  contains the initialized global/static data
    - Since the data segment is lower on the memory layout table, it has a lower address than
      data stored in the bss segment
    - The BSS segment is automatically filled with zeros so we can still initialize the
      uninitialized variables, while at the same time giving them a known and predictable value
- The **Stack** segment is where local variables and function arguments are stored
    - Size changes as functions are called
    - It grows downward, so variables declared first occupy the highest memory address
        - However, in an array, a lower index still means a lower address
    - We can accidentally access other variables through incorrect pointer arithmetic
    - Whenever a function is called, the stack creates a new **Stack Frame** and stores
      everything necessary
        - e.g. main() stack frame -> foo() stack frame with the properties discussed above
          (grows downward)
        - Stack frames also contain function arguments, return address, and a previous frame
          pointer, in that order in memory
        - It is possible to access other stack frames through pointer arithmetic
- Misusing arrays or pointers can affect the return address and the previous frame pointer,
  which can lead to a **stack buffer overflow attack**, where the return address is replaced
  with an address that leads to a malicious piece of code
- Standard library functions like gets() have the potential to overflow the stack
- `getrlimit()` can be used to get the resource limits for a process
    - e.g. available space on the stack

## A7: Memory Layout Pt. 2, Data Types, Alignment
- The **Kernel Address Space** can only be accessed by kernel components and user programs
  cannot access it
    - Will terminate with a segmentation fault if user attempts to access
- The **Memory Mapping** segment is where shared libraries are stored
    - The OS dynamically links the program with shared libraries upon execution
- The **Heap** segment is used when a program calls memory allocation functions like
  `malloc()`, `calloc()`, `realloc()`, and `free()`
    - `malloc()` takes a single argument size, and allocates size bytes of memory on the heap,
      returning void * , a pointer to the block of memory it just allocated
        - Does not initialize the allocated memory
    - `calloc()` takes two arguments, nmemb and size, and allocates an array of nmemb elements,
      where each element is of size bytes. Returns void* like malloc
        - Initializes with 0s
    - `realloc()` takes two arguments, ptr and size, and changes the size of previously
      allocated memory at ptr to size bytes
        - If the new size is bigger than the old size, the newly-allocated portion is uninitialized
    - `free()` takes a single argument, ptr, and frees memory pointed to by ptr
- Using the heap is considered manual memory management, as you need to write code yourself to
  request memory allocation on the heap, as well as to release the memory
- A **memory leak** occurs when you allocate memory on the heap, but don't deallocate it properly
    - This effectively reduces the size of memory usable by the memory allocator for the
      duration of the program
    - `-fsanitize=address` to check for memory leaks
- Some of examples of **memory safety issues** that we've discussed up until this point
  include: stack corruption, buffer overflow, uninitialized variable access, memory leaks, use
  after free, double free, and null pointer dereferences
- **Endianness** determines how we read the bytes in a single type
    - In a **little-endian system**, the least significant byte of a multi-byte value is
      stored at the lowest memory address
        - e.g. if we have 0xBEECAFE -> | 0xBE | 0xEF | 0xCA | 0xFE |
    - In a **big-endian system**, the most significant byte of a multi-byte value is
      stored at the lowest memory address
        - e.g. if we have 0xBEECAFE -> | 0xFE | 0xCA | 0xEF | 0xBE |
    - Only for single types, not composite types like `struct`
- **Memory Alignment** refers to the requirement that certain data types should be stored in
  memory at addresses that are multiples of their size in bytes
    - Violating this can lead to performance penalties or even crashes in some cases
    - `char` can be stored at any address (1 byte)
    - `short` (2 bytes) must be stored at an address that is a multiple of 2
    - `int` and `float` (4 bytes) must be stored at an address that is a multiple of 4
    - `long`, `double`, and any pointer type (8 bytes) should be stored at an address that is a
      multiple of 8
- **Padding** is the process of adding unused bytes to a `struct` to satisfy alignment
  requirements
- **Packing** is the process of eliminating or minimizing padding within a `struct` to reduce
  its size in memory
    - Helps with memory efficiency, however effects performance

