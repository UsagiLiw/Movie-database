/************************************************
*		Program name : movie.c			
*		Group name : Apple Juice
*			Member : 1. 
*				 2.
*				 3.
*				 4.
*			
*			6 December 2017
*
************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#include "movie.h"
#include "../displayData/displayData.h"
#include "../addData/addData.h"
#include "../ioFunction/ioFunction.h"

int main()
{
	FILE* pIn = NULL;
	MOVIE_T* movie;
	char terminalInput[256];
	int choice = 0;
	int header = 0;

	pIn = fopen("../DATABASE.txt", "r");
	if(pIn == NULL)
	{
		printf("DATABASE.txt file not found\n");
		printf("Creating new file...\n");
		pIn = fopen("../DATABASE.txt", "w");
		if(pIn == NULL)
		{
			printf("Error - Cannot create file.\n");
			exit(1);
		}
		printf("Create file success\n\n");
	}
	fclose(pIn);
	readHeader(header);
	movie = (MOVIE_T*) calloc(header, sizeof(MOVIE_T));
	readData(movie);
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
				displayData(movie, header);
				break;
			case 2 :
				printf("Add!\n");
				addData(movie, header);
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
				fclose(pIn);
				exit(1);
			default :
				printf("Error - Command not found");
		}
	fclose(pIn);
	}
	return 0;
}
