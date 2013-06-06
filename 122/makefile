#sorce file
SRC = sgu.cpp
#on windows os,it is different
DIR = ~/tmp

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
