CABECERA1 = ./lista.h
CC=gcc
FLAGS= -O3 -lm -Wall -I.

all: $(CABECERA1)
	$(CC) ./main.c -o main.o $(FLAGS)

run:
	./main.o -r 4 -s 4

clean:
	-rm -f *.o
