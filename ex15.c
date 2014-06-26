#include <stdio.h>

int main (int argc, char *argv[])
{
	// create two arrays we care about
	int ages[] = {23, 42, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};
	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;
	
	// first way using indexing
	for(i = 0; i < count; i++) {
		printf("%s has %d years alive. \n",
					 names[i], ages[i]);
	}
	
	printf("---\n");
	
	// setup the pointers to start of the arrays
	int *cur_age = ages;
	char **cur_name = names;
	
	// second way using pointers
	for(i = 0; i < count; i++) {
		printf("%s is %d years old.\n",
				*(cur_name+i), *(cur_age+i));
				
	}
	
	printf("---\n");
	
	// third way, pointers are just arrays
	for(i = 0; i < count; i++) {
		printf("%s is %d years old again.\n",
					cur_name[i], cur_age[i]);
	}
	
	printf("---\n");
	
	// fourth way with pointers in a stupid complex way
	for(cur_name = names, cur_age = ages; 
			(cur_age - ages) < count; cur_name++, cur_age++) 
	{
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
	
	/*** EXTRA CREDIT ***************************************************************/
	printf("---\n");
	printf("---\n");
	printf("Extra Credit\n");
	printf("---\n");
	
		// first way using indexing
	for(i = count-1; i >= 0; i--) {
		printf("%s has %d years alive. \n",
					 names[i], ages[i]);
	}
	
	printf("---\n");
	
	// setup the pointers to start of the arrays
	count = sizeof(ages)/ sizeof(int);
	cur_age = ages;
	cur_name = names;
	
	// second way using pointers
	for(i = count-1; i >= 0; i--) {
		printf("%s is %d years old.\n",
				*(cur_name+i), *(cur_age+i));
				
	}
	
	printf("---\n");
	
	// third way, pointers are just arrays
	for(i = count-1; i >= 0; i--) {
		printf("%s is %d years old again.\n",
					cur_name[i], cur_age[i]);
	}
	
	printf("---\n");
	
	// fourth way with pointers in a stupid complex way
	for(cur_name = &names[count-1], cur_age = &ages[count-1]; 
			(cur_age-ages) >= 0; cur_name--, cur_age--) 
	{
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
		printf("ages:    %p\ncur_age: %p\n", ages, cur_age);
	}
	
	return 0;
}

/*		How To Break It:
			1.  Try to make cur_age point at names.  You'll need to use a C cast to force it,
				so go look that up and try to figure it out.  
					Curious result:  
						Pointing cur_age at names[0]: 
							Second and third methods print, predictably, very large integers.
							The fourth way reverts to the original contents of ages.  I think maybe it has to do
							with the Initialization of the for loop resetting cur_name and cur_age to names and ages,
							respectively.  
						Pointing cur_age at names:
							Produces segmentation fault.  
					
					Type casting is done by placing the desired type in parenthesis in front of the variable 
					to be temporarily cast as another type.  e.g. int an_int = (int)a_char;
					
					
			2.  In the final for-loop try getting the math wrong in weird ways.  
					Coolest thing I could produce was another seg fault.
					
			3.  Try rewriting the loops so they start at the end of the arrays and go to the beginning.  
				This is harder than it looks.  
					This wasn't too bad.  The fourth way makes more sense now, after having really dissected it.
					
		Extra Credit:
			
						
					
					
*/