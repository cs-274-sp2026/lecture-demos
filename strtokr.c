#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char* line = NULL;
	size_t n = 0;
	size_t len = getline(&line, &n, stdin);
	if( len == -1 ) {
		printf("Error on getline\n");
		free(line);
		exit(1);
	}
	printf("Line is: %s\n", line);


	// A token is a piece of a string that is marked by delimiters.
	// Suppose you have the line entered by the user as "3.14,9.81,21.7" and
	// this is stored as the string variable line. If we say that the commas
	// are delimiters, then the tokens are:
	// Token 1: 3.14
	// Token 2: 9.81
	// Token 3: 21.7
	//
	//
	char* saveptr=NULL;

	// The strtok_r function tokenizes a string. It takes the following args:
	// 1) 1st arg: the string you want to parse into tokens. This string must
	// be a modifiable string. You cannot pass a read-only string or a const
	// string.
	//
	// 2) 2nd arg: is the string of delimiters. For example, "," means that
	// the comma is the delimiter. If I wanted to allow more characters to be
	// delimiters, I can give it ",-" which would mean that "," and "-" are
	// interpreted as delimiters.
	//
	// 3) 3rd arg: is the address of char pointer that points to the start
	// of the next token.
	//
	// Returns: the char pointer to the first token in the string you are 
	// tokenizing and NULL if there are no more tokens left.
	//
	// On the first call, give it the original string you want to parse.
	// In this example, it is the string variable line.
	//
	// How does strtok_r work?
	// It analyzes the string until it hits either:
	//   1) A null terminator. In which case it stops and returns NULL
	//   2) A delimiter. It will replace the delimiter with a null terminator
	//      and update saveptr with the address of the next char
	//
	// strtok_r returns the base address of the first token
	// Why does strtok_r manipulate the string you gave it? To avoid allocating
	// more memory (which would use up time and space -- you would need to
	// allocate more things on the heap because tokens are variable size and
	// this would slow things down). 
	// 
	
	char* token = strtok_r(line, ",", &saveptr);
	char** tokens = NULL; // this will store the tokens I extracted
	size_t num_tokens = 0; // this will store the number of tokens

	printf("line = %s\n", line);
	while(token) {
		tokens = realloc(tokens,sizeof(char*)*(num_tokens+1));
		char* token_copy = malloc(sizeof(char)*(strlen(token)+1));
		strcpy(token_copy,token);
		tokens[num_tokens]=token_copy;
		num_tokens++;

		double d=strtod(token,NULL);
		printf("token = %s, squared val = %lf\n", token,d*d);
		printf("saveptr = %s\n", saveptr);

		// If you pass NULL as the first argument, it tells strtok_r to
		// continue where it left off. NULL is a special value that 
		// allows strtok_r to resume where it left off from the previous call.
		// It will return the pointer to the first char of the next token.
		token=strtok_r(NULL, ",", &saveptr);
		printf("%s\n", token_copy);
	}

	// If you free(line) here, the token variable is a dangling pointer
	free(line);

	// This line below causes a segmentation fault
	// printf("%s\n", token);
	
	for( int i = 0; i < num_tokens; i++ ) {
		printf("Token %d = %s\n", i, tokens[i]);
	}

	// This cleans up all the memory that was dynamically allocated
	for( int i = 0; i < num_tokens; i++ ) {
		free(tokens[i]);
	}
	free(tokens);
	
	return 0;
}
