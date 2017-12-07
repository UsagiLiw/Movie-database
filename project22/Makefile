EXECUTABLES=./MAIN/movie

all : $(EXECUTABLES)

addData.o : ./addData/addData.c ./addData/addData.h
	gcc -c addData.c

codeGen.o : ./codeGen/codeGen.c ./codeGen/codeGen.h
	gcc -c codeGen.c

deletion.o : ./deletion/deletion.c ./deletion/deletion.h
	gcc -c deletion.c

displayData.o : ./displayData/displayData.c ./displayData/displayData.h
	gcc -c displayData.c

editFunction.o : ./editFunction/editFunction.c ./editFunction/editFunction.h
	gcc -c editFunction.c

ioFunction.o : ./ioFunction/ioFunction.c ./ioFunction/ioFunction.h
	gcc -c ioFunction.c

movieValidate.o : ./movieValidate/movieValidate.c ./movieValidate/movieValidate.h
	gcc -c movieValidate.c

search.o : ./search/search.c ./search/search.h
	gcc -c search.c

writeData.o : ./writeData/writeData.c ./writeData/writeData.h
	gcc -c writeData.c

movie.o : ./MAIN/movie.c ./MAIN/movie.h 
	gcc -c movie.c

movie : movie.o addData.o codeGen.o deletion.o displayData.o editFunction.o ioFunction.o movieValidate.o search.o writeData.o
	gcc -o movie movie.o addData.o codeGen.o deletion.o displayData.o editFunction.o ioFunction.o movieValidate.o search.o writeData.o

clean:
	-rm *.o
	-rm movie

