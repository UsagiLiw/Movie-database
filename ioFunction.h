/***********************************************************
	ioFunction.h 
	This function declares the function for ioFunction.c
	created by Nutchanon Veraphichkasem 60070503422
	7 December 2017
***********************************************************/
#define DATABASE "DATABASE.txt"

/*	readHeader
	This function will read the header file
	Argument: header - amount of data
*/
void readHeader(int*header);

/*	readData
	This function will read the data file
	Argument: movie - stored data
			header - amount of data
*/
void readData(MOVIE_T*movie,int*header);

/*	writeData
	This function will write the data in to .txt file
	Argument: movie - data write to txt file
			header - amount of data
*/
void writeData(MOVIE_T*movie,int*header);
