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
void deleteData(MOVIE_T *movieT, int *header, int position)
{
	int i = 0; 

    /*Move up the data for one line*/
	for(i = position; i < header[0]-1; i++)
	{
		memcpy((movieT+i), (movieT+i+1), sizeof(MOVIE_T));
	}
    /*Delete the duplicate information in the last line*/
	if(i == header[0]-1)
	{
		memset((movieT+i), 0, sizeof(MOVIE_T));
	}
    /*Reallocate memory that was decreased*/
	movieT = (MOVIE_T*) realloc(movieT, sizeof(MOVIE_T)*(header[0]-1));
	if(movieT == NULL)
	{
		printf("ERROR: Cannnot allocate memories!\n");
		free(movieT);
		movieT = NULL;
		exit (1);
	}
	else
	{
		header[0] -= 1;
		printf("DELETE COMPLETE\n");
	}
}

