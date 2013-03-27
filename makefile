CC = gcc

compile:	sgu.c
	${CC} -c -g sgu.c
	${CC} -o sgu sgu.o

clean:	
	rm -f *.o *~ sgu