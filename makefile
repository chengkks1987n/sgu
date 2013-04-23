SRC = 142.c
CASE = 142case.c
SAMPLE = 142sample.c

CC = gcc
FLAG = -g -Wall

all:	sgu

cleanall: clean		
	rm -f sgu in.txt case sample

clean:
	rm -f *.o *~ *# 

test: sgu case sample
	./case
	./sgu
	./sample

case: $(CASE)
	gcc -o case 142case.c

sample : $(SAMPLE)
	gcc -o sample 142sample.c

sgu : $(SRC)
	${CC} $(FLAG) -o sgu $(SRC)
