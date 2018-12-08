INC = -I ./headers
OUTPUT = test.out

.PHONY: all
all: Integer.o

rebuild: clean all

test: test.o Integer.o
	g++ test.o Integer.o -o $(OUTPUT)

test.o: tests/test.cpp headers/Integer.h
	g++ $(INC) -c tests/test.cpp

Integer.o: Integer.cpp headers/Integer.h
	g++ $(INC) -c Integer.cpp


clean:
	rm -f *.o
	rm -f *.out
