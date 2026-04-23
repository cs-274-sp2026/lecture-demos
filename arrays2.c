#include <stdio.h>
#include <string.h>

void copyarray(float vals[], float vals2[], size_t n) {
	//To copy an array, you need to copy each individual element over
	for( int i = 0; i < n; i++ ) {
		vals2[i] = vals[i];
	}
}

// You can also pass multidimensional arrays as arguments to functions
// You can omit the size of the first dimension only
// All four of these are fine:
void function1(float vals[2][3], size_t num_rows, size_t num_cols) {
//void function1(float vals[][3]), size_t num_rows, size_t num_cols) {
//void function1(float* vals[3], size_t num_rows, size_t num_cols) {
//void function1(float** vals, size_t num_rows, size_t num_cols) {
	// Do stuff in here
}

int main() {
	float vals[] = {3.0, 5.0, 7.0, 9.0};
	float vals2[4];

	// copyarray(vals, vals2, 4);
	
	// Need to include string.h for memcpy
	memcpy(vals2, vals, 4 * sizeof(float));
	printf("%f\n", vals2[0]);

	// 2-dimensional arrays are like tables with rows and columns.
	// ------------
	// | 1 | 2 | 3|
	// ------------
	// | 4 | 5 | 6|
	// ------------
	// This is an example of a 2D array with 2 rows and 3 columns
	// Could store this in memory in row major order:
	// 1 2 3 4 5 6 
	// Or you could store this in memory in column major order:
	// 1 4 2 5 3 6
	// This is handled by the compiler
	// Your responsibility is to declare the array and use it correctly.
	
	// There are 2 slots in the 1st dimension (2 rows)
	// There are 3 slots in the 2nd dimension (3 columns)
	// float my_matrix[2][3]={{0,1,2}, {3,4,5}}; 
	
	// This will initialize row 0, col 0 to 0, row 0, col 1 to 1.0 and all
	// other values to 0.0
	// float my_matrix[2][3] = {{0.0,1.0}};

	// This will compile. You can specify the size of all dimensions
	// except the 1st one
	float my_matrix[][3] = {{0,1,2}, {3,4,5}};
	
	// This will not compile
	// float my_matrix[2][] = {{0,1,2}, {3,4,5}};

	// This will also not compile
	// float my_matrix[][]={{0,1,2}, {3,4,5}};

	// How do I print this in row-major order?
	for( int i = 0; i < 2; i++ ) {
		for( int j = 0; j < 3; j++ ) {
			// '\t' is the tab character
			printf("%f\t", my_matrix[i][j]);
		}
		printf("\n");
	}

	// How do I print this in column-major order?
	for( int j = 0; j < 3; j++ ) {
		for( int i = 0; i < 2; i++ ) {
			//printf("%f\t", my_matrix[i][j]);
		}
		//printf("\n");
	}
	return 0;

	// In 1D arrays, memory access with the index i e.g. a[i] is calculated
	// as the base address (which is the address of the first element) plus 
	// index i * (size in bytes of each element).
	//
	// For 2D arrays, the compiler will know if the array is stored in row
	// or column major order. Given this information, you can still figure
	// out the memory address for an element at row = i, col = j.
	//
	// Assume for now we are storing things in row major order.
	// The base address is the element at row = 0, col = 0.
	// To figure out what the address of the first element in the next row, you
	// need to know how big each element is and how many are in a row.
	// = number of elements in a row * sizeof(type of element).
	//
	// This is called the "stride" of the first dimension i.e. how many
	// bytes it takes to go from matrix2[i][j] to matrix2[i+1][j]
	//
	// We can also calculate the "stride" of the 2nd dimension i.e. how many
	// bytes it takes to go from matrix2[i][j] to matrix2[i][j+1]
	//
	// Recall: float my_matrix[2][3];
	// Assume each float is 4 bytes
	//
	// To get the memory address of element at row = i and column = j:
	//
	// base address + i * (number of elements in a row ) * (size of each 
	// element) + j * (size of each element)
	//
	// Example:
	// 1) To access element at row index = 2, column index = 2, if base address
	// is 0:
	// 0 + 2(3)(4) + 2(4) = 32
	//
	// 2) To access element at row index = 1, column index = 2, if base address
	// is 0:
	// 0 + 1(3)(4) + 2(4) = 12 + 8 = 20
	int matrix2[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

}
