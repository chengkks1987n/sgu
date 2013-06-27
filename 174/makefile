#sorce file
SRC = sgu.c
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
