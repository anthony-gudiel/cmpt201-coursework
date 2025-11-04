# Synchronization

- **Synchronization** refers to coordinating the execution among different threads
- Data races are hard because they don't always occur, some may be rare
    - Therefore we need to reason about multiple threads at once
- What looks like one operation may actually be a number of sub-operations
    - Use a **mutex** to avoid the mix up of sub-operations
        - Mutual exclusion
- Lock mechanisms consist of:
    - Define the lock variable to create a lock
    - `lock()` function that grabs a lock
    - `unlock()` function that releases a lock
- Locks guarantee that only a single thread can hold a lock
- Trying to lock using a lock that is already in use causes the function to wait until the lock
  is available
    - `lock()` blocks the thread until mutex is free
- Mutexes are local to the process
- `pthread_mutex_lock(&mutex)` will:
    - Locks the mutex and returns immediately if the mutex is free
    - Blocks, then locks the mutex and returns once it is free
- Even if multiple locks happen at once, only a single thread will hold the lock
    - We cannot control which thread grabs the lock first, giving us non-deterministic
      behaviour

## Lock Usage
- **Atomic**: multiple operations run as if they are a single operation
- Locks effectively serialize operations
    - Only one thread at a time can run operations guarded by a lock
- We can have a data race when threads share a variable:
    - Accessing same global variable
    - Accessing same memory via a pointer
- Data race may be from one piece of code
- Data race may be from different sections of code, each using the same lock/variable
- We can use multiple locks to protect independent shared variables
    - Creating independent locks reduces **lock contention**
- `pthread_mutex_trylock()` returns immediately if unable to lock
    - No hang, doesn't wait for unlock

## Critical Section and Thread Safety
- The **Critical Section** is a piece of code that accesses a shared variable
    - and must not be concurrently executed by more than one thread
- Ideal solution for CS problem satisfies:
    - **Mutual Exclusion**: only one thread should be allowed to run in the CS
    - **Progress**: a thread should eventually complete/make progress in its task
    - **Bounded Waiting**: an upper bound must exist for the amount of time a thread waits to
      enter the critical section
        - Should only be blocked for a specified amount of time

## Condition Variables
- Producers are a set of threads creating data, consumers are a set of threads using the data
    - The shared resource is what we need to protect
- A **condition variable** is used to signal a change in state
    - One thread sends notification to condition variable, other waits for the notification
        - While waiting, the thread sleeps
- We expect the processing of a value to occur inside of a mutex
- `pthread_cond_wait()` to wait on a condition variable
    - Internally it will atomically release the mutex and wait for the condition variable
    - Once signalled, wakes up and grabs the mutex
    - Don't sleep while holding a lock, as that would block others from accessing the resource
- `pthread_cond_signal()` to wake up one of the threads waiting on cond
    - If nobody is waiting, the signal is lost
- `pthread_cond_broadcast()` will wake up all threads waiting on cond
    - All threads compete for the lock on wake up
        - Everyone will eventually get the lock, but we don't know in which order
- If any of the waiting threads are sufficient to process the event use `pthread_cond_signal()`
- If all of the waiting threads need to respond to an event use `pthread_cond_broadcast()`
- **Condition Variable Predicate**: consumer only waits if there's no data to process
    - Must recheck the predicate after we're signalled, as another thread may have consumed the data
      first

## Semaphores
- A **semaphore** is a lock with a count
    - Indicates the availability as a number/count
        - Whereas a lock is either available or not available (binary)
    - If the count is 0, it means the semaphore is unavailable
    - If the count is > 0, it means the semaphore is available
- `sem_t sem` to create semaphore named sem
- `sem_int()` to initialize the semaphore
- `sem_wait()` to acquire one of the semaphore's count
    - Doesn't guarantee mutual exclusion, instead counts the availability of a resource
- `sem_post()` to count-up the semaphore
    - Like releasing a resource

## Read-Write Lock
- Allows either unlimited readers, or one writer, not both at the same time

## Dining Philosophers
- Each fork is a resource shared by two adjacent philosophers
    - Each thread is a philosopher, a fork is a shared resource that only one should access at a
      time
- One big lock: use one mutex to guard all forks and control access
    - Avoids deadlock, but only one philosopher can eat at a time
- One lock per fork: have all threads grab their right fork, then left
    - Deadlock, circular wait
    - Solution 1: have a philosopher grab forks in a different order
        - Breaks circular wait
    - Solution 2: try grabbing both locks at once
        - Grab the left, try the right, if you can't grab it, release right
        - Could lead to livelock

## Bounded Buffer
- Producer threads that place items into the buffer must wait if the buffer is full
- Consumer threads take items from the buffer, and must wait if the buffer is empty
- Works as a queue, wrap-around to index 0
- Mutex + Condition Variable is inefficient because all threads need to compete and check for
  availability
