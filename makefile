CABECERA1 = ./lista.h
CC=gcc
FLAGS= -lm -Wall -I.

all: $(CABECERA1)
	$(CC) ./main.c -o main.o $(FLAGS)

run:
	./main.o

clean:
	-rm -f *.o
