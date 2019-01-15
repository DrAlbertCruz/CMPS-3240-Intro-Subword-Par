CC=gcc
FLAGS=-Wall -O0

all: myblas.o

myblas.o: myblas.s myblas.h
	$(CC) $(FLAGS) -c $^

clean:
	rm -f *.o *.out *.s
