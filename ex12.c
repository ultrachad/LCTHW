#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	
	if(argc == 1) {
		printf("You only have one argument. You suck.\n");
	} else if(argc > 1 && argc < 4) {
		printf("Here's your arguments:\n");
		
		for(i = 0; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments. You suck.\n");
	}
	// EXTRA CREDIT
	printf("Extra credit 4.\n");
	
	if(argc == 2) {
		printf("You only have one argument. You suck.\n");
	} else if(argc > 2 && argc < 5) {
		printf("Here's your arguments:\n");
		
		for(i = 0; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments. You suck.\n");
	}
	return 0;
}

/* How to break it

		1.  Remove the else at the end and it won't catch the end case.
				Fair enough..
		
		2.  Change the && to a || so you get an "or" instead of "and" test and see how that works
				Been there done that.
				
	Extra Credit
		1.  You were briefly introduced to &&, which does an "and" comaparison, so go research online
			the different "boolean operators".
				&& = and; ! = not; || = or
		
		2.  Write a few more test cases to see what you can come up with.
				Ain't nobody got time for that.
		
		3.  Go back to exercises 10 and 11, and use if-statements to make the loops exit early.
			You'll need the break statement to do that.  Go read about it.  
				The break statement is used to exit a loop (for, while, until), or a switch statement, early.  
		
		4.  Is the first test really saying the right thing?  To you the "first argument" isn't the same 
			first argument a user entered.  Fix it.  
			
*/