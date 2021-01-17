algorithm:testAlgorithm.o
	g++ testAlgorithm.o -o testAlgorithm

testAlgorithm.o:./testAlgorithm.cpp
	g++ -c ./testAlgorithm.cpp -g -I ../include -o testAlgorithm.o

vector:vector.o
	g++ vector.o -o vector

vector.o:./testVector.cpp ../include/vector.hpp
	g++ -c ./testVector.cpp -g -I ../include -o vector.o

.PHONY:all clean algorithm vector

all:algorithm vector

clean:
	rm -f testAlgorithm.o testAlgorithm vector.o vector