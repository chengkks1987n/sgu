#sorce file
SRC = sgu.c
CASE = case.c

CC = gcc
FLAG = -g -Wall

all:	sgu

clean:
	rm *.o 
	rm *~ 
	rm *#
	rm  #*
	rm sgu case

sgu : $(SRC)
	${CC} $(FLAG) -o sgu $(SRC)

case : $(CASE)
	${CC} $(FLAG) -o case $(CASE)
