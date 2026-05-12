#include <stdio.h>
#include <stdlib.h>

int main() {
	float f1 = 0.0;
	float f2 = 0.0;
	// scanf("%f", &f1); // reads the first one "word" that the user 
	// types in and leaves the 2nd "word" in the buffer if the user
	// types in something like 4.0 8.1. In this case, 8.1 sticks around
	// in the buffer
	//printf("%f\n", f1);

	// If you want better control over whitespace in input, use getline()
	char* line = NULL; // must be initialized to NULL. Will be modified to the
						// line read
	size_t n = 0; // size in bytes of the line read. Will be modified by getline

	// 1st argument: a pointer to a pointer to a char
	// 2nd argument: a pointer to size_t var for the size of the line read
	// 3rd argument: the input stream (stdin in this case which is the input
	// from the terminal)
	// getline() will dynamically allocate an array on the heap to store
	// the line typed in by the user and adds a null terminator for the string.
	//
	// Returns the length of the C string without the NULL terminator. This is
	// If getline fails, it returns -1 (e.g. if you don't have enough memory
	// on the heap)
	//
	size_t len = getline(&line, &n, stdin);
	if( len == -1 ) {
		printf("Error on getline\n");
		exit(1);
	}
	
	// One option to get rid of extra newline:
	// line[len-1]='\0'; // You can do this on some architectures
	
	// A better but clumsier way to get rid of the extra newline:
	if( line[len-1] == '\n') {
		line[len-1] = '\0';
	}
	if( line[len-2] == '\r') {
		line[len-2] = '\0';
	}
	printf("%s\n", line); // Another option: could remove the \n to avoid 2 
						  // newlines
	free(line); // remember to free this!

	// Another option for the line variable (1st arg):
	// Could dynamically allocate memory on the heap and pass it in.
	// If there isn't enough space, getline will reallocate memory if needed.
	return 0;
}
