/*movieFunctions.h
*Created by Bhimpaka Thapanangkun 60070503447
*
*Update1: Include structure for universal use of the program/

/*Define a structure to hold data for each movie*/
typedef struct
	{
	char code[16];			/*Movie Code generated from input movie name*/
	char title[256];		/*Movie name*/
	char actor[256];		/*The name of the actor*/
	char category[100];		/*Category of the movie*/
	char language[100];		/*Language used in the movie*/
	char releaseDate[20];		/*The release date of the movie*/
	char seenDate[20];		/*Date that the user watched*/
	char viewMethod[100];		/*The method of watching the movie*/
	int Rating;			/*How much user rate the movie*/
	} MOVIE_T;	

/*dateToday function: This function will get the present date
*					  then store the date of today into pDay,pMonth and pYear
**/
void dateToday(int* pDay, int *pMonth, int* pYear);

/*removeNewline function
*This function will remove newline from the buffer.
*Argument : - input - buffer string*/
void removeNewline(char *input);

/*checkName function: Check the input name from the user if it is allow or not
*It return 'check' variable:	1 - if the input is not valid
*								0 - if the input is valid*/
int checkName(char* name);

/*dateCompare function: compare date input to the date today
*return 'check' value: 1 - if the input is over the date today
*					   0 - if the input is under the date today*/

/*checkDate function: Check the input release date if the format is valid
*It return 'check' variable:	1 - if the input is not valid
*								0 - if the input is valid*/
int checkDate(char* inputDate);

/*dateCompare function: compare date input to the date today
*return 'check' value: 1 - if the input is over the date today
*					   0 - if the input is under the date today*/
int dateCompare(int day1,int month1,int year1, 
                int day2,int month2,int year2);

/*checkSeenDate function: Check if date that the user input is within the present or the past
*return 'check' value: 1 - if the input is over the date today
*					   0 - if the input is under the date today*/
int checkSeenDate(char* inputDate);

/*checkLetter function: Check if the input data is alphabet for every characters.
*return 'check' value: 1 - if the input is over the date today
*					   0 - if the input is under the date today*/
int checkLetter(char* letterString);
int checkNumber(char* letterString);