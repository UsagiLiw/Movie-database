/************************************************
*		Program name : movie.c			
*		Group name : Apple Juice
*			Member : 	1. Nutchanon Veraphichkasem	60070503422
*				 	2. Thanapat Sakaekhao 		60070503430
*				 	3. Nonthakorn Sukprom		60070503435
*				 	4. Bhimapaka Thapanangkun 	60070503447
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
#include "../search/search.h"


void exitProgram()
{
	char terminalInput[256];
	char yesNo;
	
	printf("Are you sure you want to exit program? (y/n)");
	fgets(terminalInput, sizeof(terminalInput), stdin);
	sscanf(terminalInput, "%c", &yesNo);
	switch(yesNo)
	{
		case 'y' :
			printf("Goodbye!");
			exit(1);
		case 'n' :	
			break;
		default :
			printf("Please select only 'y' or 'n'\n\n");
	}
}

int main()
{
	FILE* pIn = NULL;
	MOVIE_T* movie;
	MOVIE_NT* newMovie;
	char terminalInput[256];
	int choice = 0;
	int count = 0;
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
	readHeader(&header);
	movie = calloc(header, sizeof(MOVIE_T));
	readData(movie);
	printf("===================================");
	printf("\nWELCOME TO YOUR MOVIE DATABASE\n");
	printf("===================================\n\n");
	while(1)
	{
		printf("What do you want to do?\n");
		printf("1. Display\n");
		printf("2. Add\n");				
		printf("3. Search\n");
		printf("4. EXIT\n");
		fgets(terminalInput,sizeof(terminalInput),stdin);
		sscanf(terminalInput,"%d",&choice);
		switch(choice)
		{
			case 1 :
				printf("Display!\n");
				displayData(movie, &header);
				
			case 2 :
				printf("Add!\n");
				addData(newMovie,movie,&count);
				writeDatabase(newMovie,movie,header,count);
				
			case 3 :
				printf("Search!\n");
				searchOption(newMovie, movie, header);
				
			case 4 :
				printf("EXIT!\n");
				exitProgram();

			default :
				printf("Error - Command not found");
		}
	fclose(pIn);
	free(movie);
	}
	return 0;
}
