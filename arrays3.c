#include <stdio.h>

void print_float_array(float arr[][3], size_t num_rows){
	for( int i = 0; i < num_rows; i++ ) {
		for( int j = 0; j < 3; j++ ) {
			printf("%p %f\n", &arr[i][j], arr[i][j]);
		}
	}
}

int main() {
//	float arr[2][3] = {{1.0, 2.0, 3.0},{4.0,5.0,6.0}};
//	print_float_array(arr,2);
	printf("%f\n", (float) 1/2);
	return 0;
}
