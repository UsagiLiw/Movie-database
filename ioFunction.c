#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"../MAIN/movie.h"
#include"ioFunction.h"

void readHeader(int*header)
{
	FILE*inputFile=NULL;
	inputFile=fopen(DATABASE.txt,"r");
	if(inputFile==NULL)
	{
		printf("Cannot open database\n");
		exit(1);
	}
	fclose(inputFile);
}

void readData(MOVIE_T*movie,int*header)
{
	FILE*inputFile=NULL;
	inputFile=fopen(DATABASE,"r");
	if(inputFile==NULL)
	{
		printf("Cannot open Datatbase file!\n");
		exit(1);
	}
	fclose(inputFile);
}

void writeData(MOVIE_T*movie,int*header)
{
	FILE*outputFile=NULL;
	outputFile=fopen(DATABASE,"w");
	if(outputFile==NULL)
	{
		printf("Cannot open open database file\n");
		exit(1);
	}
	fclose(inputFile);
}
