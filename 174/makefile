#sorce file
SRC = sgu.c

CC = gcc
FLAG = -g -Wall

all:	sgu

clean:
	rm -f *.o *~ *# 

sgu : $(SRC)
	${CC} $(FLAG) -o sgu $(SRC)

run: sgu
	./sgu
