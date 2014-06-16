#include <stdio.h>

int main(int argc, char *argv[])
{
	// go through each string in argv
	
	int i = 0;
	while(i < argc) {
		printf("arg %d: %s\n", i , argv[i]);
		i++;
	}
	
	// let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};
	
	int num_states = 4;
	i = 0; // watch for this
	while(i < num_states) {
		printf("state %d: %s\n", i, states[i]);
		i++;
	}
	printf("Address of states[1]: %p\n", &states[1]);
	printf("Address of argv[1]: %p\n", &argv[1]);
	// EXTRA CREDIT
	// 1.
	printf("Extra credit 1:\n");
	i = (argc-1);
	while(i >= 0) {
		printf("arg %d: %s\n", i , argv[i]);
		i--;
	}
	i = (num_states-1); // watch for this
	while(i >= 0) {
		printf("state %d: %s\n", i, states[i]);
		i--;
	}
	printf("Address of states[1]: %p\n", &states[1]);
	printf("Address of argv[1]: %p\n", &argv[1]);
	// 2. and 3.
	printf("Extra Credit 2:\n");
	i = 0;
	int term;
	if(argc > num_states){
		term = num_states;
	}
	else {
		term = argc;
	}
	while(i < term){
		states[i] = argv[i];
		i++;
	}
	i = 0;
	while(i < num_states){
		printf("states[%d]: %s\n", i, states[i]);
		i++;
	}
	printf("Address of states[1]: %p\n", &states[1]);
	printf("Address of argv[1]: %p\n", &argv[1]);
	
	
	return 0;
}

/* 	How to break it

				1.  Forget to initialize the first int i; so have it loop wrong.
						Changed int i = 0; to int i;
						Seems to automatically initialize to 0, so nothing breaks in this case.
				
				2.  Forget to initialize the second loop's i so that it retains the value from the end of the first loop.
					Now your second loop might or might not run.
						This works as one would expect....
				
				3.  Forget to do a i++ increment at the end of the loop and you get a "forever loop", one of the dreaded
					problems of the first decade or two of programming.
						Been there, done that.
	Extra Credit
				
				1.  Make these loops count backward by using i-- to state at argc and count down to 0.
						Have to use num_states and argc - 1; also have to use >= 0 in termination condition
				
				2.  Use a while loop to copy values from argv into states.
				
				3.  Make this copy loop never fail such that if there's too many argv elements it won't put them all into states.
						Simple if statement solution sets terminal value to num_states if argc > 4 or argc if it is in range.
				
				4.  Research if you've really copied these strings.  
						Not sure what I'm supposed to find here.  
						
						
*/