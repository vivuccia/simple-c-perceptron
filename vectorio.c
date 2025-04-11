#include <stdio.h>
#include <stdlib.h>
#include "vectorio.h"


void readFile(vectors *arr){ // Read vectors.conf for input vectors
	FILE *config;
	config = fopen("vectors.conf", "r");
	if(!config){
		perror("FATAL ERROR! Unable to open vectors.conf. File may be corrupt or nonexistent");
		exit(EXIT_FAILURE);
	}
	vector v;
	while(fscanf(config, " [%lf %lf]", &v.x, &v.y)==2){
		append(arr, v);
	}
	printf("Loaded %zu vectors from vectors.conf \n", arr->size);	
	fclose(config);
}

void initArray(vectors *arr){ // Initialize vectors
	arr->size=0;
	arr->capacity=2;
	arr->data=malloc(arr->capacity*sizeof(vector));
	}

void append(vectors *arr, vector value) { // Append to vectors
	if(arr->size>=arr->capacity){
		arr->capacity = arr->capacity ? arr->capacity * 2 : 2;
		arr->data=realloc(arr->data, arr->capacity*sizeof(vector));
	}
	arr->data[arr->size++] = value;	   
}

void freeArray(vectors *arr){
	free(arr->data);
}

