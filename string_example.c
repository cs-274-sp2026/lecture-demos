#include <stdio.h>
#include <string.h>

int main() {
	// ASCII is the most common character encoding in use
	// We can either work with the encoding number or the character.
	// For example, 'A' is code 65
	// if( c == 65 ) will check if c is 'A'
	char c = 'a';
	printf("%c\n", c);

	// C does not have a string type
	// Instead, it represents strings as an array of characters with
	// a null terminator symbol '\0' to indicate the end of the string.
	char str[4]={'d','o','g','\0'};
	printf("%s\n", str);

	// The null terminator is a special character that is not printable
	printf("Null terminator: %c\n", '\0');

	// You can also declare string literals with quotes.
	// When the program starts, the string literal "Hello world" is then
	// converted into a character array with a null terminator at the end.
	// Then, the array is stored in a special part of memory that is
	// read-only.  Then, when the progam arrives at this line of code,
	// it takes the memory address of the array and assigns it to my_string
	// I recommend making this a const. If you leave the const out, it
	// will result in undefined behavior if you modify my_string and use it
	// later on.
	char const* my_string = "Hello world";
	printf("%s\n", my_string);
	
	// The code below will cause undefined behavior. Seems to work on ENGR
	// right now though.
	//my_string = "Goodbye world";
	//printf("%s\n", my_string);
	
	// Need to include string.h for strlen.
	// strlen return type size_t 
	printf("String length = %ld\n", strlen(my_string));
	printf("Print out 2nd character in my_string = %c\n", my_string[1]);
	printf("%s\n", my_string); // my_string is really the address of the first
								// element in the array
	printf("%s\n", my_string+2);

	char cat_string[4] = {'c','a','t','\0'};
	printf("%s\n", cat_string);
	cat_string[1] = '\0';
	printf("%s\n", cat_string);
}

