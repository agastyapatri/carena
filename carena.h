/*
Copyright 2026 Agastya Patri 

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/



#ifndef CARENA_H
#define CARENA_H
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern  "C" {
#endif


#define KiB(size) ((size)    * 1024)	
#define MiB(size) (KiB(size) * 1024)	
#define GiB(size) (MiB(size) * 1024)

typedef struct arena arena;

struct arena{
	void* memory; 
	size_t capacity; 
	size_t offset;
};

arena* arena_init(size_t size);           //	allocates the block
void arena_alloc(arena* a, size_t size);  //	bump pointer + alignment
void arena_reset(arena* a);               //	rewind the offset to 0
void arena_free(arena* a);                //	free the underlying memory 


#ifdef __cplusplus
}
#endif

#endif /* ifndef CARENA_H */

