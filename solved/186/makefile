SRC = sgu.c			#sorce file
CASE = case.c		#test case create file
SAMPLE = sample.c		#sample file, the result must be right.

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
	$(CC) -o case $(CASE)

sample : $(SAMPLE)
	$(CC) -o sample $(SAMPLE)

sgu : $(SRC)
	${CC} $(FLAG) -o sgu $(SRC)

