SRC = 142.c

CC = gcc
FLAG = -g -Wall
TARGET = sgu

all:	
	${CC} $(FLAG) -o $(TARGET) $(SRC)

clean:	
	rm -f *.o *~ sgu *#


