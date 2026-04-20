```
 / __/ _` | '__/ _ \ '_ \ / _` |
| (_| (_| | | |  __/ | | | (_| |
 \___\__,_|_|  \___|_| |_|\__,_|
```
`carena` is a general purpose arena allocator for C / C++.

The initial design of the allocator is one of a single block of memory within which all objects are allocated. The user must know how much memory is needed beforehand. The upsides of this are that cache locality is pretty much guaranteed, and that the implementation is much simpler compared to a linked list based growth.










### Theory
An arena allocator is a memory management system which allocates a single large contiguous block of memory at the start of the program, and dynamically allocated objects are created by simply advancing a pointer through that block. The downside is that there can be no individual per-object deallocations. The memory pool is deallocated when it is no longer useful.

The upside though, is that individual allocations are extremely fast, and are O(1) pointer increments. The lack of individual deallocations means that there is no memory fragmentation within the pool, and similar objects being allocated within the same pool means that there is excellent cache locality.
