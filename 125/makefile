#sorce file
SRC = sgu.c
#on linux
#DIR = ~/tmp
#on windows
DIR = ./tmp

CC = gcc
FLAG = -g -Wall

all:	sgu

clean:
	rm -f *.o *~ *# 

sgu : $(SRC)
	${CC} $(FLAG) -o $(DIR)/sgu $(SRC)

run: sgu
	$(DIR)/sgu
