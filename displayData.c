#include <stdio.h>

#include "diplayData.h"
void displayEach(MOVIE_T *movie, int which)
{
	printf("Movie code      : %s\n", movie[which].movieCode);
	printf("Movie title     : %s\n", movie[which].title);
	printf("Actor           : %s\n", movie[which].actor);
	printf("Category        : %s\n", movie[which].category);
	printf("Language        : %s\n", moive[which].language);
	printf("Release date    : %s\n", movie[which].releaseDate);
	printf("Date seen       : %s\n", movie[which].dateSeen);
	printf("Viewing method  : %s\n", movie[which].viewingMethod);
	printf("Rating   		: %s\n", movie[which].rating);
	printf("==========================================================\n");
}

void displayData(MOVIE_T *movie, int *header)
{
	int i; /* index */
	/* display all data */
	for(i = 0; i < header[0]; i++)
	{
		displayEach(movie, i);
	}
	printf("==== There are %d movie(s) in database.\n\n", header[0]);
}
