ifeq ($(DEBUG),true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o
	$(CC) -o runProgram main.o
main.o: main.c
	$(CC) -c main.c
run:
	./runProgram
