SRC = 142.c			#sorce file
CASE = 142case.c		#test case create file
SAMPLE = 142sample.c		#sample file, the result must be right.

CC = gcc
FLAG = -g -Wall

all:	sgu

cleanall: clean		
	rm -f sgu in.txt case sample sgu.txt sample.txt

clean:
	rm -f *.o *~ *# 

test: sgu case sample test.sh
	./test.sh

case: $(CASE)
	gcc -o case $(CASE)

sample : $(SAMPLE)
	gcc -o sample $(SAMPLE)

sgu : $(SRC)
	${CC} $(FLAG) -o sgu $(SRC)
