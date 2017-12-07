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

void removeNewline(char *input)
{
	if(input[strlen(input) - 1] == '\n')
	{
		input[strlen(input) - 1] = '\0';	
	}
}

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

void writeDatabase(MOVIE_T *movie,int *header)
    {
	FILE *outputFile = NULL; 
	outputFile = fopen(DATABASE, "w");
	if(outputFile == NULL)
	{
        printf("can't open output file\n");
        exit(1);
	}

    fclose(outputFile);
    }
