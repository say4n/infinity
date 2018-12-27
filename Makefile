CXXFLAGS = -std=c++11
LIB = lib
BUILD = build
OUTPUT = test.out
DOCS = docs

.PHONY: all build rebuild clean

all: Integer docs test

build: all

rebuild: clean all

docs:
	doxygen Doxyfile

fibonacci: src/tests/fibonacci.cpp Integer
	mkdir -p $(BUILD)
	cp src/tests/fibonacci.cpp $(BUILD)
	cp lib/Integer.h $(BUILD)
	$(CXX) $(CXXFLAGS) build/fibonacci.cpp -L$(LIB) -lInteger -o $(OUTPUT)

factorial: src/tests/factorial.cpp Integer
	mkdir -p $(BUILD)
	cp src/tests/factorial.cpp $(BUILD)
	cp lib/Integer.h $(BUILD)
	$(CXX) $(CXXFLAGS) build/factorial.cpp -L$(LIB) -lInteger -o $(OUTPUT)

test: src/tests/test.cpp Integer
	mkdir -p $(BUILD)
	cp src/tests/test.cpp $(BUILD)
	cp lib/Integer.h $(BUILD)
	$(CXX) $(CXXFLAGS) build/test.cpp -L$(LIB) -lInteger -o $(OUTPUT)

Integer: Integer.o
	mkdir -p $(LIB)
	ar rvs $(LIB)/libInteger.a Integer.o
	rm -f Integer.o
	cp src/headers/Integer.h $(LIB)

Integer.o: src/Integer.cpp
	$(CXX) $(CXXFLAGS) -c src/Integer.cpp

clean:
	rm -rf $(LIB)
	rm -rf $(BUILD)
	rm -rf $(DOCS)
	rm -f *.out
