#include "carena.h"
#include <stdint.h>
#include <stdlib.h> 


arena* arena_init(size_t capacity){
	arena* a = (arena*)malloc(sizeof(arena)+capacity);
	if(!a)	return NULL;
	a->memory = (uint8_t*)(a + 1);
	a->capacity = capacity; 
	a->offset = 0;
	return a;
}

void arena_free(arena* a){
	if(!a)	return;
	free(a);
}

void arena_reset(arena* a){
	if(!a)	return; 
	a->offset = 0;
}

void* arena_alloc(arena* a, size_t size){
	if(!a || !a->memory)	return NULL;
	size_t alignment = ALIGNMENT;
	uintptr_t current_ptr = (uintptr_t)(a->memory + a->offset);
	uintptr_t padding = 0; 
	uintptr_t modulo = current_ptr & (alignment - 1);
	if(modulo != 0)
		padding = alignment - modulo; 
	if((a->offset + padding + size) > a->capacity)
		return NULL; 
	a->offset += padding; 
	void* ptr = &a->memory[a->offset];
	a->offset += size; 
	return ptr;
}
