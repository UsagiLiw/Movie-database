# Makefile 
# Makefile for movie database.
# Created by Bhimpaka Thapanangkun , Nonthakorn Sukprom
# ID: 60070503447 , 60070503435

# command for compile
COMPILE = gcc -Wall -o

# declaration name of each function and directory

MAIN_FUNCTION = movie
PATH_0 = ./MAIN/$(MAIN_FUNCTION)

FUNCTION_1 = ioFunction
PATH_1 = ./$(FUNCTION_1)/$(FUNCTION_1)

FUNCTION_2 = displayData
PATH_2 = ./$(FUNCTION_2)/$(FUNCTION_2)

FUNCTION_3 = search
PATH_3 = ./$(FUNCTION_3)/$(FUNCTION_3)

FUNCTION_4 = movieValidate
PATH_4 = ./$(FUNCTION_4)/$(FUNCTION_4)

FUNCTION_5 = editFunction
PATH_5 = ./$(FUNCTION_5)/$(FUNCTION_5)

FUNCTION_6 = deletion
PATH_6 = ./$(FUNCTION_6)/$(FUNCTION_6)

FUNCTION_7 = codeGen
PATH_7 = ./$(FUNCTION_7)/$(FUNCTION_7)

FUNCTION_8 = addData
PATH_8 = ./$(FUNCTION_8)/$(FUNCTION_8)

FUNCTION_9 = writeData
PATH_9 = ./$(FUNCTION_9)/$(FUNCTION_9)

ALL = $(PATH_0).c $(PATH_0).h $(PATH_1).c $(PATH_1).h $(PATH_2).c $(PATH_2).h $(PATH_3).c $(PATH_3).h $(PATH_4).c $(PATH_4).h $(PATH_5).c $(PATH_5).h $(PATH_6).c $(PATH_6).h $(PATH_7).c $(PATH_7).h $(PATH_8).c $(PATH_8).h $(PATH_9).c $(PATH_9).h

all: make
	
# compile and run program
make: $(ALL)
	@echo COMPILING...
	@$(COMPILE) $(MAIN_FUNCTION) $(PATH_0).c $(PATH_1).c $(PATH_2).c $(PATH_3).c $(PATH_4).c $(PATH_5).c $(PATH_6).c $(PATH_7).c $(PATH_8).c $(PATH_9).c
	@echo OPENING $(MAIN_FUNCTION)
	@./$(MAIN_FUNCTION)
	@echo FINISHED.

clean:
	@-rm $(MAIN_FUNCTION)
	@echo $(MAIN_FUNCTION) DELETED.
