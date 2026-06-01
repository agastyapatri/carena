#include <stdio.h> 
#include <stdlib.h> 
#include "carena.h"
#define ROWS 10 
#define COLS 10 

typedef struct matrix{
	size_t rows, cols; 
	double* data; 
}matrix;

matrix* arena_alloc_matrix (arena* a, size_t rows, size_t cols);
matrix* malloc_matrix(size_t rows, size_t cols);


int main(){
	arena* a = arena_init(MiB(10));
	matrix* m = arena_alloc_matrix(a, ROWS, COLS);
	matrix* n = malloc_matrix(ROWS, COLS);
	arena_free(a);
	return 0;
}



matrix* arena_alloc_matrix (arena* a, size_t rows, size_t cols){
	matrix* m = (matrix*)arena_alloc(a, sizeof(matrix));
	if(!m)	return NULL; 
	m->rows = rows; 
	m->cols = cols; 
	m->data = (double*)arena_alloc(a, rows*cols*sizeof(double));
	if(!m->data) return NULL;
	return m;
}


matrix* malloc_matrix(size_t rows, size_t cols){
	matrix* m = (matrix*)malloc(sizeof(matrix));
	if(!m)	return NULL; 
	m->rows = rows; 
	m->cols = cols; 
	m->data = (double*)malloc(rows*cols*sizeof(double));
	if(!m->data) return NULL;

	return m;
}
