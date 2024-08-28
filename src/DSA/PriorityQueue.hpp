#pragma once
#include <DSA/MaxHeap.hpp>

template<class T>
class PriorityQueue
{
public:
	void push(T* obj);
	T pop();
	T& top();
	bool empty();
	void build(T (&arr)[20]);
	void build(std::vector<T> arr);

	PriorityQueue();

	void print();

private:
	maxHeap<T> storage;
};


//IMPLEMENTATION

template<class T>
void PriorityQueue<T>::push(T* obj)
{
	storage.insert(obj);
}

template<class T>
T PriorityQueue<T>::pop()
{
	return  storage.extractMax();
}
template<class T>
bool PriorityQueue<T>::empty()
{
	return storage.empty();
}

template<class T>
T& PriorityQueue<T>::top()
{
	return *storage.maximum();
}

template<class T>
void PriorityQueue<T>::build(T (& obj)[20])
{
	storage.buildMaxHeap(obj);
}

template<class T>
void PriorityQueue<T>::build(std::vector<T> obj)
{
	storage.buildMaxHeap(obj);
}


template<class T>
PriorityQueue<T>::PriorityQueue()
{
}


template<class T>
void PriorityQueue<T>::print()
{
	storage.printHeap();
}