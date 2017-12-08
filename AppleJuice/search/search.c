/***********************************************
*search.c
*
*This program is for searching data and let user choose to edit or delete data
*
*create by Thanapat Sakaekhao
*		 60070503430
**********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../MAIN/movie.h"
#include "../addData/addData.h"
#include "../movieValidate/movieValidate.h"
#include "../deletion/deletion.h"
#include "../editFunction/editFunction.h"
#include "../displayData/displayData.h"
#include "search.h"
/* search by movie title */
int titleSearch(MOVIE_NT* newMovie, MOVIE_T* movie, int* header, char* search)
{
	char tmpTitle[128];
	int* position;
	int count = 0;
	int i;

	position = (int*) calloc(*header, sizeof(int));
	for(i=0; i < *header; i++)
	{
		strcpy(tmpTitle, movie[i].title);
		if(strstr(tmpTitle, search) != NULL)
		{
           	count++;
			printf("#%d - %s", count, movie[i].title);
			position[count] = i;
		}
	}if(count < 0)
   		{
			displaySearch(newMovie, movie, count, position, header);
		}
	if(count == 0)
   		{
       		printf("No data found\n");
   		}
}
/* search by actor */
int actorSearch(MOVIE_NT* newMovie, MOVIE_T* movie, int* header, char search)
{
	char tmpActor[128];
	int* position;
	int count = 0;
	int i;
	for(i=0; i < *header; i++)
	{
		strcpy(tmpActor, movie->actor);
		if(strstr(tmpActor, &search) != NULL)
		{
           	count++;
			printf("#%d - %s", count, movie->actor);
			position[count] = i;
		}
	}
	if(count < 0)
   		{
			displaySearch(newMovie, movie, count, position, header);
		}
	if(count == 0)
   		{
       		printf("No data found\n");
   		}displaySearch(newMovie, movie, count, position, header);
	return count;
}
/* searcch by category */
int categorySearch(MOVIE_NT* newMovie, MOVIE_T* movie, int* header, char search)
{
	char tmpCategory[128];
	int* position;
	int count = 0;
	int i;

	for(i=0; i < *header; i++)
	{
		strcpy(tmpCategory, movie->category);
		if(strstr(tmpCategory, &search) != NULL)
		{
           	count++;
			printf("#%d - %s", count, movie->category);
			position[count] = i;
		}
	}
	if(count < 0)
   		{
			displaySearch(newMovie, movie, count, position, header);
		}
	if(count == 0)
   		{
       		printf("No data found\n");
   		}
}
/* search by release date */
int releaseSearch(MOVIE_NT* newMovie, MOVIE_T* movie, int* header, char search)
{
	char tmpRelease[128];
	int* position;
	int count = 0;
	int i;
	for(i=0; i < *header; i++)
	{
		strcpy(tmpRelease, movie->releaseDate);
		if(strstr(tmpRelease, &search) != NULL)
		{
           	count++;
			printf("#%d - %s", count, movie->releaseDate);
			position[count] = i;
		}
	}
	if(count < 0)
   		{
			displaySearch(newMovie, movie, count, position, header);
		}
	if(count == 0)
   		{
       		printf("No data found\n");
   		}
}
/* send to display function and ask user what to do with data */
void displaySearch(MOVIE_NT* newMovie, MOVIE_T* movie, int count, int* position, int* header)
{
     char input[64];
	int choose;
     char choice[64];
	int which;
    
	if(count > 0)
	{
		do
		{
			memset(input, 0, sizeof(input));
			printf("Select data: ");
		    fgets(input,sizeof(input),stdin);
		}while(atoi(input) < 1 || atoi(input) > count || isdigit(input[0]) == 0);
		sscanf(input, "%d", &which);
		displayEach(movie, position[which]);
		while(1)
		{
    			if(count > 0)
    			{
        			printf("What do you want to do next:\n");
     	 		printf("1 - Edit\n");
        			printf("2 - Delete\n");
        			printf("0 - Exit\n");
        			printf("Enter your choice:");
        			fgets(choice, sizeof(choice), stdin);
				sscanf(choice, "%d", &choose);
        			if(choose < 0 || choose > 2)
        			{
          		  	printf("Choice invalid\n");
        			}
        			if(choose == 0)
        			{
          		 	break;
        			}
        			if(choose == 1)
        			{
					editFunction(newMovie, movie, position[which],header, which);
        			}
        			if(choose == 2)
        			{
					do
					{
						printf("Do you want to delete this data? (y/n): ");
						fgets(input,sizeof(input),stdin);
						removeNewline(input);
						input[0] = tolower(input[0]);
					}while(strlen(input) != 1 || (input[0] != 'y' && input[0] !='n'));
					if(input[0] == 'y')
					{
          	     	 /* call function to delete data */
						deleteData(movie, header, position[which]);
					}
					
        			}
			}	
    		}
		
	}	
	
}
/* seperate to each search funtion */
void searchData(MOVIE_NT* newMovie, MOVIE_T* movie, int* header, int choice)
{
	char input[128];
    char inputSearch[256];
	char search[256];

		memset(inputSearch, 0, sizeof(inputSearch));
       	if(choice == 1)
       	{
			getTitle(movie, inputSearch);
			strcpy(search, inputSearch);
			titleSearch(newMovie, movie, header, search);
       	}
       	if(choice == 2)
       	{
       	    getActor(inputSearch);
			strcpy(search, inputSearch);
			actorSearch(newMovie, movie, header, search);
       	}
       	if(choice == 3)
       	{
       	    getCategory(inputSearch);
			strcpy(search, inputSearch);
			categorySearch(newMovie, movie, header, search);
       	}
       	if(choice == 4)
       	{
       	    printf("Enter release year(Buddish year):");
       	    fgets(inputSearch, sizeof(inputSearch), stdin);
			strcpy(search, inputSearch);
			releaseSearch(newMovie, movie, header, search);
       	}
}
/* search menu */
void searchOption(MOVIE_NT* newMovie, MOVIE_T* movie, int header)
{
    char input[256];
    int choice;
    int i;

    while(1)
    {
	printf("========================================================\n");
        printf("Search Menu\n");
        printf("1 - Movie title\n");
        printf("2 - Actor\n");
        printf("3 - Category\n");
        printf("4 - Release Year(Buddish year)\n");
        printf("0 - Exit\n");
        printf("Enter your choice:");
        memset(input, 0, sizeof(input));
        fgets(input, sizeof(input), stdin);
        sscanf(input,"%d",&choice);
       	if(choice < 0 || choice > 9 || !(isdigit(input[i])))
        	{
           	printf("Your choice is not exist\n");
       	}
       	if(choice == 0)
       	{
           	break;
       	}
       	if(choice > 0 && choice <= 9)
       	{
           	searchData(newMovie, movie, header, choice);
        	}
    }
}
