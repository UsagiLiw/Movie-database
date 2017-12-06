/************************************************
*		Program name : movie.c			
*		Group name : Apple Juice
*			Member : 1. 
*					 2.
*					 3.
*					 4.
*			
*			6 December 2017
*
************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

int main()
{
	char terminalInput[256];
	int choice = 0;
	
	printf("===================================");
	printf("\nWELCOME TO YOUR MOVIE DATABASE\n");
	printf("===================================\n\n");
	while(1)
	{
		printf("What do you want to do?\n");
		printf("1. Display\n");
		printf("2. Add\n");
		printf("3. Edit\n");		
		printf("4. Delete\n");		
		printf("5. Search\n");
		printf("6. EXIT\n");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%d",&choice);
		switch(choice)
		{
			case 1 :
				printf("Display!\n");
				break;
			case 2 :
				printf("Add!\n");
				break;
			case 3 :
				printf("Edit!\n");
				break;
			case 4 :
				printf("Delete!\n");
				break;
			case 5 :
				printf("Search!\n");
				break;
			case 6 :
				printf("EXIT! Goodbye!\n");
				exit(1);
			default :
				printf("Error - Command not found");
		}
	}
	return 0;
}
