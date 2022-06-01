all: test

test: examheap.cpp heap.o
	g++ -std=c++11 examheap.cpp heap.o -o test

clean: 
	remove *.o test