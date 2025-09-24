# Quiz 1 Review

## A0: Linux Terminal
### Linux Ideas and Commands
- **ls**: lists the items in the current directory or the specified directory
    - **-a**: argument to specify show all, including hidden directories and files
    - **-l**: argument to specify long format, displaying detailed info like files types and
      permissions, owner name, file name, last modified date/time
- **pwd**: prints the directory you're currently in (**P**rint **W**orking **D**irectory)
- **cd**: change to the specified directory (**C**hange **D**irectory)
- **~**: refers to the home directory
- **.**: refers to the current directory
- **..**: refers to the parent directory of the current directory
- **man**: provides a page of instructions on how to use the specified function/command
    -**/**: used to search for a particular term within the man page
    - **n**: navigates to the next page
    - **q**: quits the man page
- **mkdir**: creates a directory
    - **rmdir**: removes an empty directory
- **touch**: used to create a new file, or update the 'last modified' timestamp associated to the
  file
- **cp**: copy file/directory
- **mv**: move file/directory
- **rm**: remove file
    - **rm -r**: remove recursively, can be used to remove directories
- **cat**: shows the contents of a file in the terminal
- **less**: similar to cat, but let's you scroll up and down instead of displaying everything at
  once
- **chmod**: used to change file permissions
    - user (u), group (g), others (o), all (a)
    - read (r), write (w), execute (x)
    `chmod u+x filename` or `chmod o-x filename`
- **head**: prints the first 10 lines of a file to the terminal
    **head -x**: prints the first *x* lines of a file to the terminal
- **tail/tail -x**: prints the last 10 lines of a file to the terminal by default, or *x* lines if
  specified
- **sort**: sorts the contents of a file alphabetically
- **nl**: nl prints the files content, with line numbers added at the start of each line
- **wc**: prints the word count of the provided file
   - **-l**: counts lines
   - **-w**: counts words
   - **-c**: counts bytes/characters
   - **-m**: similar to -c, but handles multi-byte characters
- **top**: used to show running processes and system stats in real time
- **ps**: shows the process status of a currently running process (snapshot, not live)
- **kill**: used to terminate a process via process ID
- **sleep**: pauses a command or script for however many seconds are specified
- **fg**: brings a job to the foreground
- **&**: starts a job in the background

### Regular Expressions
- **egrep**: used to search text using regular expressions
    - **.**: matches to any single character except newline
    - **[abc]**: matches to any one character inside the brackets
    - **[^abc]**: matches to any one character NOT inside the brackets
    - **[a-z]**: matches to any one character in the range specified
    - **^**: indicates the beginning of a line
    - **$**: indicates the end of a line
    - **{n}**: specifies exactly how many times the preceding element should appear
        - **{n, m}**: should appear at least *n* times, at most *m* times
    - **+**: matches to one or more of the preceding element
    - * : matches to 0 or more of the preceding element
    `egrep "pattern" filename`

### Piping and Redirecting
- **stdin (0)**: standard input; where the program reads input from
    - keyboard is the default
- **stdout (1)**: standard output; where the program sends normal output
    - goes to the terminal by default
- **stderr (2)**: standard error; where the programs sends error messages
    - goes to the terminal by default
- **>**: redirects operators in the shell, controls where input comes from and where output goes
    - overwrites file
    `echo "Hello" > file.txt`
- **>>**: redirects stdout to a file
    - appends to file
    `echo "Hello" >> file.txt`
- **<**: redirects stdin from a file
    `cat < file.txt`
- **2>**: redirects stderr to a file
    `ls missingfile 2> error.txt`
- **|**: pipes commands together; passes result of one command to the next

## A1: Neovim
- **q**: quits the editor if you haven't made any changes, error if you have unsaved changes
    - **q!**: force quit
- **w**: goes to the beginning of the next word
- **b**: goes to the beginning of the previous word
- **A**: inserts at the end of the line
- **U**: undoes all changes on the current line
- **{** and **}**: used to navigate between paragraphs
    - goes to the beginning of the paragraph

## A2: Bash Scripting
- **shebang (#!/bin/bash)**: the first line in a script that tells the system which interpreter to
  use
    - tells the system to use bash
- **#**: used to comment
- **$#**: gives the number of arguments passed to the script
- **$n**: gives the *nth* argument passed to the script
- **variable assignment**:
    `name="Anthony"`
- **accessing variables**:
    `echo "My name is $name`
- **RANDOM**: gives a random number between 0 and 32767
- **read**: waits for the user input and stores it in a variable
    `echo "Enter your name:"
    read name
    echo "Hello $name!"`
- **grep**: searches for lines containing whatever is specified in the regular expression
- **v=$( ls | wc)**: stores the output of `ls | wc` into `v`
- **cat /dev/stdin | sort**: reads whatever is typed by the user, then sorts it alphabetically

### Math
- `let "a = 5 + 4"` sets a to 9
    - `let a=5+4` also works
- `let a++` increments a by 1
- `b = $(( 5 + 4))` is another way to do arithmetic, and sets b to 9
- `((b++))` increments b by 1
- `c=$(( count % 2 == 0))` calculates a boolean expression

### Branching and Logic
- **if statement syntax**:
    - -gt, -lt, -eq, &&, ||, else, elif
    - -n checks if a string is non-empty

    `if [$a -gt 100];
    then
        ...
    elif [...];
    then
        ...
    else
    fi`

- **while loop syntax**:

    `while [condition];
    do
        ...
    done

- **for loop syntax**:

    `for item in list;
    do
        ...
    done`

    OR

    `for i in {1...5};
    do
        ...
    done`

## A3: Compilation
- **pre-processing**: handles directives that start with #, like `#include` or `#define`
    - `#include <stdio.h>` imports the source code from stdio.h
    - outputs modified source file
- **compiling**: converts the pre-processed source code into assembly or machine code
    - checks for syntax and type errors, outputs object file (.o)
- **linking**: combines object files and libraries into a single executable
    - outputs the final executable you can run
- **clang**:
    `clang example.c -o example` compiles example.c into an executable named example
    `clang file1.c file2.c -o program` compiles file1.c and file2.c into an executable named
    program
    `clang main.c -L/user/local/lib -o program` tells the linker where to look for libraries
    `clang main.c -L/user/local/lib -lmylib -o program` links against a library without writing the
    `clang file1.o file2.o -o myprogram` converts the object files into an executable

- **static library**: `.a` or `.lib` extension, linked at compile time
    - the code from the library is copied into the executable, resulting in a larger executable
- **shared/dynamic library**: `.so` extension, linked at runtime (e.g. libpthread.so.0)
    - executable contains reference to the library instead of actually copying its contents
- **ar**: used to create, modify, and extract from static libraries (.a)
    `ar rcs libmylib.a file1.o file2.o`
        - **r**: inserts files into the archive
        - **c**: creates the archive if it doesn't exist
        - **s**: writes an index for faster linking
- **LD_LIBRARY_PATH**: is an environment variable that tells the linker where to look for shared
  libraries (.so) at runtime
    `export LD_LIBRARY_PATH=/home/user/mylibs:$LD_LIBRARY_PATH`
- **-g**: generates debugging information
- **-Wall**: enables common warnings
- **-Wextra**: enables additional warnings beyond wall
- **-Weverything**: enables all warnings
- **-Werror**: treat all warnings as errors
- **fsanitize=<type>**: enables runtime checks for specific bugs
    - e.g. `fsanitize=address` or `fsanitize=undefined`
- **-01**: enables some optimization, faster compilation
- **-02**: enables more aggressive optimization
- **-03**: enables max optimization, may increase file size
- **-I<dir>**: adds a directory to search for header files
    `clang -I./include main.c -o program` compiler looks in ./include for #include files

## A4: Make and CMake
### Make
- **modern build system**: a tool that automates the process of turning source code into a final
  executable or library
- **target: prereq1 ... prereqn**:
    - target is what we want to make
    - prereqs are files that, if they've been modified more recently than the target, will cauase
      the target to be remade
        - Or if they don't exist yet
- **make**: runs the first target
- **clean**: removes files created during the build process
- **make all**: runs the target named all
- **$@**: outputs the target
- **$?**: outputs prereqs newer than the target
- **$^**: outputs all prereqs
- **$<**: outputs the first prereq
- **variable assignment**: `files = file1 file2`
- **accessing variables**: `program: $(files)`
- * **wildcard**: matches any string of characters in file names
    e.g. `SRC = $(wildcard *.c)` matches to all .c files in the current directory
- **% wildcard**: used in pattern rules to match file names
    e.g. `%.o: %.c` matches the base name

### CMake
- **CMakeLists.txt**: describes the project; three essential components
    - `cmake_minimum_required(...)` ensures the project is built with an appropriate CMake version
    - `project(...)` names the project; can optionally set languages
    - `add_executable(myprogram main.c utils.c)` tells CMake what to build
        - add_executable creates an executable
- **include_directories**: tells CMake where to find header files
    `include_directories(include)`
- **file(GLOB <variable name> <wildcard expression>)**: allows us to use a wildcard expression to
  get a list of files and store it in a variable
    e.g. `file(GLOB SOURCES "src/* .c")` will make a list of all .c files under src/ and store it in
    SOURCES -> `add_executable(program ${SOURCES})`
- **build/**: is used to separate sources files from build files (makefiles)
    `mkdir build` -> `cd build` -> `cmake ..` -> `make` OR from the root directory:
    `cmake -S . -B build` -> `cmake --build build`
- **CMake**: generates makefiles
- **Make**: compiles and links according to those makefiles
