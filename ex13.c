#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("ERROR: You need at least one argument.\n");
		// this is how you abort a program
		return 1;
	}
	
	int i = 0;
	int j = 0;
	char letter;
		for(j = 1; j < argc; j++) {
			printf("Argument #%d:\n", j);
			for(i = 0, letter = argv[j][i]; argv[j][i] != '\0'; letter = argv[j][++i]) {
			switch(letter) {
				case 'a':
				case 'A':
					printf("%d: 'A'\n", i);
					break;
				
				case 'e':
				case 'E':
					printf("%d: 'E'\n", i);
					break;
				
				case 'i':
				case 'I':
					printf("%d: 'I'\n", i);
					break;
				
				case 'o':
				case 'O':
					printf("%d: 'O'\n", i);
					break;
				
				case 'u':
				case 'U':
					printf("%d: 'U'\n", i);
					break;
				
				case 'y':
				case 'Y':
					if(i > 2) {
						// it's only sometimes Y
						printf("%d: 'Y'\n", i);
						break;
					}	

			
			default:
			printf("%d: %c is not a vowel\n", i, letter);
			}
		}
		printf("\n");
	}
	
	// EXTRA CREDIT
	// 1.  
	printf("Extra Credit 1.\n");
	for(i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];
		
		switch(letter) {
			case 'a':
				printf("%d: %c\n", i, letter);
				break;
			case 'A':
				printf("%d: %c (tolowercase called)\n", i, letter+32);
				break;
			
			case 'e':
				printf("%d: %c\n", i, letter);
				break;
			case 'E':
				printf("%d: %c (tolowercase called)\n", i, letter+32);
				break;
			
			case 'i':
				printf("%d: %c\n", i, letter);
				break;
			case 'I':
				printf("%d: %c (tolowercase called)\n", i, letter+32);
				break;
			
			case 'o':
				printf("%d: %c\n", i, letter);
				break;
			case 'O':
				printf("%d: %c (tolowercase called)\n", i, letter+32);
				break;
			
			case 'u':
				printf("%d: %c\n", i, letter);
				break;
			case 'U':
				printf("%d: %c (tolowercase called)\n", i, letter+32);
				break;
			
			case 'y':
				if(i > 2) {
					printf("%d: %c\n", i, letter);
				}
				break;
			case 'Y':
				if(i > 2) {
					// it's only sometimes Y
					printf("%d: %c (tolowercase called)\n", i, letter+32);
				}	
				break;
			default:
			;
		}
	}
	
	return 0;
}

/*		How to break it:
			I don't like switch statements so I'm skipping this.
			
		Extra credit:
			1.  Write another program that uses math on the letter to convert it to lowercase, 
				and then remove all the extraneous uppercase letters in the switch.
					See above.
			
			2.  Use the ',' (comma) to initialize letter in the for-loop.
					Had to add a statement at initialization as well as increment.  
					Had to use prefix increment operator to avoid printing first letter twice.
					The statement "i++, letter = argv[1][i]" also works.
					
			3.  Make it handle all of the arguments you pass it with yet another for-loop.  
					Easy peasy.
					
			4.  Convert this switch-statement to an if-statement.
					No way.
					
			5.  In the case for 'Y' I have the break outside the if-statement.  What's the impact of this
				and what happens if you move it inside the if-statement.  Prove to yourself you're right.
					Moving break inside the if statement will print "y is not a vowel" when, in fact, it sometimes is.
			
*/