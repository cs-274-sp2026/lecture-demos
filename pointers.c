#include <stdio.h>

// Everything in your C program gets stored in memory when it is run.
// This includes variables, functions, structs, etc. and the code
// itself. The computer's memory is simply the place where it stores
// stuff (temporarily) as it is running the program. 
//
// Memory is volatile -- if you turn it off, you lose everything in memory.
// This is in contrast to something that is persistent, which typically requires
// you to save it to disk or a database.
//
// Different memory models are used on a computer (e.g. the stack, the heap, 
// etc.). Memory can be thought of as a gigantic array (see class notes on
// pointers). Each element of this array is 1 byte. The size in bytes of
// a variable is determined by its type. For example, a char is 1 byte. An 
// integer is typically 4 bytes. Other types take up more space.
//
void change_me(int z) {
	z = 100;
}

void change_me2(int *z) {
	*z = 100;
}

int* buggy_function() {
	int z = 42;
	return &z;
}

int main() {
	//int y;
	int x = 3;
	int* addr_of_x = &x;	// This is a pointer variable that stores the
							// memory address of x. Notice that you have
							// to specify what type of pointer this is.
	//int* ptr = NULL;
	
	printf("x = %d\n", x ); // this gives you the value of x
	printf("Address of x = %p\n", &x); // The & gives you the address of x
		 	// %p is a format specifier for memory addresses or pointers
	printf("Address of x = %p\n", addr_of_x);

	// The * notation here means dereference the pointer to get access
	// to what is stored at that address.
	printf("The contents at address addr_of_x is: %d\n", *addr_of_x);

	// If you try to dereference an uninitialized pointer or NULL pointer,
	// it will cause a segmentation fault, which means your program is 
	// accessing
	// memory that it is not supposed to do. Compiling with -Wall will
	// point this out as a warning. Valgrind will also notice this as
	// an invalid memory access.
	// printf("The contents at address ptr is: %d\n", *ptr);

	int z = 2;
    printf("Before function call change_me, z = %d\n", z);
	change_me(z);
	printf("After function call change_me, z=%d\n", z);

	// Call by reference -- you pass the pointer and it changes
	// the value stored at the memory address the pointer points to.
	// Note that you call change_me2 with &z to get the address of z.
	printf("Before function call change_me2, z = %d\n", z);
	change_me2(&z);
	printf("After function call change_me2, z = %d\n", z);

	// This will cause an error. -Wall will pick it up.
	// Don't store pointers to local variables and return them when the
	// function ends. This will produce a segmentation fault when you
	// dereference ptr2.
	
	// The Stack: a special place in memory where automatic variables are
	// stored. Everything on the stack is freed when the scope ends.
	// This means any pointer to an automatic variable will point to 
	// cleaned up memory after the scope ends. Don't use these dangling 
	// pointers. Do not dereference dangling pointers. This will cause
	// a "use after free" error.
	//
	
	//int* ptr2 = buggy_function();
	//printf("Value at ptr: %d\n", *ptr2);
	
	int y = 2;
	//int* p1 = &y;
	//int** p2 = &p1; // This is a pointer to a pointer. It is allowed
	
	// The const keyword indicates the value does not change
	// e.g. const int pi = 3.141; // means this variable cannot be changed
	// Const can be applied to pointers. It can mean 2 different things.
	// 1. Constant pointer: you cannot modify the memory address pointed to
	//    by the pointer.
	//
	
	x = 5;
	int* const const_ptr = &x;
	// const_ptr = &y; // syntax error
	
	printf("x = %d\n", *const_ptr);
	*const_ptr = 42; // This is ok
	printf("x = %d\n", *const_ptr);

	// 2. Constant value pointed at by the pointer: underlying value at the
	//    memory address cannot change.
	//
	
	const int* pointer_to_const = &x;
	//int const* pointer_to_const = &x; // this is allowed and does the same thing
	//*pointer_to_const = 42; // this is a syntax error because you are changing
							// the value through the pointer_to_const variable
	x = 42; // this is ok 
	pointer_to_const = &y; // this is ok
	int* pointer_to_const2 = &x;
	*pointer_to_const2 = 42; // this is ok

	// 3. You can also have a constant pointer to a constant value
	const int* const ptr = &x;
	//ptr = &y; // syntax error
	//*ptr = 42; // syntax error
	

	// You are not allowed to cast const pointers to non-const pointers
	// int* non_const_ptr = (int*)pointer_to_const; // syntax error
}
	
