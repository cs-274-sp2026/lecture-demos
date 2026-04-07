#include <stdio.h>
#include <math.h> // needed for pow()

int main() {
	// gcc is a build tool for C. It does several things:
	// 1. It preprocesses the C source code
	// 2. It then compiles the source code into object code
	// 3. It links together the object files necessary for the executable


	// The main function is the entrypoint for the program. Every C
	// program must have exactly one main() function. The return is an
	// int. Typically, returning 0 means everything is ok. Any other
	// return code is typically indicative of an error.
	
	/* This is an example of a 
	 * multi-line
	 * comment
	 */

	// The first argument is called the format string.
	// The next arguments to printf (if needed) are called format specifiers.
	// %s: is for strings
	// %d: is for integers
	// %f: is for floats
	//

	// Types:
	// int: integer
	// long: long integer 
	// float: floating point number
	// double: double precision floating point number
	// char: character (1 byte typically). It is usually a value from -128 
	//		 to 127 

	// Literals
	//
	// int: 42, 1, 0
	// double: 3.1412, 2.78
	// float: 3.14f, -5.7f
	// char: 'a'
	//
	// Operators
	// +: Addition
	// -: Subtraction
	// *: Multiplication
	// /: Division - will truncate the decimal part if the denominator is an int
	// %: Mod operator - returns the remainder
	// pow(2,5): 2 raised to the 5th power
	//
	// Implicit Casting / Type Coercion
	// If you are casting a float or double to an int, the conversion rule is
	// truncation
	// If you are casting an int or long int to a float or double, the
	// conversion rule is tack on .0
	//
	int x = 42+14;
	int y = 2*4;
	int z = pow(2,5);


	float w = 5 / (float)2; // This is an example of an explicit cast
	// Explicit type casting is where you explicitly / intentionally
	// convert an expression of one type to a new expression of another 
	// compatible type

	int m = 7 % 2;

	printf("x = %d, y = %d, z = %d, w = %f, m = %d\n", x, y, z, w, m) ;
	printf("Hello, %s world! %d %2.4f\n", "woohoo!", 42, 3.1412 );
	fflush(stdout);

	// When you declare a constant, you must add the const keyword at the
	// beginning and you must initialize it
	const float PI = 3.141;
	
	float f1 = 0;
	float f2 = 0;
	scanf("%f %f", &f1, &f2);
	printf("The values are %f %f\n", f1, f2); 

	// Relational operators allow you to do comparisons
	// Examples: >, <, ==, >=, <=, !=
	//
	// Logical operators:
	// 1) || (logical OR with short circuiting)
	// 2) && (logical AND with short circuiting)
	//
	// There are bitwise operators | and &. Don't confuse them
	// with the logical operators
	
	int x = 1;
	int y = 0;
	if(( x == 1 ) && ( y == 0)) {
		// if the condition is true, go here
		printf("True condition hit\n");
	} else if (( x == 1) && ( y > 2)) {
		// else if condition
		printf("Else if condition hit\n");
	} else {
		// else condition
		printf("Else condition hit\n");
	}
}
