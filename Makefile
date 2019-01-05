CXXFLAGS = -std=c++11
LIB = lib
BUILD = build
OUTPUT = test.out
DOCS = docs

.PHONY: all build rebuild clean

all: infinity docs test

build: all

rebuild: clean all

docs:
	doxygen Doxyfile

fibonacci: src/tests/fibonacci.cpp infinity
	mkdir -p $(BUILD)
	cp src/tests/fibonacci.cpp $(BUILD)
	cp lib/Integer.h $(BUILD)
	$(CXX) $(CXXFLAGS) build/fibonacci.cpp -L$(LIB) -lInfinity -o $(OUTPUT)

factorial: src/tests/factorial.cpp infinity
	mkdir -p $(BUILD)
	cp src/tests/factorial.cpp $(BUILD)
	cp lib/Integer.h $(BUILD)
	$(CXX) $(CXXFLAGS) build/factorial.cpp -L$(LIB) -lInfinity -o $(OUTPUT)

testFloat: src/tests/testFloat.cpp Float
	mkdir -p $(BUILD)
	cp src/tests/testFloat.cpp $(BUILD)
	cp lib/Float.h $(BUILD)
	$(CXX) $(CXXFLAGS) build/testFloat.cpp -L$(LIB) -lFloat -o $(OUTPUT)

testInteger: src/tests/testInteger.cpp Integer
	mkdir -p $(BUILD)
	cp src/tests/testInteger.cpp $(BUILD)
	cp lib/Integer.h $(BUILD)
	$(CXX) $(CXXFLAGS) build/testInteger.cpp -L$(LIB) -lInteger -o $(OUTPUT)

infinity: Integer.o Float.o
	mkdir -p $(LIB)
	ar rvs $(LIB)/libInfinity.a Float.o Integer.o
	cp src/headers/*.h $(LIB)

Float: Float.o
	mkdir -p $(LIB)
	ar rvs $(LIB)/libFloat.a Float.o
	rm -f Float.o
	cp src/headers/Float.h $(LIB)

Float.o: src/Float.cpp
	$(CXX) $(CXXFLAGS) -c src/Float.cpp

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
