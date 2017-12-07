/*********************************************************************
	addDatafunction.c
	This file contain all functions that use with addData.c
	create by Nutchanon Veraphichkasem 60070503422
	7 December 2017
***********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#include"movieValidate.h"

/*getMovie function
	this function will ask user a movie's name
	and if the user didn't put in anything it will ask again
	Argument : 
	name : get input from user
	no return
*/
void getMovie(char*movie)
{

	char input[128];
	/*get movie name*/
	do
	{
		printf("--------------------\n");
		printf("ENTER MOVIE NAME:");
		fgets(input,sizeof(input),stdin);
	}
	/*if input not met condition, loop again*/
	while(strcasecmp(input,"\n")==0);
	strcpy(movie,input);
	
}

/*getActorName function
	this function will ask user a actor's name and lastname
	and if the user input wrong format or don't met the condition
	it will ask again
	Argument : 
	name : get input from user
	no return
*/
void getActorName(char*name)
{
	char input[128];
	/*get actor name and lastname*/
	do
	{
		printf("--------------------\n");
		printf("Enter the name and last name of the actor\n");
		printf("If there are more than one acter user want to add, use (comma)"," before enter the next name\n");
		printf("ENTER THE ACTOR NAME:");
		fgets(input,sizeof(input),stdin);
	}
	/*if input not met condition, loop again*/
	while(checkName(input)!=0);
	strcpy(name,input);
}

/*getRelease function
	this function will ask user a movie's name
	and if the user didn't put in anything it will ask again
	Argument : 
	name : get input from user
	no return
*/
void getRelease(char*release)
{
	char input[128];
	do
	{
		printf("--------------------\n");
		printf("Enter the movie's release date in term of YYYY/MM/DD i\n");
		printf("ENTER THE RELEASE YEAR:");
		fgets(input,sizeof(input),stdin);
	}
	/*if input not met condition, loop again*/
	while(checkDate(input)!=0);
	strcpy(release,input);
}

/*getCategory function
	this function will ask movie's category
	and if the user input wrong type of format, it will ask again
	if the input are not in the list, ask again.
	Argument : 
	name : get input from user
	no return
*/
void getCategory(char*category)
{
	char input[128];
	int i;
	do
	{
		printf("--------------------\n");
		printf("Enter the category of the movie from the list\n");
		printf("list of category avilable: DRAMA,COMEDY,ACTION,ROMANCE,HORROR,CARTOON,OTHER\n");
		printf("ENTER MOVIE CATEGORY:");
		fgets(input,sizeof(input),stdin);
		/*change user input to upper case character
		and user function checkCategory to check if the
		input met the condition*/
		for(i=0;i<strlen(input);i++)
		{
			isupper(input[i]);
		}
	}
	while(checkCategory(input)!=0);
	strcpy(category,input);
}

/*getLanguage function
	this function will ask user a movie's language
	and if the user didn't put in anything it will ask again
	if the input are not in the list, ask again.
	Argument : 
	name : get input from user
	no return
*/
void getLanguage(char*language)
{
	char input[128];
	int i;
	do
	{
		printf("--------------------\n");
		printf("Enter the language of the movie from the list\n");
		printf("list of language avilable: ENGLISH,THAI,OTHER\n");
		printf("ENTER MOVIE LANGUAGE:");
		fgets(input,sizeof(input),stdin);
		/*change user input to upper case character
		and user function checkLanguage to check if the
		input met the condition*/
		for(i=0;i<strlen(input);i++)
		{
			isupper(input[i]);
		}
	}
	while(checkLanguage(input)!=0);
	strcpy(language,input);
}

/*getWatchdate function
	this function will ask date user watched the movie
	and if the user didn't put in anything it will ask again
	if the input date is in the future return error and ask again
	Argument : 
	name : get input from user
	no return
*/
void getWatchdate(char*watch)
{
	char input[128];
	while(1)
	{
		printf("--------------------\n");
		printf("Enter the date user watched the movie (MUST NOT BE IN THE FUTURE)\n");
		printf("ENTER WATCH DATE:");
		fgets(input,sizeof(input),stdin);
	}
	while(checkSeenDate(input)!=0);
	strcpy(watch,input);
}

/*getMethod function
	this function will ask method user use to watched the movie
	and if the user didn't put in anything it will ask again
	if the input are not alphabet return error and ask again
	Argument : 
	name : get input from user
	no return
*/
void getMethod(char*method)
{
	char input[128];
	do
	{
		printf("--------------------\n");
		printf("Enter the method user used when watched the movie (ex. cinema,internet,DVD)\n");
		printf("ENTER METHOD:");
		fgets(input,sizeof(input),stdin);
	}
	while(checkMethod(input)!=0);
	strcpy(method,input);
}

/*getRating function
	this function will ask rating the user give to the movie they watched
	and if the user didn't put in anything it will ask again
	if the input are not digit between 1 to 10 return error and ask again
	Argument : 
	name : get input from user
	no return
*/
void getRating(int*rating)
{
	char input[128];
	int rate;
	do
	{
		printf("--------------------\n");
		printf("Enter the rating user give to the movie (Rating between 1 - 10)\n");
		printf("ENTER MOVIE RATING:");	/*Enter num from 1 - 5*/
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&rate);
	}
	while(checkRating(rate)!=0);
	
}

