#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void populate(int** table, size_t rows, size_t cols) {
	for( size_t i = 0; i < rows; i++ ) {
		for( size_t j = 0; j < cols; j++ ) {
			table[i][j] = i*j;
		}
	}
}

void print_table(int** table, size_t rows, size_t cols) {
	for( size_t i=0; i<rows; i++ ) {
		for( size_t j=0; j<cols; j++ ) {
			printf("%u %u %d\n", i, j, table[i][j]);
		}
	}
}

int main() {

	// This is how you declare a 2D array on the stack
	//	int matrix[10][12] = {0};
	size_t n_rows = 10;
	size_t n_cols = 12;

	// this is an example of a dynamically allocated "non-contiguous" 2D array
	int** array = malloc(sizeof(int*) * n_rows);
	for( size_t i = 0; i < n_rows; i++ ) {
		array[i]=malloc(sizeof(int)*n_cols);
	}

	populate(array, n_rows, n_cols);
	print_table(array, n_rows, n_cols);
	
	// Remember to free the individual rows before freeing the array
	for( size_t i = 0; i < n_rows; i++ ) {
		free(array[i]);
	}
	free(array);
	
	// You don't need to have the same number of columns in each row for
	// a dynamically allocated 2D array. This is called a jagged array.
	// You need to keep track of how many columns are in each row for a 
	// jagged array and you need to use another array to store this info.
	// int* num_columns_in_each_row;
	// Then, you have to pass the jagged array and the num_columns_in_each_row
	// array whenever you send the jagged array to a function.
	
	// Traditionally, you use the heap for dynamically allocated multidimensional
	// arrays.
	return 0;
}


