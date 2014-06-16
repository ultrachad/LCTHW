#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	printf("In case you were curious, argv[0]: %s\n", argv[0]);
	// go through each string in argv
	// why am I skipping argv[0]?
		// because argv[0] contains the program's name.
	for(i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}
	
	// let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington", NULL
		};
	int num_states = 4;
	
	for(i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i , states[i]);
	}
	
	// EC #4
	
		// assign element of states to argv
	argv[3] = states[2];
	
	for(i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i , states[i]);
	}
	
	for(i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}
		// assign element of argv to states
	states[2] = argv[2];
	
	for(i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i , states[i]);
	}
	
	for(i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}
	return 0;
}

/* How to break it

		1. Run in other language
				Tried both python and ruby and they both gave me weird errors.
				Definitely broke before I was able to pass a large number of arguments.
				Reached up to 120 args in C and was unable to break it.

		2. Initializing i to 0. 
				Works on the first try.  
				It works because the first argument is the call to execute the program, I think.
			
		3. Set num_states wrong so that it's a higher value and see what it does.
				It throws an error that says "Segmentation Fault (core dumped)".
					A segmentation fault is thrown when a program tries to read memory it doesn't have access to.  
				
	Extra Credit
		
		1. Figure out what kind of code you can put into the parts of a for-loop.
				for(initialization, test, increment){
					code;
				}
			
		2. Look up how to use the ',' (comma) character to separate multiple statements
			in the parts of the for-loop, but between the ';' (semicolon) characters.  
				Commas allow for multiple variables to be initialized and incremented differently
				within a single for-loop.
			
		3. Read what a NULL is and try to use it in one of the elements of the states array to see what it will print.
					A null pointer definitively points nowhere, as opposed to an uninitiallized pointer,
					which can unintentionally point to an object or function.
					Setting an element in the states array to NULL and printing yields "(null)"
		4.  See if you can assign an element from the states array to the argv array before printing both.  Try the inverse.
					Both cases only work if enough arguments passed to argv upon execution of the program.
					

*/