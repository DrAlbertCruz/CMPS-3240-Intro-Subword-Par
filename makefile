CC=gcc
FLAGS=-Wall -O0

all: myblas.o test_dewvm.out bench_dewvm.out

# Targets to benchmark dewvm()
bench_dewvm.out: bench_dewvm.o myblas.o
	$(CC) $(FLAGS) -o $@ $^
bench_dewvm.o: bench_dewvm.c myblas.h
	$(CC) $(FLAGS) -c $<

# A test function to make sure dewvm() is correct
test_dewvm.out: test_dewvm.o myblas.o
	$(CC) $(FLAGS) -o $@ $^
test_dewvm.o: test_dewvm.c myblas.h
	$(CC) $(FLAGS) -c $<

# Target to compile myblas.o from assembly language
myblas.o: myblas.s myblas.h
	$(CC) $(FLAGS) -c $^

# Target to generate myblas.s. Only necessary if you're in another environment (hence why its
# not included in the 'all' target).
assemble: myblas.c
	$(CC) $(FLAGS) -S myblas.s -c $<

clean:
	rm -f *.o *.out
