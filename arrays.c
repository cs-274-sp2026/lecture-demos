#include <stdio.h>

// An array is a: 1) contiguous, 2) homogenous and 3) fixed-sized sequence
// of elements of a given type.
// 1) Contiguous: it is a sequential (uninterrupted) chunk of memory where each 
//    slot in the chunk of memory is next to each other.
// 2) Homogenous: everything is the same type
// 3) Sequence: every element is at an address that is next to the previous one.
//
// When you create an array  in C, the size should be a compile-time constant
// i.e. not a variable
// Don't do the following (will have undefined behavior):
//   int size=10;
//   int arr[size];
// Instead, use a constant value e.g.
//   int arr[10];

// size_t stores the size of things.
// The line below is equivalent to the print_numbers function declaration
// void print_numbers(int* numbers, size_t n)
void print_numbers(int numbers[], size_t n) {
	for( int i = 0; i < n; i++ ) {
		printf("%d\n", numbers[i]);
	}
	printf("\n");
	numbers[2] = 42; // changes the memory address here. Equivalent to
		// passing in a pointer to the numbers array
}

int main() {
	int arr[5]={1,1,1}; // initializes first 3 elements to 1
						// initializes the rest to be 0
	int b[1000] = {0}; // initializes everything to be 0
						// Extra elements are assigned to have value 0
	char c[3] = {0};	// Assigns the null terminator here

	// Assigns values to different slots in the array
	arr[0] = 10; // Assign 10 to the 1st slot in the array, which has index=0
	arr[1] = 8;
	arr[2] = 3; // note that the last index is 3-1 = 2. 

	// An array of size N has indices from 0 to N-1
	
	// Don't go beyond index N-1. Undefined behavior.
	// arr[30] = 100;
	//printf("%d\n", arr[3]);
	
	for( int i = 0; i < 5; i++ ) {
		printf("%d\n", arr[i]);
	}
	for( int i = 0; i < 3; i++ ) {
		printf("Char c = %c\n", c[i]);
	}

	// The base address is the memory address of the first element in the array.
	// You can always use an array like a pointer to the base address
	c[0] = 'c';
	c[1] = 'a';
	c[2] = 't';
	

	char* base = &c[0];
	printf("base[0] = %c\n", base[0]);

	// To access an element at index i, you start with the base address
	// and add i * (sizeof(element)) i.e.
	// Address at index i = base + i * (sizeof(element))
	// This is how the square brackets are converted to a memory address.
	
	printf("Element at index 2 = %c, %c\n", c[2], *(base+2));

	//sizeof operator that gives you the number of bytes of a type
	// sizeof(int) will return 4 bytes on the ENGR system
	printf("%ld\n", sizeof(int));
	printf("%ld\n", sizeof(char));
	printf("%ld\n", sizeof(char*));

	// The sizeof operator can be given an expression like sizeof(1+1)
	// It will not evaluate the result of the expression but it will return
	// the size of the resulting type
	printf("%ld\n", sizeof(1+1));
	
	int i = 3;
	printf("%ld\n", sizeof(i++));
	printf("Value of i: %d\n", i); // sizeof does not increment i, so this prints 3
	
	// sizeof returns the size in bytes of your array if you pass an array
	// as an argument
	printf("size of array c: %ld\n", sizeof(c));
	printf("size of array arr: %ld\n", sizeof(arr));

	//char* str = "Hello";
	//str[0] = 'J'; // results in a compile error because str is read-only
	//printf("%s\n", str);
	char modifiable_str[6] = "Hello";
	modifiable_str[0] = 'J';
	printf("%s\n", modifiable_str);
	printf("%s\n", modifiable_str+1); // moves to 1 element width plus base
	// Note that for strings, the pointer in the printf above does not need
	// to point to the base address. It can point to the address of any element
	// in the string to print out a substring
	printf("%s\n", modifiable_str+3);
	
	
	// Recall that an array of size N has indices from 0 to N-1.
	// If you read beyond the bounds of an array, you get a buffer over-read.
	// If you write beyond the bounds of an array, you get a buffer overflow.
	// Why do over-reads and overflows happen? C arrays are not stored with
	// their size. They rely on finding the null terminator for a string.
	// Buffer over-reads can allow a hacker to read a part of memory they
	// aren't supposed to reach (see heartbleed and mongobleed exploits).
	// Buffer overflows allow a hacker to overwrite a part of memory they aren't
	// supposed to reach and then jump to it and execute it. This is called
	// an Arbitrary Code Execution (ACE) exploit.
	//	 For example, the stack is a place in memory where you store a bunch
	//	 of things like local variables, return values, return addresses, etc.
	//	 Could overwrite the return address to go to a different part of memory
	//	 and execute the bytes in memory there. 
	// Compiler does not catch buffer over-reads and overflows.
	// Valgrind can catch some of them -- but only when it actually happens
	// at runtime.
	
	print_numbers(arr, 5);	// will change arr[2] to be 42
	print_numbers(arr, 5);
	return 0;
}
