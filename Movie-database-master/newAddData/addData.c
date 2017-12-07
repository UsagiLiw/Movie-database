/***************************
*	AddData.c
*
*
*
*
***************************/
#include <stdio.h>
#include <stdliub.h>
#include <string.h>
#include <ctype.h>

#include "../MAIN/movie.h"
#include "../movieValidate/movieValidate.h"
#include "../codeGen/codeGen.h"
#include "../writeData/writeData.h"

void getTitle(char movieCode[], char titleInput[])
{
	char stringInput[256];		
	
	do
	{
		printf("Please enter movie name : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		strcpy(titleInput, stringInput);
	}while(strlen(titleInput) == 0);
	generateCode(titleInput, movieCode);
}

void getActor(char actorName[])
{
	char stringInput[256];
	
	do
	{
	}while(checkName(actorName))
}
void addData(MOVIE_NT *movie[])
{
	char title[256];
	char movieCode[16];

	getTitle(movieCode, title);
	
}
