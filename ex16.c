#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);
	
	who -> name = strdup(name);
	who -> age = age;
	who -> height = height;
	who -> weight = weight;
	
	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);
	
	free(who -> name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	// make two people structures
	struct Person *joe = Person_create(
			"Joe Alex", 32, 64, 140);
	
	struct Person *frank = Person_create(
			"Frank Black", 20, 72, 180);
			
	// print them out and where they are in memory
	
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);
	
	printf("Frank is at memory location %p\n", frank);
	Person_print(frank);
	
	// make everyone age 20 years and print them again
	joe -> age += 20;
	joe -> height -= 2;
	joe -> weight += 40;
	Person_print(joe);
	
	frank -> age += 20;
	frank -> weight += 20;
	Person_print(frank);
	
	// destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(frank);
	
	return 0;
}

/* Line by Line
		1.  includes
				stdio.h:	
							operations on files
							file access
							formatted input/output
							character input/output
							direct input/output (ie. fread, fwrite)
				assert.h:	
							gives access to assert macro, a debugging tool
							void assert(int expression) throws and error if expression evaluates to 0
				stdlib.h:	
							dynamic memory management
							random number generation
							communication with environment (??)
							integer arithmetic
							search, sort, convert functions
				string.h:	
							string tools
							
		2.  struct Person
				complex data type declaration
				variables of different types are physically grouped by one name in a contiguous block of memory
				can be accessed by the same pointer
				
		3.  function Person_create
				initializes a struct of type Person
				takes all attributes as parameters
		
		4.	....
		
	How to Break It:
		1.	Try passing NULL to Person_destroy at the end to see what it does.  
				
		2.	Forget to call Person_destroy at the end, then run it under Valgrind to see it report that you forgot to
			free the memory.  Figure out the options you need to pass to Valgrind to get it to print how you leaked
			this memory.
				Use Valgrind --leak-check=full ./ex16
		
		3.  Forget to free who->name in Person_destroy and compare the output.  Again, use the right options to see 
			how Valgrind tells you exactly where you messed up.  
				--leak-check=full gives the line of the struct declaration and the line of the initialization in the program.
				
		4.  This time, pass NULL to Person_print and see what Valgrind thinks of that.
				Program exits early so nothing gets free'd.  First, though, it says that 0x0 (NULL) is not malloc'd, stack'd,
				or (recently) free'd.  Invalid read size of 8?
				
	Extra Credit
		In this exercise I want you to attempt something difficult for the extra credit: Convert this program to not use
		pointers and malloc.  This will be hard, so you'll want to research the following:
			1.	How to create a struct on the stack, which means just like you've been making any other variable.
			
			2.  How to initialize it using the x.y character instead of the x->y syntax.
			
			3.  How to pass a structure to other functions without using a pointer.  
			
			*/
			
				
							
