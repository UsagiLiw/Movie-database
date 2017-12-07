/*
	writeData.c
	create by Nutchanon Veraphichkasem 60070503422
	7 December 2017
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../MAIN/movie.h"

#define DATABASE "DATABASE.txt"

/*void removeNewline(char *input)
{
	if(input[strlen(input) - 1] == '\n')
	{
		input[strlen(input) - 1] = '\0';	
	}
}*/

void readBuffer(char *buffer, MOVIE_T *movie)
	{
	char *token = NULL;
	int count = 0;
	
	token = strtok(buffer, "[]");
	while(token != NULL)
        {
		if(strcmp(token, " ") != 0)
		{
			if(count==0)
				strcpy(movie[i].title, token);
			else if(count==1)
				strcpy(movie[i].actor, token);
			else if(count==2)
				strcpy(movie[i].category, token);
			else if(count==3)
				strcpy(movie[i].language, token);
			else if(count==4)
				strcpy(movie[i].releaseDate, token);
			else if(count==5)
				strcpy(movie[i].seenDate, token);
			else if(count==6)
				strcpy(movie[i].viewMethod, token);
			else if(count==7)
				strcpy(movie[i].Rating, token);

			count++;
			}
		token = strtok(NULL, "[]");
		}
	}

void writeDatabase(MOVIE_T *movie, int *header)
{
	FILE*inputFile = NULL;
	int i;

	inputFile = fopen("../DATABASE.txt", "w");
	if(inputFile == NULL)
	{
		printf("Error opening file, file not found\n")
		exit(1);
	}
	fprintf(inputFile,"%d\n",header);
	for(i = 0; i < header; i++)
	{
		fprintf(inputFile,"[%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%d]\n", movie[i].title
											, movie[i].actor
											, movie[i].language
											, movie[i].releaseDate
											, movie[i].seenDate
											, movie[i].viewMethod
											, movie[i].Rating);
	}
	fclose(inputFile);
}

void driverFunction()
{
	
}
/*int main()
	{
	char buffer[4096];
	int header[2] = {0,0};
	MOVIE_T *movie = NULL;
	FILE *inputFile = NULL;

	inputFile = fopen("../DATABASE.txt", "r");
	if(inputFile == NULL)
	{
		printf("Cannot open the file!\n");
		exit (1);
	}
	sscanf(buffer, "%d %d", &header[0], &header[1]);
	/* allocate memories for hold each data */
	/*movie = (MOVIE_T*) calloc(header[1], sizeof(MOVIE_T));
	/* if can't reserve memories display error and exit */
	/*if(movie == NULL)
	{
		printf("Cannot allocate memories\n");
		exit(2);
	}
 
	
	while(fgets(buffer,sizeof(buffer),inputFile) != NULL)
	{
		removeNewline(buffer);
		readBuffer(buffer, movie);
		printf("[%s] [%s] [%s] [%c] [%s] [%s] [%s] [%s] [%s] [%d]\n", movie[i].title
														, movie[i].actor
														, movie[i].language
														, movie[i].releaseDate
														, movie[i].seenDate
														, movie[i].viewMethod
														, movie[i].Rating);
		
	}
	fclose(inputFile);
	writeDatabase(movie, header);

	return 0;
	}*/



