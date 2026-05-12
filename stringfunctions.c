#include <stdio.h>
#include <stdlib.h>
#include <string.h> // New for today

int main() {
	char buf[4]; // Creates a buffer of 4 chars on the stack

	// The fgets function:
	// 1st arg: the char array for the input
	// 2nd arg: the size of that char array
	// 3rd arg: the input stream (which is stdin in this case)
	// Note: it does not dynamically allocate memory for the 1st argument. You
	// need to either create a char buffer on the stack or on the heap
	// - It will also add the null terminator to the line read.
	// - If you input more chars than the size of the 1st arg arrray, it will
	//   read up to the size of the array-1 and add the null terminator. The
	//   remainder of the input is left in the buffer for the input
	//
	// Note: Compared to getline, fgets requires you to know the size of the 
	// input. If you don't know that, use getline
	fgets(buf, 4, stdin);
	printf("%s\n", buf);
	
	// The next call to fgets will grab the remainder of the input in the buffer
	// up to 3 chars in this case
	fgets(buf, 4, stdin);
	printf("%s\n", buf);

	// 1) strcmp: compares two strings that are passed in as arguments
	// Returns 0 if the two strings are the same
	char* str1 = "Alice";
	char* str2 = "Bob";

	// This compares memory address, not the strings
	if( str1 == str2 ) {
		printf("Equal\n");	
	} else {
		printf("Not equal\n");
	}
	

	// This only compares the first characters
	if( *str1 == *str2 ) {
		printf("Equal\n");
	} else {
		printf("Not equal\n");
	}

	int returnval = 0;
	returnval = strcmp(str1,str2);

	if( returnval == 0 ) {
		printf("They are equal: %s %s. return value = %d\n", str1, str2,
				returnval);
	} else {
		printf("They are not equal: %s %s. return value = %d\n", str1, str2, 
				returnval);
	}
	
	// 2) strcpy: copies from one string to the other
	// 1st arg is the destination string
	// 2nd arg is the source string
	char* destination = malloc(sizeof(buf));
	strcpy(destination,buf);
	printf("strcpy result: %s\n", destination);
	printf("strcpy source: %s\n", buf);
	free(destination);

	// You can also pass in a 3rd arg to strncpy which specifies the number
	// of chars to copy over
	char* destination2 = malloc(sizeof(str1));
	strncpy(destination2, str1, 2);
	printf("strncpy result: %s\n", destination2);
	free(destination2);
	

	// 3) strcat: glues two strings together
	// Make sure the 1st arg is big enough to hold the size of the concatenated
	// string.
	char* concatenated = malloc(strlen(str1) + strlen(str2) + 1); // +1 for
	// null terminator
	strcpy(concatenated,str1);
	printf("%s\n", concatenated);
	strcat(concatenated,str2);
	printf("Concatenated string: %s\n", concatenated);
	free(concatenated);

	// 4) sprintf prints a formatted string (need to include stdio.h)
	double pi = 3.14;
	const char* hello = "Hello!";
	char* buf2 = malloc(sizeof(char)*1024);
	if( !buf2 ) {
		printf("Error: malloc failed\n");
		exit(-1);
	}
	sprintf(buf2, "%lf %s\n", pi, hello);
	printf("%s\n", buf2);
	free(buf2);

	// 5) strtod and strtol
	// strtod: convert a string to a double
	// strtol: convert a string to a long
	const char* my_string = "3.0Bob"; // if the string is not a valid double,
	// it will read up to the first valid char that could be interpreted as
	// a double and stops
	char* endptr=NULL; // 2nd arg to strtod is modified to contain the address
	// of where the strtod function stopped reading at the first invalid char
	double my_double = strtod(my_string,&endptr);
	printf("%lf\n", my_double*my_double);
	printf("%s\n", endptr);

	// 6) isLower(c) and isUpper(c) checks if the character c is lower or
	// uppercase. Returns true if so, and false otherwise
}
