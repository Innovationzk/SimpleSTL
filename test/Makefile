algorithm:algorithm.o
	g++ algorithm.o -o algorithm

algorithm.o:./testAlgorithm.cpp ../include/algorithm.hpp
	g++ -c ./testAlgorithm.cpp -g -I ../include -o algorithm.o

vector:vector.o
	g++ vector.o -o vector

vector.o:./testVector.cpp ../include/vector.hpp
	g++ -c ./testVector.cpp -g -I ../include -o vector.o

list:list.o
	g++ list.o -o list

list.o:./testList.cpp ../include/list.hpp
	g++ -c ./testList.cpp -g -I ../include -o list.o

bintree:bintree.o
	g++ bintree.o -o bintree

bintree.o:./testBinTree.cpp ../include/bintree.hpp
	g++ -c ./testBinTree.cpp -g -I ../include -o bintree.o

.PHONY:all clean algorithm vector list bintree

all:algorithm vector list bintree

clean:
	rm -f algorithm.o algorithm vector.o vector list.o list bintree.o bintree