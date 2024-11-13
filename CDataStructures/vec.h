#include <stdio.h>
#include <stdlib.h>

#ifndef VEC_H
#define VEC_H

typedef struct T_vector {
  size_t size;
  int *data;
} vector;

void initializeVec(vector *vec) { vec->size = 0; }

void resize(vector *vec, size_t size) {
  (vec->data) = (int *)malloc(size * sizeof(int));
  vec->size = size;
}

void push_back(vector *vec, int elem) {
  resize(vec, (vec->size) + 1);
  vec->data[vec->size] = elem;
}

#else
#endif