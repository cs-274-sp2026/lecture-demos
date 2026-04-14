#include <stdio.h>
#include <math.h>
#include <stdlib.h> // for exit() call

// Functions have:
// 1. A return type (void in loop demo indicates it has no return value)
// 2. Name (loopdemo in this example)
// 3. Arguments / parameters (this would be N in this example)

void loopdemo(int N); // this is a function prototype. It allows you to use
					  // this function anywhere in the file

// A void parameter means it takes no parameters
void blah(void) {
	loopdemo(10);
}

void loopdemo(int N) {
	for( int i = 0; i < N; i++ ) {
		printf("i = %d\n", i);
		break; // exits the loop here
	}

	for( int j = 0; j < N; j++ ) {
		if( j != 5 ) {
			printf("j = %d\n", j);
		} else {
			continue; // The continue command goes to the
			// next iteration of the loop and skips the rest
			// of the loop body below it.
		}
		printf("Test for continue\n");
	}
}

void switch_example() {
	int x = 5;
	/* This if statement is equivalent  to the switch statement below
	if ( x == 0 ) {
		printf("A\n");
	} else if ( x == 1 ) {
		printf("B\n");
	} else {
		printf("Error\n");
	}
	*/

	switch(x) {
		case 0:
			printf("A\n");
			break;			
		case 1: 
			printf("B\n");
			break;
		default:
			printf("Error\n");
			break;
	}
}

double volume_of_sphere(double radius) {
	radius = 1.0;
	
	// Remember to include math.h at the top
	// Remember to compile with -lm which links in the math library
	double volume = 4.0 / 3.0 * 3.142 * pow(radius,3);
	printf("Radius in inner scope: %f\n", radius);
	return volume;
}

//Recursive function
int factorial(int n) {
	if( n < 0 ) {
		printf("Error, n needs to be > 0\n");
		exit(-1);
		// return 0; // be careful -- need to make sure you see the error printed 
	} else if((n == 0) || ( n == 1 )) {
		return 1;
	} else {
		return n * factorial(n-1);
	}
}

// Functions can have more than one argument
// But functions cannot have more than one return value
void foo(int x, int y) {
	printf("%d %d\n", x, y );
}

int main() {
	double radius= 2.0;
	double volume = volume_of_sphere(radius);
	printf("Radius: %f\n", radius);

	// The return value for volume_of_sphere is forgotten after 
	// calling the function unless you store it in a variable
	printf("Volume = %f\n", volume_of_sphere(radius));
	printf("Volume = %f\n", volume);
	foo(1,2);
	//loopdemo(2);
	printf("Factorial result: %d\n", factorial(3));
	return 0;
}
