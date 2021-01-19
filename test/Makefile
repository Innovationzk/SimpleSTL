algorithm:algorithm.o
	g++ algorithm.o -o algorithm

algorithm.o:./testAlgorithm.cpp ../include/algorithm.hpp
	g++ -c ./testAlgorithm.cpp -g -I ../include -o algorithm.o

vector:vector.o
	g++ vector.o -o vector

vector.o:./testVector.cpp ../include/vector.hpp
	g++ -c ./testVector.cpp -g -I ../include -o vector.o

.PHONY:all clean algorithm vector

all:algorithm vector

clean:
	rm -f algorithm.o algorithm vector.o vector