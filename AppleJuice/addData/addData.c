/***************************************************************
	addData.c
	This program will get valid data from user
	Created by Nutchanon Veraphichkasem 60070503422
	7 December 2017
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../MAIN/movie.h"
#include "../movieValidate/movieValidate.h"
#include "../codeGen/codeGen.h"
#include "../writeData/writeData.h"
#include "addData.h"

/*
*	addData - This function will get the data from user with valid format.
*	Argument:	
*		addData - store data add by user 
*		header - record of amount of movie data
*/


void getTitle(char *movieCode, char *titleInput)
{
	char stringInput[256];		
	/*Ask for movie name*/
	
	do
	{
		printf("Please enter movie name\n");
		printf("Enter here : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		strcpy(titleInput, stringInput);
	}while(strlen(titleInput) == 0);
	generateCode(titleInput, movieCode);
}

void getActor(char *actorName)
{
	char stringInput[256];
	/*Ask for actor name and lastname*/

	do
	{
		printf("Please enter actor(s) name\n");
		printf("Example : 'Robert Downey Jr. , Tony Jaa'");
		printf("Enter here : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		strcpy(actorName, stringInput);
	}while(checkName(actorName) == 1);
}

void getCategory(char *category)
{
	char stringInput[256];
	int i = 0;
	/*Ask for category of the movie*/

	do
	{
		printf("Please enter category\n");
		printf("Category list : DRAMA , COMEDY , ACTION , ROMANCE , HORROR , CARTOON , OTHER\n");
		printf("Enter here : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		strcpy(category, stringInput);
		for(i = 0 ; i < strlen(category) ; i++)
		{
			category[i] = toupper(category[i]);
		}
	}while(checkCategory(category) == 1);
}

void getLanguage(char *language)
{
	char stringInput[256];
	int i = 0;
	/*Ask for movie's language*/
	do
	{
		printf("Please enter langauge of this movie\n");
		printf("Language list : ENGLISH , THAI , OTHER\n");
		printf("Enter here : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		strcpy(language, stringInput);
		for(i = 0 ; i < strlen(language) ; i++)
		{
			language[i] = toupper(language[i]);
		}
	}while(checkLanguage(language) == 1);
}

void getReleaseDate(char *releaseDate)
{
	char stringInput[256];
	/*Ask for movie's release date*/
	do
 	{
		printf("Please enter the release date here(YYYY-MM-DD)\n");
		printf("Enter here:");
		fgets(stringInput,sizeof(stringInput),stdin);
		strcpy(releaseDate,stringInput);
	}while(checkDate(releaseDate) == 1);
}

int getSeenDate(char *seenDate)
{
	char stringInput[256];
	int status = 0;
	/*Ask for the date user watch the movie*/
	do
	{
    	printf("Please enter the date you watched the movie(YYYY-MM-DD)\n");
    	printf("Enter here(Leave blank if haven't seen yet):");
    	fgets(stringInput,sizeof(stringInput),stdin);
    	strcpy(seenDate,stringInput);
    	if(strcmp(seenDate,"\n") == 0)
    	{
			printf("You haven't watch the movie\n");
      		status = 1;
    	}
	}while(checkSeenDate(seenDate) == 1);
	return status;
}

void getMethod(char *method)
{
	char stringInput[256];
	int i;
	/*Ask watched method of the user*/
	do
	{
    	printf("Please enter your viewing method here\n");
    	printf("Enter here:");
    	fgets(stringInput,sizeof(stringInput),stdin);
    	strcpy(method,stringInput);
		for(i = 0; i < strlen(method); i++)
    	{
      		method[i] = toupper(method[i]);
    	}
  	}while(checkMethod(method) == 1);
}

void getRating(int* rating)
{
  	char stringInput[256];
	/*Ask for user's rating of the movie*/
  	do
  	{
    	printf("Please enter the rating for the movie here(1-10)\n");
    	printf("Enter here:");
    	fgets(stringInput, sizeof(stringInput), stdin);
    	sscanf(stringInput,"%d",rating);
  	}while(checkRating(rating) == 1);
}


void addData(MOVIE_NT* newMovie,MOVIE_T* movie,int* count)
{
	char stringInput[256];
	char title[256];
	char movieCode[16];
	char actor[256];
	char category[100];		
	char language[100];		
	char releaseDate[20];	
	char seenDate[20];		
	char viewMethod[100];		
	int rating;			
	char yesNo;
	int watched = 0;
	int i = 0;

	movie = calloc(1, sizeof(MOVIE_NT));
	do
	{
		movie = realloc(movie, sizeof(movie)+sizeof(MOVIE_NT));
		/*Copy movie title and movie code to structure*/
		getTitle(movieCode, title);
		strcpy(movie[i].code, movieCode);
		strcpy(movie[i].title, title);
	
		/*Copy actor name to structure*/
		getActor(actor);
		strcpy(movie[i].actor, actor);

		/*Copy category to structure*/
		getCategory(category);
		strcpy(movie[i].category, category);
		
		/*Copy language to structure*/
		getLanguage(language);
		strcpy(movie[i].language, language);
		
		/*Copy release date to stucture*/
		getReleaseDate(releaseDate);
		strcpy(movie[i].releaseDate, releaseDate);	
	
		/*Copy seen date to structure*/
		watched = getSeenDate(seenDate);
		strcpy(movie[i].releaseDate, releaseDate);
		
		if(watched == 1)	/*If user input seen date*/
		{
			/*Copy view method to structure*/
			getMethod(viewMethod);	
			strcpy(movie[i].viewMethod, viewMethod);
			
			/*Copy rating to structure*/
			getRating(&rating);
			movie[i].Rating = rating;
		}

		do
		{
			printf("Do you want to add other movie? (y/n) : ");
			fgets(stringInput, sizeof(stringInput), stdin);
			sscanf(stringInput, "%c", &yesNo);
			if(yesNo = 'n')
			{
				break;
			}
		}while((yesNo != 'y') || (yesNo != 'n'));
		i++;	
	}while(yesNo == 'y');
	count = i+1;
}

