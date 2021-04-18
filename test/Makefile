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

queue:queue.o
	g++ queue.o -o queue

queue.o:./testQueue.cpp ../include/queue.hpp
	g++ -c ./testQueue.cpp -g -I ../include -o queue.o

bintree:bintree.o
	g++ bintree.o -o bintree

bintree.o:./testBinTree.cpp ../include/bintree.hpp
	g++ -c ./testBinTree.cpp -g -I ../include -o bintree.o

.PHONY:all clean algorithm vector list bintree queue

all:algorithm vector list bintree queue

clean:
	rm -f algorithm.o algorithm vector.o vector list.o list bintree.o bintree queue queue.o