#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int titleSearch(MOVIE* movie, int* header, char inputSearch)
{
	char tmpName[128];
	int* position;
	int count = 0;
	int i = 0;

	for(i=0; i < header; i++)
	{
		strcpy(tmpName, movie->name);
		if(strstr(tmpName, search) != NULL)
		{
			checkName = strstr(tmpName, search) - tmpName;
			if(checkName == 0)
			{
           		count++;
				position[count] = i;
			}
		}
	}
	displaySearch(count, position)
}
int actorSearch(MOVIE* movie, int* header, char inputSearch)
{
	int* position;
}
int categorySearch(MOVIE* movie, int* header, char inputSearch)
{
	int* position;
}
int releaseSearch(MOVIE* movie, int* header, char inputSearch)
{
	int* position;
}

int displaySearch(int count, int* position)
{
    char input[64];
    char choice[64];
    int j;
	int which;
    
	if(count > 0)
    {
    /* ask user which data user want to display */
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
        	printf("Enter your choice:")
        	fgets(choice, sizeof(choice), stdin);
        	if(choice < 0 || choice > 2)
        	{
            	printf("Choice invalid\n");
        	}
        	if(choice == 0)
        	{
            	break;
        	}
        	if(choice == 1)
        	{
				editData(movie, header, position[which]);
        	}
        	if(choice == 2)
        	{
			do
			{
				printf("= Do you want to delete this data? (y/n): ");
				fgets(input,sizeof(input),stdin);
				removeNewline(input);
				input[0] = tolower(input[0]);
			}while(strlen(input) != 1 || (input[0] != 'y' && input[0] !='n'));
			if(input[0] == 'y')
			{
                /* call function to delete data */
				deleteData(patient, header, position[which]);
			}
			
        	
		}
    }
	break;
}
void searchData(MOVIE_T* movie, int* header, int choice)
{
    char inputSearch[256];
	
	
	position = (int*) calloc(header, sizeof(int));
	while(1)
	{
		memset(inputSearch, 0, sizeof(inputSearch));
       	if(choice == 1)
       	{
       	    printf("Enter movie title:");
       	    fgets(inputSearch, sizeof(inputSearch), stdin);
			titleSearch(movie, header, inputSearch)
       	}
       	if(choice == 2)
       	{
       	    printf("Enter actor name:");
       	    fgets(inputSearch, sizeof(inputSearch), stdin);
			actorSearch(movie, header, inputSearch)
       	}
       	if(choice == 3)
       	{
       	    printf("Enter Category:");
       	    fgets(inputSearch, sizeof(inputSearch), stdin);
			categorySearch(movie, header, inputSearch)
       	}
       	if(choice == 4)
       	{
       	    printf("Enter release year:");
       	    fgets(inputSearch, sizeof(inputSearch), stdin);
			releaseSearch(movie, bheader, inputSearch)
       	}
		if(count == 0)
   		{
       		printf("No data found\n");
   		}
	}
	if(count > 0)
        {
        /* ask user which data user want to display */
		do
		    {
			memset(input, 0, sizeof(input));
			printf("==== WHICH RECORD DO YOU WANT TO SEE: ");
		    fgets(input,sizeof(input),stdin);
			}while(atoi(input) < 1 || atoi(input) > count || isdigit(input[0]) == 0);
			sscanf(input, "%d", &which);
		displayEach(movie, position[which]);
}
int searchOption(MOVIE_T* movie, int *header)
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
        memset(choice, 0, sizeof(choice));
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
           	searchData(movie, header, choice);
        }
    }
}
