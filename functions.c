#include <stdio.h>

// Scopes in C are loosely affiliated with curly braces
// A scope dictates two things:
// 1. Where symbols are accessible
//	A symbol is a named entity e.g. a variable, function, constant, enum, etc.
//	Symbols are only accessible within their scopes below their point of 
//	declaration
// 2. When automatic variables are freed from memory
//   An automatic variable is a regular, function-local variable. They have 
//   automatic storage duration.
//   When a variable's scope ends, the computer is allowed to free that
//   variable from memory.
//
//
//	 C has three kinds of loops:
//	 1. for
//	 2. while
//	 3. do while
//
//
//


int main() {

	int x = 2;


	// The for loop header has 3 things:
	// 1. Initialization statement
	// 2. Condition
	// 3. Post statement
	// 
	// i++ is the same as i = i + 1
	// ++i which is the same as i = i + 1 but it does the increment first
	for( int i = 0; i < 10; i++ ) {
		printf("The value of i is: %d, the value of x is: %d\n", i, x);
	}

	int counter=0;
	while(counter < 10) {
		printf("Counter is: %d\n", counter);
		counter++;
	}

	counter=0;
	do {
		printf("Do while counter is: %d\n", counter);
		counter++;
	} while (counter < 10);

	// Shorthand operators
	// ++, --, +=, -=, *=, /=
	int variable = 1;
	variable += 1; // variable = variable + 1
	variable -= 1; // variable = variable - 1

	// Pre- and post-increment
	// ++i vs i++
	variable =1;
	variable++; // This is an expression that is evaluated and has a value
	// variable++ evaluates to the current value (of 1) and then increments it
	
	variable = 1;
	++variable; // increments first, then evaluates to the value of 2

	// if( variable++ == 1) vs  if ( ++variable == 1) 
	//
	
	// Assignments have a value as well
	variable = 0; // the value of this expression is the value that was assigned
	if( variable == 0 ) { // don't use = for equality
		//true block
	} else {

	}


	// Symbols are accessible only within their scope. However, you can
	// have a scope within a scope
	// Can access named entities in an outer enclosing scope.
	// Can't do the other way around. 
	int blah=10;
	{
		int foo = 3;
		int blah = 20; // This is called shadowing -- where you declare
		// a variable with the same name as a variable in an outer scope.
		// You can't access the outer scope variable while it is being shadowed.
		// It is only accessible once you leave the scope of the "shadowing"
		// variable.
		printf("%d\n", blah);	
		int blah = 10;
	}
	printf("%d\n", blah);
}
