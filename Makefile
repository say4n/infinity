CXXFLAGS = -std=c++11
LIB = lib
BUILD = build
OUTPUT = test.out
DOCS = docs

.PHONY: all
all: Integer docs test

build: all
rebuild: clean all

docs:
	doxygen Doxyfile

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
	rm -r $(LIB)
	rm -r $(BUILD)
	rm -r $(DOCS)
	rm -f *.out
