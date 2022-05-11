#pragma once
#include "BinHeapMin.h"

template <class T>
class PQueMin
{

public:

	//PQueMin();

	PQueMin(int capacity) {

		//std::cout << "CAPACITY PASSED INTO PQ CSTR IS " << capacity << std::endl;

		//BinHeapMin newBinHeap(capacity);
		binaryHeap = new BinHeapMin<T>(capacity); //use new keyword?
		//binaryHeap = new BinHeapMin(capacity); //use new keyword?


	}

	//Inserts item into priority queue
	void insert(T p, int priority) {
		//cout << "Inserted " << p << " into PQ with priority " << priority << endl;
		binaryHeap->insertKey(p, priority);
	}

	//Gets top of priority queue
	T extractMin() {
		return binaryHeap->extractMin();
	}
	//int extractMax();

	//Look at top of priority queue without removing item
	T peekMin() {
		return binaryHeap->peekMin();
	}
	//int peekMax();

	//Changes priority of item in heap at index (practically useless considering there is no particular order in the binary heap other than the root being minimum)
	void changePriority(int i, int p) {
		binaryHeap->changeKey(i, p);
	}

private:
	BinHeapMin<T>* binaryHeap;
};

