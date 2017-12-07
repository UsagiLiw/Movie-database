/***************************************************************
	IOFunction.c
	This program read and write the database file
	Created by Nutchanon Veraphcihkasem
	7 December 2017
 ***************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"../MAIN/movie.h"
#include"ioFunction.h"

/*	readHeader
	This function will read the header file
	Argument: header - amount of data
*/
void readHeader(int*header)
{
	FILE*inputFile=NULL;	/*pointer for input*/
	inputFile=fopen(DATABASE.txt,"r");	/*open file*/
	if(inputFile==NULL)
	{
		printf("Cannot open database, file not found\n");
		exit(1);
	}
	fclose(inputFile);
}

/*	readData
	This function will read the data file
	Argument: movie - stored data
			header - amount of data
*/
void readData(MOVIE_T*movie,int*header)
{
	FILE*inputFile=NULL;
	inputFile=fopen(DATABASE,"r");
	if(inputFile==NULL)
	{
		printf("Cannot read Datatbase file!,file not found\n");
		exit(1);
	}
	fclose(inputFile);
}

/*	writeData
	This function will write the data in to .txt file
	Argument: movie - data write to txt file
			header - amount of data
*/
void writeData(MOVIE_T*movie,int*header)
{
	FILE*outputFile=NULL;
	outputFile=fopen(DATABASE,"w");
	if(outputFile==NULL)
	{
		printf("Cannot open database, file not found\n");
		exit(1);
	}
	fclose(inputFile);
}
