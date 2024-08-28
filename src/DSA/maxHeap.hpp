#pragma once
#include <typeinfo>
#include <iostream>
#include <vector>

template<class T>
class maxHeap
{
public:

	int  parent(const int index) noexcept;
	int left(const int index) noexcept;
	int  right(const int index) noexcept;
	bool empty() noexcept;

	void insert(T* elemnt);
	T extractMax();
	T* maximum() noexcept;


	void maxHeapify(std::vector<T>* arr,const int index);
	void buildMaxHeap(T (&arr)[20]);
	void buildMaxHeap(std::vector<T>* unorderedArray);
	void heapSort();
	void printHeap();
	void printFloor(int level, int index);


	maxHeap();
	~maxHeap();

private:
	std::vector<T> arr;
	size_t size = 0;
};


template<class T>
int  maxHeap<T>::parent(const int index) noexcept
{
	return  (index / 2) - 1;
}


template<class T>
int maxHeap<T>::left(const int index) noexcept
{
	return index * 2 + 1;
}

template<class T>
int maxHeap<T>::right(const int index)noexcept
{
	return index * 2 + 2;
}


template<class T>
bool maxHeap<T>::empty() noexcept
{
	return arr.empty();
}

template<class T>
T maxHeap<T>::extractMax()
{
	T max = arr[0];
	arr[0] = arr[size - 1];
	size--;
	maxHeapify(&arr, 0);
	return max;
}

template<class T>
T* maxHeap<T>::maximum() noexcept
{
	return &arr.at(0);
}

template<class T>
void maxHeap<T>::insert(T* elemnt)
{
	int i = size++;
	arr[i] = elemnt;
	while (i > 0 && arr[parent(i)] < arr[i]) {
		T temp = arr[parent(i)];
		arr[parent(i)] = arr[i];
		arr[i] = temp;
		i = parent(i);
	}
	
}

template<class T>
void maxHeap<T>::maxHeapify(std::vector<T>* arr,const int index)
{
	int l = left(index);
	int r = right(index);
	int bigger = index;
	size_t len = arr->size();
	if ( l < size && (*arr)[l] > (*arr)[index])
	{
		bigger = l;

	}

	if ( r < size && (*arr)[r] > (*arr)[index])
	{
		bigger = r;
	}

	if (bigger != index)
	{
		T temp = (*arr)[bigger];
		(*arr)[bigger] = (*arr)[index];
		(*arr)[index] = temp;
		maxHeapify(arr, l);
		maxHeapify(arr, r);
	}

}

template<class T>
void maxHeap<T>::buildMaxHeap(T (&unorderedArray)[20])
{
	int len = 20;
	size = 20;
	arr.insert(arr.begin(), unorderedArray, unorderedArray + len);

	for (int i = (len/2)-1; i > 0; i--)
	{
		this->maxHeapify(&arr, i);
	}
	
}

template<class T>
void maxHeap<T>::buildMaxHeap(std::vector<T>* unorderedArray)
{
	arr = unorderedArray;
	int len = unorderedArray->size();

	for (int i = len/2-1; i > 0; i--)
	{
		this->maxHeapify(parent(i), i);
	}
	arr = unorderedArray;
}


template<class T >
void maxHeap<T>::heapSort()
{
	for (int i = size-1; i > 1; i--)
	{
		T temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		size--;
		maxHeapify(arr, 0);
	}

}

template<class T>
void maxHeap<T>::printFloor(int level, int index)
{	
	
	if (index < arr.size()) {
		
		std::cout << level << ": " << arr.at(index) << "\n";
		int l = left(index);
		int r = right(index);

		printFloor(level + 1, l);
		printFloor(level + 1, l);
	}
}

template<class T>
void maxHeap<T>::printHeap()
{
	printFloor(0, 0);
}


template<class T>
maxHeap<T>::maxHeap()
{

}

template<class T>
maxHeap<T>::~maxHeap()
{
	
	
}
