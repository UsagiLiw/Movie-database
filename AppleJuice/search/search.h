int titleSearch(MOVIE_NT* newMovie, MOVIE_T* movie, int* header, char* search);
int actorSearch(MOVIE_NT* newMovie, MOVIE_T* movie, int* header, char search);
int categorySearch(MOVIE_NT* newMovie, MOVIE_T* movie, int* header, char search);
int releaseSearch(MOVIE_NT* newMovie, MOVIE_T* movie, int* header, char search);
void displaySearch(MOVIE_NT* newMovie, MOVIE_T* movie, int count, int* position, int* header);
void searchData(MOVIE_NT* newMovie, MOVIE_T* movie, int* header, int choice);
void searchOption(MOVIE_NT* newMovie, MOVIE_T* movie, int header);
