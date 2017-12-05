/*By Bhimapaka Thapanangkun 60070503447
*movievalidate.c containing all validate function for movie database
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "movieFunctions.h"

/*dateToday function: This function will get the present date
*					  then store the date of today into pDay,pMonth and pYear
**/
void dateToday(int* pDay, int *pMonth, int* pYear)
{
    time_t seconds = 0;    
    struct tm * pTimeStruct;

    seconds = time(&seconds);
    pTimeStruct = localtime(&seconds);
    *pDay = pTimeStruct->tm_mday;
    *pMonth = pTimeStruct->tm_mon + 1;
    *pYear = pTimeStruct->tm_year + 1900;
}

/*removeNewline function
*This function will remove newline from the buffer.
*Argument : - input - buffer string*/
void removeNewline(char *input)
{
	if(input[strlen(input) - 1] == '\n')
	{
		input[strlen(input) - 1] = '\0';	
	}
}

/*checkName function: Check the input name from the user if it is allow or not
*It return 'check' variable:	1 - if the input is not valid
*								0 - if the input is valid*/
int checkName(char* name)
{
	int i; /* count loop */
	int check = 0;
	
	removeNewline(name);
	if(strlen(name) < 1) /* if name is blank */
	{
		check = 1;
	}
	else if(strlen(name) >= 1)
    {
		for(i = 0; i < strlen(name); i++)
        {
			if(!(isalpha(name[i]) || name[i] == '.' || name[i] == '-' || name[i] == '\'' || isspace(name[i])))
			{
				printf("\nInvalid -- only alphabets(A-Z), apostrophe('), dash(-), and period(.) are allowed\n");
				check = 1;
                break;
			}
        }
    }
    return check;
}

/*checkDate function: Check the input release date if the format is valid
*It return 'check' variable:	1 - if the input is not valid
*								0 - if the input is valid*/
int checkDate(char* inputDate)
{
	int tempDay = 0; 			/* to collect day that divided from inputDate */
	int tempMonth = 0;		 	/* to collect month that divided from inputDate */
	int tempYear = 0; 			/* to collect year that divided from inputDate */
	int check = 0; 				/* return value is it correct format or not */
	int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; /* to check max days in each month */
	int maxDay = 0; 			/* max day in each month */
	int i = 0; 					/* count loop */


	removeNewline(inputDate);
	if(strlen(inputDate) != 10) /* if date length is not 10 -- INVALID */
	{
		printf("INVALID FORMAT - MUST BE YYYY/MM/DD\n");
		check = 1;
	}
	else if((inputDate[4] != '/') || (inputDate[7] != '/')) /* if do not have slash '/' -- INVALID  */
	{
		printf("INVLAID FORMAT - MUST BE YYYY/MM/DD\n");
		check = 1;
	}
	else 
	{
		for(i=0; (i < 10) && (check == 0) ; i++)
		{
			if(i == 2 || i == 5) /* do not interset '/' */
			{
			continue;
			}
			else if(!isdigit(inputDate[i])) /* date is digit or not */
			{
				printf("INVALID INPUT - ONLY NUMERIC VALUE\n");
				check = 1;
			}
		}
	}
	if(check == 0) 
	{
		sscanf(inputDate,"%d/%d/%d",&tempYear,&tempMonth,&tempDay); /* Collect inputDate into YYYY/MM/DD format */
		if(tempMonth < 1 || tempMonth > 12) /*Month must be within 1 to 12*/
		{
			printf("INVALID DATE\n");
			check = 1;
		}
		else 
		{
			maxDay = monthDays[tempMonth-1]; /* collect maxDay in each month to this variable */
			if((tempMonth == 2) && (tempYear%4 == 0) && (tempYear%100 != 0)) /* if it is leap year */
			{
				maxDay = 29; /* change maxDay in February to 29 days */
			}
			if((tempDay < 1) || (tempDay > maxDay))
			{
				printf("INVALID DATE\n");
				check = 1;
			}
		}
	}

	return check;
}

/*dateCompare function: compare date input to the date today
*return 'check' value: 1 - if the input is over the date today
*					   0 - if the input is under the date today*/
int dateCompare(int day1,int month1,int year1, 
                int day2,int month2,int year2)
{
    int check = 0;

	if((day1 > day2) || (month1 > month2) || (year1 > year2))
	{
		check = 1;
		printf("INVALID DATE: Seen date cannot be in the future");
	}

    return check;
}    

/*checkSeenDate function: Check if date that the user input is within the present or the past
*return 'check' value: 1 - if the input is over the date today
*					   0 - if the input is under the date today*/
int checkSeenDate(char* inputDate)
{
	int check = 0;
	int tempDate,tempMonth,tempYear,pDay,pMonth,pYear;
	
	dateToday(&pDay,&pMonth,&pYear);
	if(checkDate(inputDate) == 0)
	{
		sscanf(inputDate,"%d/%d/%d",&tempYear,&tempMonth,&tempDate);		/* Collect inputDate into YYYY/MM/DD format */
		check = dateCompare(tempDate,tempMonth,tempYear,pDay,pMonth,pYear);	/* Compare seen date with the date today*/		
	}
	else
	{
		check = 1;
	}
	
	return check;
}

/*checkLetter function: Check if the input data is alphabet for every characters.
*return 'check' value: 1 - if the input is over the date today
*					   0 - if the input is under the date today*/
int checkLetter(char* letterString)
{
	int i,length;
	int check = 0;
	
	removeNewline(letterString);
	if(strlen(letterString) < 1) /* if name is blank */
	{
		check = 1;
	}
	else if(strlen(letterString) >= 1)
    {
		for(i = 0; i < strlen(letterString); i++)
        {
			if(isalpha(letterString[i]) == 0)
			{
				printf("\nINVALID FORMAT: Must contain alphabets only\n");
				check = 1;
                break;
			}
        }
    }
    return check;
}

int main()
{
	printf("Hello World\n");
	return 0;
}


