#include <stdlib.h> // this is needed for malloc
#include <stdio.h>

void b( int x ) { 
	int w=2;
	printf("%d%d\n", x+1,w);
}


void a(int x) {
	int z=1;
	printf("%d%d\n", x,z);
	b(x);
}

int main() {
	int x=42;

	// This creates a contiguous chunk of memory on the stack.
	// It is very hard to resize this chunk. What happens if I want to turn
	// my_array into an array of size 11?
	// This is because my_array could be arranged next to other things in 
	// memory such as the variables x and y and you can't move them.
	// If you want to resize the array, you need to declare a new array that
	// is bigger and copy everything over.
	// If you have an automatic array, they can't be resized because they can't 
	// be moved -- they are on the stack.
	// 
	// The stack is the place in memory where all automatic variables are 
	// stored. The stack is last-in-first-out (LIFO).
	//
	// (top of stack)
	// -------------
	// |    y      |
	// -------------
	// | my_array  |
	// |           |
	// -------------
	// |    x      |
	// -------------
	//
	//  Note that the compiler determines where things are on the stack.
	//  Memory is allocated at the top of the stack (e.g. y) and memory is
	//  freed at the top of the stack.
	//
	int my_array[10]={0};
	int y;

	// Suppose main calls a() and a() calls b(). Inside main, when a() is
	// called the main function's scope is still around. Local variables in
	// main() are not yet freed. Inside a(), it declares a local variable z
	// and then calls b(). b() has a local variable itself called w.
	// At some point, the functions start to end. b() ends first, with its scope
	// cleaned up, then a() ends, with its scope cleaned up, then main() ends,
	// with its scope cleaned up.
	//
	// Every function has a stack frame
	//	A stack frame is a block of memory that stores the automatic variables
	//	created by that function call, along with other information like the
	//	return address in memory.
	// When a function is called, a stack frame is put on the stack. When a 
	// function call ends, the stack frame is popped off the stack in last-in
	// first-out order.
	// There are no gaps in the stack and there are no gaps in the stack frame.
	a(x);

	// The heap is another place in memory where variables can be stored.
	// The heap is not contiguous. Instead, it can be "fragmented". The heap
	// is also not last-in-first-out. Data can be freed from the heap whenever
	// you want.
	// You have the responsibility to remember to free stuff from the heap. It
	// is not freed for you like automatic variables. Failure to remember to
	// free things on the heap results in a memory leak.
	//
	// The heap stores dynamically allocated variables that YOU create and you
	// have to decide when it is freed.
	//
	// To allocate memory on the heap, use malloc() -- remember to include 
	// stdlib.h as a header file
	
	// This dynamically allocates 4 bytes of contiguous memory on the heap,
	// assuming sizeof(int) returns 4 bytes. This marks that memory as allocated
	// and returns a pointer to the base address. Note that the memory on the
	// heap is nameless (unlike variables on the stack). Things on the heap
	// have memory address (i.e. pointers) associated with them.
	//
	int *ptr = malloc(sizeof(int)); // The variable ptr is stored on the stack
	// but the memory that ptr points to is on the heap
	
	// If there is insufficient contiguous memory available, malloc will 
	// return null. 
	if( !ptr ) { // Good programming practice: check if malloc returns NULL
		printf("Error! malloc() failed\n");
		exit(1); // kills the program and returns error code 1
	}
	*ptr = 12; // make sure you initialize the pointer after you malloc it
	printf("%d\n", *ptr);
	return 0;
}
