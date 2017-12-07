#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void generateCode(char inFileName[],char movieName[])
{
	FILE* pIn = NULL;	
	char stringInput[256];
	/*char movieName[128];*/
	char tempMovie[128];
	int length = 0;
	char movieCode[14];
	char existCode[14];
	int movieNum = 0;
	int existNum = 0;
	int i = 0;
	int j = 0;

	/*printf("Please Enter the movie name:");
	fgets(stringInput,sizeof(stringInput),stdin);
	strcpy(movieName,stringInput);*/
	/*Delete space from string*/
	for(i = 0, j = 0 ; j < 10 ; i++)
	{ 
		while(isspace(movieName[i]) != 0)
		{
			i++;	
		}
		tempMovie[j] = movieName[i];
		j++;
	}
	//printf("%s\n",tempMovie);
	/*Make all character into uppercase*/
	length = strlen(tempMovie);
	for(i = 0 ; i < length ; i++)
	{
		tempMovie[i] = toupper(tempMovie[i]);
	}
	//printf("%s\n",tempMovie);
	memset(movieCode,'_',10);
	memset(movieCode+10,':',1);
	memset(movieCode+11,'0',2);	
	for(i = 0 ; i < 10 ; i++)
	{
		movieCode[i] = tempMovie[i];
	}
	if(length < 10)
	{
		memset(movieCode+length,'_',10-length);
	}
	printf("%s\n",movieCode);
	pIn = fopen(inFileName, "r");
	while(fgets(stringInput,sizeof(stringInput),pIn) != NULL)
	{
		sscanf(stringInput, "[%s]", existCode);	//Beware! else sscanf(stringInput, "%s", existCode);
		if(strncmp(existCode+1, movieCode,10) == 0)
		{
			printf("Found same movie Code!\n");
			sscanf(&existCode[12], "%d",&existNum);
			if(existNum > movieNum)
			{
				movieNum = existNum;
			}
		}
	}
	movieNum++;
	sprintf(&movieCode[12], "%02d", movieNum);
	printf("%s\n",movieCode);
}
