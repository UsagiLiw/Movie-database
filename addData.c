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
	strcpy(addData[i].title, input);

	getActorName(input);
	strcpy(addData[i].actor, input);

	getCategory(input);
	strcpy(addData[i].category, input);

	getLanguage(input);
	strcpy(addData[i].language, input);

	getRelease(input);
	strcpy(addDadta[i].releaseDate, input);

	getWatchdate(input);
	strcpy(addData[i].seenDate, input);

	getMethod(input);
	strcpy(addDadta[i].viewMethod, input);

	getRating(input);
	strcpy(addDadta[i].Rating, input);
}

