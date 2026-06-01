```
 / __/ _` | '__/ _ \ '_ \ / _` |
| (_| (_| | | |  __/ | | | (_| |
 \___\__,_|_|  \___|_| |_|\__,_|
```
`carena` is a general purpose arena allocator for C / C++.

### What an arena allocator is 
An arena allocator is a memory management strategy where:
-   A large contiguous block of memory is allocated upfront (The "arena")
-   Individual allocations are made by simply advancing a pointer through that block. 
-   There is no per-object deallocation. Memory is freed al at once by resetting or destroying the entire arena. 

The key advantages are: 
1.  Allocation of objects is extremely fast. 
2.  Zero fragmentation within the arena 
3.  Simple implementation. 
4.  Since the allocations are contiguous, objects in the arena have great cache locality.
