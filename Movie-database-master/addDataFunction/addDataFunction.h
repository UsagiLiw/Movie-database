/**********************************************
addDataFunction.h 
contain function that use in addData.c
create by Nutchanon Veraphichkasem 60070503422
7 December 2017
***********************************************/	

/*This function ask for movie name, if user didn't anything,
 it will loop until user enter something*/
void getMovie(char*movie);

/*This function get first and lastname of the actor
and check if the user input alphabet or number
if the user enter number - let user enter again*/
void getActorName(char*name);

/*This function get the release date of the movie
in term of YYYY/MM/DD if the user input others from
or invalid amount of day,month and year, return error
and ask again*/
void getRelease(int*release);

/*This function get the category of the movie
if the category user input isn't on the list 
show error message and ask again*/
void getCategory(char*category);

/*This function ask the language of the movie
if the language user input isn't on the list print 
error and ask again.*/
void getLanguage(char*language);

/*This function get the date user watched the movie
if the user haven't watch the movie yet, leave this blank*/
void getWatchdate(char*watch);

/*This function get the method user watch the movie
if the user haven't watch the movie yet, this function will be unavilable*/
void getMethod(char*method);

/*This function get the rating user rate this movie
if the user haven't watch the movie yer, this function will be unavilable*/
void getRating(int*rating);

/*This function use to check the date of today
if the user enter the date they watched the movie in the future date
this function will checked it as error and ask the user to input again*/
void dateToday(int* pDay, int *pMonth, int* pYear);

/*This function remove every new line user input the data and they press enter*/
void removeNewline(char *input);


