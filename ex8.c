#include <stdio.h>

int main(int argc, char *argv[])
{
	int areas[] = {10, 12, 13, 14, 20};
	char name[] = "Zed"; 
	char full_name[] = {
		'Z', 'e', 'd', 
		' ', 'A', '.', ' ', 
		'S', 'h', 'a', 'w', '\0'
	};
	
	// WARNING: On some systems you may have to change the
	// %ld in this code to a %u since it will use unsigned ints
	
	//Extra credit:
	
	areas[1] = name[0];
	
	printf("The size of an int: %lu\n", sizeof(int));
	printf("The size of areas (int[]): %lu\n", sizeof(areas));
	printf("The first area is %d, the 2nd is %d.\n", areas[0], areas[1]);
	
	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name (char[]): %ld\n", sizeof(name));
	printf("The contents (int) of name[10]: %d\n", name[10]);
	
	printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
	printf("The contents (int) of full_name[20] is: %d\n", full_name[20]);
	int i;
	for (i = 10; i < 100; i++)
	{
		printf("The contents (int) of full_name[%d] is: %d\n", i, full_name[i]);
	}
	for (i = 10; i < 10000; i++)
	{
		printf("%c", full_name[i]);
	}
	printf("The number of chars: %lu\n", sizeof(full_name)/sizeof(char));
	
	printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);
	
	return 0;
}