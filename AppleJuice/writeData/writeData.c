/*
	writeData.c
	create by Nonthakorn Sukprom 60070503435
	7 December 2017
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../MAIN/movie.h"
#include "writeData.h"

#define DATABASE "DATABASE.txt"

void writeDatabase(MOVIE_NT *newMovie,MOVIE_T* movie, int header, int count)
{
	FILE* inputFile = NULL;
	int i;
	
	movie = calloc(header, sizeof(MOVIE_T));
	inputFile = fopen("../DATABASE.txt", "w");
	if(inputFile == NULL)
	{
		printf("Error opening file, file not found\n");
		exit(1);
	}
	fprintf(inputFile,"%d\n",header);
	for(i = 0; i < header; i++)
	{
		fprintf(inputFile,"[%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%d]\n", movie[i].code
											, movie[i].title
											, movie[i].actor
											, movie[i].category
											, movie[i].language
											, movie[i].releaseDate
											, movie[i].seenDate
											, movie[i].viewMethod
											, movie[i].Rating);
	}
	for(i = 0 ; i < count; i++)
	{
		fprintf(inputFile,"[%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%d]\n", movie[i].code
											, newMovie[i].title
											, newMovie[i].actor
											, newMovie[i].category
											, newMovie[i].language
											, newMovie[i].releaseDate
											, newMovie[i].seenDate
											, newMovie[i].viewMethod
											, newMovie[i].Rating);
	}
	
	
	fclose(inputFile);
}



