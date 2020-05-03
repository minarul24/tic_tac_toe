/*************************************************************************************
//              Author:    MOHAMMAD MINARUL ISLAM SHAWON
//              Date:      19/NOV/2018
//              Program:   It is a tic-tac-toe game; played 
//                         between two players.
*************************************************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

void display_board(char array[3][3]);
bool winning_check(char array[3][3]);
int i,j,k,b_row,b_col;
int row=3,col=3;
char user1[50];
char user2[50];
char symbol1,symbol2;
char user[50];	
char array[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
int b[3][3];


int main(void)
{
	int turn=0,error;
	bool win;
	char chr='#';
	
	printf("Player 1, Enter your name:");
	gets(user1);
	
	printf("Please enter your symbol('X' or 'O'):");
	scanf("%c",&symbol1);
	
	printf("Player 2, Enter your name:");
	scanf("%s",user2);
	
	if(symbol1=='X')
	symbol2='O';
	
	else 
	symbol2='X';
	
	printf("%s : %c\n",user1,symbol1);
	printf("%s : %c\n",user2,symbol2);
	
			
	display_board(array);
	
	do
	{
		do
		{
		error =0;
		if(turn%2==0)
		{
			printf("%s, What is your next move?",user1);
			printf("\nWhich row?");
			scanf("%i",&b_row);
			printf("Which column?");
			scanf("%i",&b_col);
			
			if((b_row>3 || b_row<1) || (b_col>3 || b_col<1) )
			{
				printf("Invalid input, please try again!\n");
				error=1;
			}
			if(array[b_row-1][b_col-1] == symbol1 || array[b_row-1][b_col-1] == symbol2)
			{
				printf("Place already taken. Try another.\n");
				error=1;	
			}
			else
				array[b_row-1][b_col-1] = symbol1;
		}
		else
		{
			printf("%s, What is your next move?",user2);
			printf("\nWhich row?");
			scanf("%i",&b_row);
			printf("Which column?");
			scanf("%i",&b_col);
			
			if((b_row>3 || b_row<1) || (b_col>3 || b_col<1) )
			{
				printf("Invalid input, please try again!\n");
				error=1;
			}
			if(array[b_row-1][b_col-1] == symbol1 || array[b_row-1][b_col-1] == symbol2)
			{
				printf("Place already taken. Try another.\n");
				error=1;	
			}
			else
				array[b_row-1][b_col-1] = symbol2;
					
		}
		
	}
	while(error);
	
	win=winning_check(array);
	if(win)
	{
		if(turn%2==0)
		{
			printf("\n%s, Congratulations! You won.",user1);
			turn=9;
		}
		else
		{
			printf("\n%s, Congratulations! You won.",user2);
			turn=9;
		}
	}
	
	turn++;
	display_board(array);
	
	
	
	if(turn==9)
	{
		printf("\nGame Draw.");	
	}
	
	}while(turn<9);

	
	return 0;
}

void display_board(char array[3][3])
{
	printf("\n    1   2   3 ");// column of the board
	for(i=0;i<3;i++) // to build the board
	{
		printf("\n  *************\n%i ",i+1);// i+1 displays the rows of the spaces available
			for(j=0;j<3;j++)
			{
			printf("|%2c ",array[i][j]);
			}
		printf("|");	
	}
	printf("\n  *************\n");
}


bool winning_check(char array[3][3])
{
	for(i=0; i<3; i++)
		{
			for (j=0; j<3; j++)
			{
				if(array[i][0]==array[i][1] && array[i][0]== array[i][2] && array[i][0]!= '#')
				{
					return true;
				}
				else if(array[0][j]==array[1][j] && array[0][j]==array[2][j] && array[0][j] != '#')
				{
					return true;
				}
				else if(array[0][0]==array[1][1] && array[0][0]==array[2][2] && array[0][0]!= '#')
				{
					return true;
				}
				else if (array[2][0]==array[1][1] && array[2][0]==array[0][2] && array[2][0]!= '#')
				{
					return true;
				}
			}
		}
	return false;
}