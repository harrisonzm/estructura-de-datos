#pragma once

template<class T>
class maxHeap
{
public:

	int  parent noexcept (const int index);
	int left noexcept  (const int index);
	int  right noexcept (const int index);

	void insert(T* elemnt);
	T extractMax();
	T* maximum noexcept ();


	void maxHeapify(T* array,const int index);
	T* buildMaxHeap(T* array);
	void heapSort(T* array);


	maxHeap(size_t capacity);
	~maxHeap();

private:
	T* array = nullptr;
	size_t size = 0;
};


template<class T>
int  maxHeap<T>::parent noexcept (const int index)
{
	return  (index / 2) - 1;
}


template<class T>
int maxHeap<T>::left noexcept (const int index)
{
	return index * 2 + 1;
}

template<class T>
int maxHeap<T>::right noexcept (const int index)
{
	return index * 2 + 2;
}

template<class T>
T maxHeap<T>::extractMax()
{
	T max = array[0];
	array[0] = array[size - 1];
	size--;
	maxHeapify(array, 0);
	return max;
}

template<class T>
T* maxHeap<T>::maximum noexcept ()
{
	return array[0];
}

template<class T>
void maxHeap<T>::insert(T* elemnt)
{
	i = ++size;
	array[i] = elemnt;
	while (i > 0 && array[parent(i)] < array[i]) {
		temp = array[parent(i)];
		array[parent(i)] = array[i];
		array[i] = temp;
		i = parent(i);
	}
	
}

template<class T>
void maxHeap<T>::maxHeapify(T* array,const int index)
{
	int l = left(index);
	int r = right(index);
	int smaller = index;
	size_t size = sizeof(*array) / sizeof(T);
	if (array[l] > array[index] && l <= size)
	{
		smaller = l;

	}

	if (array[r] > array[index] && r <= size)
	{
		smaller = r;
	}
	if (smaller != index)
	{
		T temp = array[smaller];
		array[smaller] = array[index];
		array[index] = temp;
		maxHeapify(array, l);
		maxHeapify(array, r);
	}

}

template<class T>
T* maxHeap<T>::buildMaxHeap(T* unorderedArray)
{
	array = unorderedArray;
	size = sizeof(*unorderedArray) / sizeof(T);

	for (int i = heapSize; i > 0; i--)
	{
		size_t parent = i / 2 - 1;
		this->maxHeapify(parent);
	}
}


template<class T >
void maxHeap<T>::heapSort(T* array)
{

	buildMaxHeap(array);
	for (int i = size; i > 1; i--)
	{
		T temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		size--;
		maxHeapify(array, 0);
	}

}


template<class T>
maxHeap<T>::maxHeap(size_t capacity)
{
	size = capacity;
	array = new T[size];
}

template<class T>
maxHeap<T>::~maxHeap() {
	delete[] array;
}
