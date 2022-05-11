#pragma once

#include <iostream>
#include <limits.h>
#include <math.h>
#include <algorithm>

using namespace std;

//void swap(int* x, int* y);
template <class T>
struct BHeapItem {
	T item = T();
	int priority = 0;
};

template <class T>
class BinHeapMin
{
private:

	BHeapItem<T>* heapArray;	//pointer to array of heap elements
	int capacity;	//max possible size of heap
	int heap_size; //current heap size

public:

	//cstr

	BinHeapMin() {	//Default constructor
		heap_size = 0;
		capacity = 128;	//When no capacity is assigned, heap capacity is 128 by default
		heapArray = new BHeapItem<T>[capacity];
	}

	//Constructor
	BinHeapMin(int cap) {
		heap_size = 0;
		capacity = cap;
		heapArray = new BHeapItem<T>[cap];
	}

	//Swims a node until both it's children have lower priority and parent has higher priority
	void Heapify(int i)	//takes subtree root index as arguement
	{
		cout << "HEAPIFY" << endl;

		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < heap_size && heapArray[l].priority < heapArray[r].priority) {
			smallest = l;
		}
		if (r < heap_size && heapArray[r].priority < heapArray[smallest].priority) {
			smallest = r;
		}
		if (smallest != i) {
			swap(&heapArray[i], &heapArray[smallest]);
			Heapify(smallest);
		}
	}

	//Gets parent of a node via index
	int parent(int i) {
		return (i - 1) / 2;
	}

	//Gets left child of a node via index
	int left(int i) {
		return (2 * i) + 1;
	}

	//Gets right child of a node via index
	int right(int i) {
		return (2 * i) + 2;
	}

	//changes the value of item at i
	void changeKey(int i, T newValue) {

		heapArray[i].item = newValue;
		while (i != 0 && heapArray[parent(i)].priority > heapArray[i].priority) {
			swap(&heapArray[i], &heapArray[parent(i)]);
			i = parent(i);
		}
	}

	//removes and returns the root of the heap
	T extractMin() {

		if (heap_size <= 0) {
			return T();
			//return INT_MAX;
			//return " ";
		}
		if (heap_size == 1) {
			heap_size--;
			return heapArray[0].item;
		}

		T root = heapArray[0].item;
		heapArray[0] = heapArray[heap_size - 1];	//swaps root and end
		heap_size--;
		Heapify(0);

		cout << "ROOT IS: " << root << endl;

		return root;
	}
	

	//Returns the root of the heap without removing it
	T peekMin() {
		cout << "PEEK MIN" << endl;
		return heapArray[0].item;
	}

	
	//Deletes item at index i
	void deleteKey(int i) {
		changeKey(i, INT_MIN);
		extractMin();
	}

	//Inserts item with a priority
	void insertKey(T k, int priority) {

		//cout << "inserted " << k << " with priority " << priority << endl;

		if (heap_size == capacity) {
			//OVERFLOW
			cout << "Overflow: Could not insertKey" << endl;
			return;
		}

		heap_size = heap_size + 1;
		int i;
		i = heap_size - 1;
		heapArray[i] = BHeapItem<T>();
		heapArray[i].item = k;
		heapArray[i].priority = priority;


		while (i != 0 && heapArray[parent(i)].priority > heapArray[i].priority) {
			cout << "SWIM" << endl;
			swap(&heapArray[i], &heapArray[parent(i)]);
			i = parent(i);
		}
	}

	//utility function for swapping values of 2 ints
	void swap(int* x, int* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
		
	}

	//utility function for swapping values of 2 strings
	void swap(string* x, string* y)
	{
		string temp = *x;
		*x = *y;
		*y = temp;

	}

	//utility function for swapping values of 2 binary heap node structs
	void swap(BHeapItem<T>* x, BHeapItem<T>* y)
	{
		BHeapItem<T> temp = *x;
		*x = *y;
		*y = temp;

	}
	
};



