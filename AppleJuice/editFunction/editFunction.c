/*
*		editFunction.c
*		Create By : Nonthakorn Sukprom 60070503435
*		7 December 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../MAIN/movie.h"
#include "../addData/addData.h"
#include "../search/search.h"
#include "editFunction.h"

void editFunction(MOVIE_NT* newMovie,MOVIE_T* movie, int* position, int* header, int which)
{
		char terminalInput[258];
		char title[256];
		char code[16];
		char actor[256];
		char release[100];
		char category[100];
		char language[100];
		char releaseDate[20];
		char seenDate[20];
		char viewMethod[100];
		int rating;
		int choice;
		int count = 0;
		
		while(1)
		{
			printf("What do you want to edit? (Press return to stop)\n");
			printf("1. Movie Name\n");	
			printf("2. Actor Name\n");
			printf("3. Releae date\n");
			printf("4. Category\n");
			printf("5. Language\n");
			printf("6. Watch date\n");
			printf("7. Watching Method\n");
			printf("8. Rating\n");
			fgets(terminalInput,sizeof(terminalInput),stdin);
			if(strcmp(terminalInput, "\n") == 0)
			{
				break;
			}
			sscanf(terminalInput,"%d",&choice);
			switch(choice)
			{
				case 1 :
					getTitle(code, title);
					strcpy(movie[position[which]].code, code);
					break;
				case 2 :
					getActor(actor);
					break;
				case 3 :
					getReleaseDate(release);
					break;
				case 4 :
					getCategory(category);
					break;
				case 5:
					getLanguage(language);
					break;
				case 6:
					getSeenDate(seenDate);
					break;
				case 7 :
					getMethod(viewMethod);
					break;
				case 8 :
					getRating(rating);
					break;
				default :
					printf("Error - Command not found");
			}
		writeDatabase(newMovie,movie, header, count);

		}
}
