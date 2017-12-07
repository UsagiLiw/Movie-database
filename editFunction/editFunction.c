#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../addDataFunction/addDataFunction.h"

int main()
{
		MOVIE_T movie;
		char terminalInput[258];
		int choice;
		
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
					getMovie(movie.title);
					break;
				case 2 :
					getActorName(movie.actor);
					break;
				case 3 :
					getRelease(movie.releaseDate);
					break;
				case 4 :
					getCategory(movie.category);
					break;
				case 5:
					getLanguage(movie.language);
					break;
				case 6:
					getWatchdate(movie.seenDate);
					break;
				case 7 :
					getMethod(movie.viewMethod);
					break;
				case 8 :
					getRating(movie.Rating);
					break;
				default :
					printf("Error - Command not found");
			}
		}
	return 0;
}
