# Scheduling

- Even though CPUs today have many cores, there are still many more processes than cores
    - How do we get these jobs to run in parallel
        - Job: a process, task, thread, etc.

## CPU Scheduling
- **CPU Scheduling** is sharing a core by multiple processes
- A **Context Switch** is when we stop running one process and start running another
    - Doesn't end the process, more of a pause. Can be resumed exactly where it left off
- The **Ready Queue** is a queue of processes that are waiting for some CPU time
    - Linked list in memory
- **Scheduling** is picking one process to run next from the ready queue(s)
