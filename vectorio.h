#ifndef VECTORIO_H
#define VECTORIO_H


typedef struct { // Define individual vectors	
	double x, y;
	} vector;

typedef struct { // Define array of vectors as struct
	vector *data;
	size_t size;
	size_t capacity;
	} vectors; 

void initArray(vectors *arr);
void append(vectors *arr, vector value);
void readFile(vectors *arr);
void freeArray(vectors *arr);

#endif
