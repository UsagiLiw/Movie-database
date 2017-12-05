#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

void getMovie(char*movie)
{

	char input[128];
	do
	{
	printf("--------------------\n");
	printf("ENTER MOVIE NAME:");
	fgets(input,sizeof(input),stdin);
	}
	while(strcasecmp(input,\n)==0);
	strcpy(movie,input);
	
}

void getActorName(char*name)
{
	char input[128];
	do
	{
	printf("--------------------\n");
	printf("ENTER THE ACTOR NAME:");
	fgets(input,sizeof(input),stdin);
	}
	while(checkName(input)!=0);
	strcpy(name,input);
}

void getRelease(int*release)
{
	char input[128];
	do
	{
	printf("--------------------\n");
	printf("ENTER THE RELEASE YEAR:");
	fgets(input,sizeof(input),stdin);
	}
	while(checkDate(input)!=0);
	strcpy(year,input);
}

void getCategory(char*category)
{
	char input[128];
	do
	{
	printf("--------------------\n");
	printf("ENTER MOVIE CATEGORY:");
	fgets(input,sizeof(input),stdin);
	}
	while(checkLetter(input)!=0);
	strcpy(year,input);
}

void getLanguage(char*language)
{
	do
	{
	printf("--------------------\n");
	printf("ENTER MOVIE LANGUAGE:");
	fgets(input,sizeof(input),stdin);
	}
	while(checkLetter(input)!=0);
	strcpy(year,input);
}

void getWatchdate(char*watch)
{
	char input[128];
	do
	{
	printf("--------------------\n");
	printf("ENTER WATCH DATE:");
	fgets(input,sizeof(input),stdin);
	}
	while(checkSeenDate(input)!=0);
	strcpy(year,input);
}

void getMethod(char*method)
{
	char input[128];
	do
	{
	printf("--------------------\n");
	printf("ENTER METHOD:");
	fgets(input,sizeof(input),stdin);
	}
	while(checkLetter(input)!=0);
	strcpy(year,input);
}

void getRating(int*rating)
{
	do
	{
	printf("--------------------\n");
	printf("ENTER MOVIE RATING:");
	fgets(input,sizeof(input),stdin);
	}
	while(checkNumber(input)!=0);
	strcpy(year,input);
}
