CXXFLAGS = -std=c++11
LIB = lib
BUILD = build
OUTPUT = test.out

.PHONY: all
all: Integer

build: all
rebuild: clean all

test: tests/test.cpp Integer
	mkdir -p $(BUILD)
	cp tests/test.cpp $(BUILD)
	cp lib/Integer.h $(BUILD)
	$(CXX) $(CXXFLAGS) build/test.cpp -L$(LIB) -lInteger -o $(OUTPUT)

Integer: Integer.o
	mkdir -p $(LIB)
	ar rvs $(LIB)/libInteger.a Integer.o
	cp headers/Integer.h $(LIB)

Integer.o: Integer.cpp
	$(CXX) $(CXXFLAGS) -c Integer.cpp

clean:
	rm -r $(LIB)
	rm -r $(BUILD)
	rm -f *.o
	rm -f *.out
	rm -f *.a
