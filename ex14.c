#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
int can_print_it(char ch);
void print_letters(char arg[], int length);

void print_arguments(int argc, char *argv[])
{
	int i = 0;
	
	for(i = 0; i < argc; i++) {
		print_letters(argv[i], strlen(argv[i]));
	}
	
}

void print_letters(char arg[], int length)
{
	int i = 0;
	
	for(i = 0; i < length; i++) {
		char ch = arg[i];
		
		if(can_print_it(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}
	
	printf("\n");
	
	for(i = 0; i < length; i++) {
		char ch = arg[i];
		
		if(ispunct(ch) || isdigit(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}
	printf("\n");
}

int can_print_it(char ch)
{
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}


/*		How to break it:
			1.  Confuse the compiler by removing the forward declarations so it complains about can_print_it and print_letters.
					It didn't like that at all.  
			
			2.  When you call print_arguments inside main try adding 1 to argc so that it goes past the end of argv[].
					Throws a segmentation fault.  
					
		Extra Credit:
			1.  Rework these functions so that you have fewer functions.  
				For example, do you really need can_print_it?
					You can test for alpha or blank in the print letters function.  "isalpha(ch) || isblank(ch)"
					would easily fit in the condition of the if statement.  
			
			2.  Have print_arguments figure out how long each argument string is using the strlen function, and the pass that
				length to print_letters.  Then, rewrite print_letters so it only processes this fixed length and doesn't rely
				on the '\0' terminator.  
					See above.
					
			3.  Use man to lookup information on isalpha and isblank. Use the other similar functions to print out only digits
				or other characters.  
					Used ispunct(char) and isdigit(char).  
					
			4.  
					
			
			
*/