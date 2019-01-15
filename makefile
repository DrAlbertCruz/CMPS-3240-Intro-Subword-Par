CC=gcc
FLAGS=-Wall -O0

all: myblas.o myblas.s test_dewvm.out

test_dewvm.out: test_dewvm.o myblas.o
	$(CC) $(FLAGS) -o $@ $^

test_dewvm.o: test_dewvm.c myblas.h
	$(CC) $(FLAGS) -c $<

myblas.o: myblas.s myblas.h
	$(CC) $(FLAGS) -c $^

clean:
	rm -f *.o *.out *.s
