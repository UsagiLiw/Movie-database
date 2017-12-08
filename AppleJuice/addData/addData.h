/***************************************************************
	addData.h
	This header file declares function for addData.c.
	Created by Nutchanon Veraphichkasem 60070503422
	7 December 2017
****************************************************************/

/*
*	addData - This function will get the data from user with valid format.
*/

void addData(MOVIE_NT* newMovie,MOVIE_T* movie,int* count);
void getTitle(char *movieCode, char *titleInput);
void getActor(char *actorName);
void getCategory(char *category);
void getLanguage(char *language);
void getReleaseDate(char *releaseDate);
int getSeenDate(char *seenDate);
void getMethod(char *method);
void getRating(int* rating);

