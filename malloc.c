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

void bad_memory_leak() {
	while(1) {
		int* ptr = malloc(sizeof(int)*1000000);
	}
}

// Resizes array arr to be of size n+1. Note that this frees arr
double* resize_array(double* arr, size_t n) {
	double* new_arr = malloc(sizeof(double)*(n+1));
	for( int i = 0; i < n; i++ ) {
		new_arr[i] = arr[i];
	}
	new_arr[n] = 0.0;
	free(arr); // this frees the memory to the old arra
	return new_arr;
}

// Note that this free arr
double* resize_array2(double *arr, size_t n) {
	double* new_arr = realloc(arr,sizeof(double)*(n+1));
	new_arr[n]=0.0;
	free(arr);
	return new_arr;
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
	//  What happens if you need to move things around on the stack?
	//  1) Allocate new block of bytes
	//  2) Copy data from the old memory location to the newly allocated
	//  memory location
	//  3) Delete the old memory location
	//
	//  The hard part about moving things like this is step 3 because you
	//  need to delete the old memory location and this is hard on a LIFO
	//  stack. It is very hard to access and delete memory locations that
	//  are not the top thing on the stack.
	//
	//  The stack is optimized for:
	//  1) Compactness
	//  2) Performance (e.g. quick access to anything in the stack and cache
	//     locally)
	//  3) Simplicity of interface (just push and pop stack frames. This is
	//     all handled automatically)
	//  The tradeoff is that you lose flexibility e.g. the ability to move
	//  things around on the stack

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
	
	int* ptr = malloc(sizeof(int)); // The variable ptr is stored on the stack
	// but the memory that ptr points to is on the heap
	
	// If there is insufficient contiguous memory available, malloc will 
	// return null. 
	if( !ptr ) { // Good programming practice: check if malloc returns NULL
		printf("Error! malloc() failed\n");
		exit(1); // kills the program and returns error code 1
	}
	*ptr = 12; // make sure you initialize the pointer after you malloc it
	printf("%d\n", *ptr);
	
	// This is how you free dynamically allocated memory. It accepts an arg
	// of the pointer to the memory you want freed. Note that this does not
	// free the ptr variable itself. The free() call frees the dynamically
	// allocated memory that ptr points to. The ptr variable is a local
	// variable on the stack that is automatically cleaned up.
	//
	free(ptr);
	ptr=NULL; // Can NULL out a pointer that you have freed. If you don't
	// NULL out a freed ptr, you have a dangling pointer
	//	*ptr=12; // This is a use-after-free error. Don't do this.
	
	// Run valgrind --leak-check=full --show-leak-kinds=all
	// You can add this line to your ~/.bashrc file in your home root:
	// alias valgrind 'valgrind --leak-check=full --show-leak-kinds=all'
	//
	// Remember to source your ~/.bashrc file
	// If you have a memory leak, valgrind will result in a "in use at
	// exist: 4 bytes in 1 blocks" message and this indicates a memory leak.
	// You can also spot the memory leak because the # of allocs will be more
	// than the # of frees.
	// The category of interest is the "definitely lost" memory, which indicates
	// a memory leak. Valgrind also shows you the line number where it thinks
	// the memory was allocated but it won't show you where to free it.
	//
	// If you forget to free a block of dynamic memory that you allocated,
	// you have a memory leak. Memory leaks are a mistake. Some are not too
	// bad (e.g. a one-off small memory leak) but others can be really bad
	// (e.g. a memory leak in an inner loop) and bog down your computer.
	//
	// Rules about using the stack vs the heap:
	// 1) All dynamically allocated memory must be freed exactly once
	// 2) You must not free it before you are done with it.
	// 3) Make sure the pointer to the dynamically allocated memory is not
	//    lost when the function goes out of scope
	//
	// You can manage things on the heap with pointers. This means you can
	// move things around and resize arrays on the heap.
	int n = 50;
	double* a = malloc(sizeof(double)*n);
	for( int i = 0; i < n; i++ ) {
		a[i] = i;
	}
	double* new_a = resize_array2(a, n);
	for( int i = 0; i < (n+1); i++ ) {
		printf("%f\n", new_a[i]);
	}
	// free(a); // undefined behavior  because a was freed in resize_array
	free(new_a);

	// calloc() is a function that allocates a block of bytes and initializes
	// it to 0. Note that malloc does not initialize things to 0.
	float* floats=calloc(10,sizeof(float)); // initializes to 0 for you
	if( !floats )  {
		// Remember to check if malloc, realloc and calloc return NULL
		printf("Error: Calloc failed\n");
		exit(1);
	}
	for( int i = 0; i < 10; i++ ) {
		printf("Calloc result: %f\n", floats[i]);
	}
	free(floats);

	// The stack is usually much smaller than the heap and a fixed size. Going
	// beyond this size results in a stack overflow.
	// The heap can grow in size until it can't grow any more. The general
	// convention is to put really big things on the heap, not the stack.
	return 0;
}


