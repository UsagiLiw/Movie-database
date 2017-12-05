#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"../adddata/addDataFunction.h"

void addData(MOVIE_T*addData,int*header)
{
	char input[MAXBUFFER];
	memset(input, 0, sizeof(input));
	getMovie(input);
	strcpy(addDadta->title, input);

	getActorName(input);
	strcpy(addDadta->actor, input);

	getCategory(input);
	strcpy(addDadta->category, input);

	getLanguage(input);
	strcpy(addDadta->language, input);

	getRelease(input);
	strcpy(addDadta->releaseDate, input);

	getWatchdate(input);
	strcpy(addDadta->seenDate, input);

	getMethod(input);
	strcpy(addDadta->viewMethod, input);

	getRating(input);
	strcpy(addDadta->Rating, input);
}

