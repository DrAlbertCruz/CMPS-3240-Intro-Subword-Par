CC=gcc
FLAGS=-Wall -O0

all: myblas.o myblas.s

myblas.o: myblas.c myblas.h
	$(CC) $(FLAGS) -c $^

myblas.s: myblas.c myblas.h
	$(CC) $(FLAGS) -S -o $@ $<

clean:
	rm -f *.o *.out *.s
