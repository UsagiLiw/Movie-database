/* deletion.c : Delete line from the data
* By Bhimapaka Thapanangkun 
* ID: 60070503447
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../MAIN/movie.h"
#include "../movieValidate/movieValidate.h"
#include "deletion.h"

/*deleteData function: Delete specific line from the file specify by user
*/
void deleteData(MOVIE_T *movie, int *header, int position)
{
	int i = 0; 

    /*Move up the data for one line*/
	for(i = position; i < header[0]-1; i++)
	{
		memcpy((movie+i), (movie+i+1), sizeof(MOVIE_T));
	}
    /*Delete the duplicate information in the last line*/
	if(i == header[0]-1)
	{
		memset((movie+i), 0, sizeof(MOVIE_T));
	}
    /*Reallocate memory that was decreased*/
	movie = (MOVIE_T*) realloc(movie, sizeof(MOVIE_T)*(header[0]-1));
	if(movie == NULL)
	{
		printf("ERROR: Cannnot allocate memories!\n");
		free(movie);
		movie = NULL;
		exit (1);
	}
	else
	{
		header[0] -= 1;
		printf("DELETE COMPLETE\n");
	}
}

