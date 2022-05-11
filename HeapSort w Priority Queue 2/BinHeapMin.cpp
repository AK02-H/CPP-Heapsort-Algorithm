#include "BinHeapMin.h"
#include <iostream>
using namespace std;

//template <class T>
//BinHeapMin<T>::BinHeapMin()

//template <class T>
//BinHeapMin<T>::BinHeapMin(int cap)

//template <class T>
//void BinHeapMin<T>::insertKey(T k, int priority)

//template <class T>
//void BinHeapMin<T>::changeKey(int i, T newValue)

//template <class T>
//T BinHeapMin<T>::extractMin()

//template <class T>
//void BinHeapMin<T>::deleteKey(int i)

//template <class T>
//void BinHeapMin<T>::Heapify(int i)

//template <class T>
//int BinHeapMin<T>::peekMax() {
//
//	T maxElement = heapArray[heap_size / 2].item;	//Essentially the first leaf
//	int maxElementIndex = heapArray[heap_size / 2].item;	//Essentially the first leaf
//
//	for (int i = 1 + heap_size / 2; i < heap_size; ++i) {
//
//		if()
//		maxElement = max(maxElement, heapArray[i].priority);
//	}
//
//	return maxElement;
//}
//
//template <class T>
//int BinHeapMin<T>::extractMax() {
//
//	int maxElemIndex = heap_size;
//
//	int maxElement = heapArray[heap_size / 2].priority;
//
//	for (int i = 1 + heap_size / 2; i < heap_size; ++i) {
//		if (maxElement < heapArray[i].priority) {
//			maxElement = heapArray[i].priority;
//			maxElemIndex = i;
//		}
//	}
//
//	deleteKey(maxElemIndex);
//
//	return maxElement;
//}