/****************************************************************************************/ 
/***    prologue                                                                      ***/
/***                                                                                  ***/
/***    University of California Extension, Santa Cruz                                ***/
/***                                                                                  ***/
/***    Advanced C Programming                                                        ***/
/***                                                                                  ***/
/***    Instructor: Rajainder A. Yeldandi                                             ***/
/***                                                                                  ***/
/***    Author: Joshua Cook                                                           ***/
/***                                                                                  ***/
/***    Assignment Number: 6                                                          ***/
/***                                                                                  ***/
/***    Topic: Tic Tac Toe                                                            ***/
/***                                                                                  ***/
/***    File name:                                                                    ***/
/***                                                                                  ***/
/***    Date:                                                                         ***/
/***                                                                                  ***/
/***    Objective:                                                                    ***/
/***                                                                                  ***/
/***    Comments:                                                                     ***/
/****************************************************************************************/

/***    Program Elements                                                              ***/
/***                                                                                  ***/
/***    preprocessor directives                                                       ***/
/***                                                                                  ***/
/***    function prototypes                                                           ***/
/***                                                                                  ***/
/***    global definitions                                                            ***/
/***                                                                                  ***/

#include <stdio.h>
#include <string.h>
#define TRUE 1

int main(int argc, char *argv[])
{
    char user_input[256]={0x0};
    char player_one[256] = "Player 1";
    char player_two[256] = "Player 2";

	char ary[4][4] = {{' ', ' ', ' ', ' '},{' ', ' ', ' ', ' '},{' ', ' ', ' ', ' '},{' ', ' ', ' ', ' '}};
    // char ary[4][4] = {{'a', 'b', 'c', 'd'},{'e', 'f', 'g', 'h'},{'i', 'j', 'k', 'l'},{'m', 'n', 'o', 'p'}};
    
    
	char (*a_ptr)[4] = ary;
	int user_row, user_col;

    
    int len;

	// User Interface 
	
	printf("\n\n\n\n");
	printf("*************************************************************\n");
	printf("Welcome to Tic Tac Toe!\n");
	printf("\n\n");
	printf("*************************************************************\n");	
	printf("\n\n");

	// prompt user for conversion type
	printf("Who will play first?\n");
	printf("Please type Player 1's name: ");

	// collect user response via stdin
	fgets(user_input, sizeof(user_input), stdin);


	// remove newline character from end of collected input
	len = strlen(user_input);
	if( user_input[len-1] == '\n' )
		user_input[len-1] = '\0';
	if(user_input[0] != '\0')
		strcpy(player_one,user_input);	

	
	// prompt user for conversion type
	printf("Who will play first?\n");
	printf("Please type Player 2's name: ");

	// collect user response via stdin
	fgets(user_input, sizeof(user_input), stdin);

	// remove newline character from end of collected input
	len = strlen(user_input);
	if( user_input[len-1] == '\n' )
		user_input[len-1] = '\0';
	if(user_input[0] != '\0')
		strcpy(player_two,user_input);	



	printf("\n\n\n\n");
	printf("*************************************************************\n");
	printf("Presenting:\n");
	printf("%s v %s\n", player_one, player_two);
	printf("*************************************************************\n");	
	printf("\n\n");

	printf("*************************************************************\n");
	printf("How to Play:\n\n");
	printf("\tWhen prompted, enter your move as \"row,column\".\n");
	printf("\tFor Example, to play here:\n");
		printf("\t    1   2   3   4  \n");
	printf("\t  +---+---+---+---+\n");
	printf("\t1 | %c | %c | %c | %c |\n", **a_ptr,*(*a_ptr+1),*(*a_ptr+2),*(*a_ptr+3));
	printf("\t  +---+---+---+---+\n");
	printf("\t2 | %c | %c | x | %c |\n", **(a_ptr+1),*(*(a_ptr+1)+1),*(*(a_ptr+1)+2),*(*(a_ptr+1)+3));
	printf("\t  +---+---+---+---+\n");
	printf("\t3 | %c | %c | %c | %c |\n", **(a_ptr+2),*(*(a_ptr+2)+1),*(*(a_ptr+2)+2),*(*(a_ptr+2)+3));
	printf("\t  +---+---+---+---+\n");
	printf("\t4 | %c | %c | %c | %c |\n", **(a_ptr+3),*(*(a_ptr+3)+1),*(*(a_ptr+3)+2),*(*(a_ptr+3)+3));
	printf("\t  +---+---+---+---+\n");
	printf("\n\n");
	printf("\tEnter: 2 3\n\n");
	printf("\t\t\tPress Enter to Continue.\n");
	printf("*************************************************************\n");	
	printf("\n\n");	
	getchar();    



	while(TRUE)
	{
		printf("*************************************************************\n");
		printf("Your move, %s!", player_one);
		printf("\n");
		printf("*************************************************************\n");	
		printf("\t    1   2   3   4  \n");
		printf("\t  +---+---+---+---+\n");
		printf("\t1 | %c | %c | %c | %c |\n", **a_ptr,*(*a_ptr+1),*(*a_ptr+2),*(*a_ptr+3));
		printf("\t  +---+---+---+---+\n");
		printf("\t2 | %c | %c | %c | %c |\n", **(a_ptr+1),*(*(a_ptr+1)+1),*(*(a_ptr+1)+2),*(*(a_ptr+1)+3));
		printf("\t  +---+---+---+---+\n");
		printf("\t3 | %c | %c | %c | %c |\n", **(a_ptr+2),*(*(a_ptr+2)+1),*(*(a_ptr+2)+2),*(*(a_ptr+2)+3));
		printf("\t  +---+---+---+---+\n");
		printf("\t4 | %c | %c | %c | %c |\n", **(a_ptr+3),*(*(a_ptr+3)+1),*(*(a_ptr+3)+2),*(*(a_ptr+3)+3));
		printf("\t  +---+---+---+---+\n");
		printf("\n\n");

	
		// prompt user for move
		while(TRUE){
			printf("%s, please enter your move as \"row column\":", player_one);

			// collect user response via stdin
			scanf("%i %i", &user_row, &user_col);
			if(*(*(a_ptr+user_row-1)+user_col-1) == ' '){
				*(*(a_ptr+user_row-1)+user_col-1) = 'x';
				break;
			}
			else
				printf("Invalid move.\n");
		}
		
		printf("*************************************************************\n");
		printf("Your move, %s!", player_two);
		printf("\n");
		printf("*************************************************************\n");	
		printf("\t    1   2   3   4  \n");
		printf("\t  +---+---+---+---+\n");
		printf("\t1 | %c | %c | %c | %c |\n", **a_ptr,*(*a_ptr+1),*(*a_ptr+2),*(*a_ptr+3));
		printf("\t  +---+---+---+---+\n");
		printf("\t2 | %c | %c | %c | %c |\n", **(a_ptr+1),*(*(a_ptr+1)+1),*(*(a_ptr+1)+2),*(*(a_ptr+1)+3));
		printf("\t  +---+---+---+---+\n");
		printf("\t3 | %c | %c | %c | %c |\n", **(a_ptr+2),*(*(a_ptr+2)+1),*(*(a_ptr+2)+2),*(*(a_ptr+2)+3));
		printf("\t  +---+---+---+---+\n");
		printf("\t4 | %c | %c | %c | %c |\n", **(a_ptr+3),*(*(a_ptr+3)+1),*(*(a_ptr+3)+2),*(*(a_ptr+3)+3));
		printf("\t  +---+---+---+---+\n");
		printf("\n\n");

	
		// prompt user for move
		while(TRUE){
			printf("%s, please enter your move as \"row column\":", player_two);

			// collect user response via stdin
			scanf("%i %i", &user_row, &user_col);
			--user_row;
			--user_col;
			if(*(*(a_ptr+user_row)+user_col) == ' '){
				*(*(a_ptr+user_row)+user_col) = 'o';
				break;
			}
			else
				printf("Invalid move.\n");
		}
		
		
	}
	return 0;
	
}