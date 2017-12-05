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
void getMovie(char*movie);
void getActorName(char*name);
void getRelease(int*release);
void getCategory(char category);
void getLanguage(char*language);
void getWatchdate(char*watch);
void getMethod(char*method);
void getRating(int*rating);
