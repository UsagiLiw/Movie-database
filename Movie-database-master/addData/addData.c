/***************************************************************
	addData.c
	This program will get valid data from user
	Created by Nutchanon Veraphichkasem 60070503422
	7 December 2017
****************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"../addDataFunction/addDataFunction.h" 
#include"../MAIN/movie.h"

/*
*	addData - This function will get the data from user with valid format.
*	Argument:	
*		addData - store data add by user 
*		header - record of amount of movie data
*/

void addData(MOVIE_T*addData,int*header)
{
	char input[MAXBUFFER];

	memset(input, 0, sizeof(input));
	/*Ask for movie name*/
	getMovie(input);
	strcpy(addData[i].title, input);

	/*Ask for actor name and lastname*/
	getActorName(input);
	strcpy(addData[i].actor, input);

	/*Ask for category of the movie*/
	getCategory(input);
	strcpy(addData[i].category, input);

	/*Ask for movie's language*/
	getLanguage(input);
	strcpy(addData[i].language, input);

	/*Ask for movie's release date*/
	getRelease(input);
	strcpy(addData[i].releaseDate, input);

	/*Ask for the date user watch the movie*/
	getWatchdate(input);
	strcpy(addData[i].seenDate, input);

	/*Ask watched method of the user*/
	getMethod(input);
	strcpy(addData[i].viewMethod, input);

	/*Ask for user's rating of the movie*/
	getRating(input);
	strcpy(addData[i].Rating, input);
}

