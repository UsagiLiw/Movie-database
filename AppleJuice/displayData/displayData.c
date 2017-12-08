/*********************************************
*displayData.c
*
*This program is for display all data or data from search
*
*create by Thanapat Sakaehao
*		 60070503430
**********************************************/
#include <stdio.h>

#include "../MAIN/movie.h"
#include "displayData.h"

/* display one data */
void displayEach(MOVIE_T *movie, int which)
{
	printf("Movie code       : %s\n", movie[which].code);
	printf("Movie title      : %s\n", movie[which].title);
	printf("Actor            : %s\n", movie[which].actor);
	printf("Category         : %s\n", movie[which].category);
	printf("Language         : %s\n", movie[which].language);
	printf("Release date     : %s\n", movie[which].releaseDate);
	printf("Date seen        : %s\n", movie[which].seenDate);
	printf("Viewing method   : %s\n", movie[which].viewMethod);
	printf("Rating			: %d\n", movie[which].Rating);
	printf("==========================================================\n");
}

/* display all data */
void displayData(MOVIE_T *movie, int *header)
{
	int i; /* loop counter */
	for(i = 0; i < header[0]; i++)
	{
		displayEach(movie, i);
	}
	printf("==== There are %d movie(s) in database.\n\n", header[0]);
}
