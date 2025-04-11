#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *data;
	size_t size;
	size_t capacity;
} Array;

void arrayinit(Array *arr){
	arr->size=0;
	arr->capacity=100;
	arr->data = malloc(arr->capacity*sizeof(int));
}

void append(Array *arr, int value){
	if(arr->size==arr->capacity){
		arr->capacity*=2;
		arr->data=realloc(arr->data, arr->capacity*sizeof(int));
	}
	arr->data[arr->size++] = value;
}

void free_array(Array *arr){
	free(arr->data);
}
	
void get_input(Array *arr){ 
	int input;
	while (scanf("%d", &input) == 1) {
        append(arr, input);
    }
}

void printloop(Array *arr){
	int i;
	for(i=0; i<arr->size; ++i){
		printf("Pos: %d, val: %d \t", i, arr->data[i]);
	}
}

int main() {
	Array arr;
	arrayinit(&arr);
	get_input(&arr);
	printloop(&arr);
	printf("\n");
	free_array(&arr);
	return 0;

}
