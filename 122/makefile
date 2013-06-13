#sorce file
SRC = sgu2.cpp
#on linux
#DIR = ~/tmp
#on windows
DIR = ./tmp


CC = g++
FLAG = -g -Wall

all:	sgu

cleanall: clean		
	rm -f $(DIR)/*

clean:
	rm -f *.o *~ *# 

sgu : $(SRC)
	${CC} $(FLAG) -o $(DIR)/sgu $(SRC)

run: sgu
	$(DIR)/sgu
