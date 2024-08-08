#pragma once

template<class T>
class minHeap
{
public:

	int  parent  (const int index);
	int left  (const int index);
	int  right  (const int index);


	void insert(const T* const elemnt);
	T* minimum();
	T* extractMinimum();


	void minHeapify (const T* arr, const int index);
	T* buildMinHeap(const T* array);
	void heapSort(const T* array);

	minHeap();
	~minHeap();

private:
	T* array = nullptr;
	size_t size = 0;
};


template<class T>
int minHeap<T>::parent  (const int index)
{   
	return  (index / 2) - 1;
}


template<class T>
int minHeap<T>::left (const int index)
{
	return (index * 2) + 1;
}

template<class T>
int minHeap<T>::right  (const int index)
{
	return (index * 2) + 2;
}

template<class T>
void minHeap<T>::minHeapify  (const T* array, const int index)
{
	int l = left(index);
	int r = right(index);
	int smaller = index;
	size_t size = sizeof(*array) / sizeof(T);
	if (array[l] < array[index] && l < size)
	{
		smaller = l;

	}

	if (array[r] < array[index] && r < size)
	{
		smaller = r;
	}
	if (smaller != index)
	{
		T temp = array[smaller];
		array[smaller] = array[index];
		array[index] = temp;
		minHeapify(array,l);
		minHeapify(array,r);
	}

}

template<class T>
T* minHeap<T>::buildMinHeap (const T* unorderedArray)
{	
	array = unorderedArray;
	size = sizeof(*unorderedArray) / sizeof(T);

	for (int i = heapSize; i > 0; i--)
	{	
		size_t parent = i / 2 - 1;
		this->minHeapify(parent);
	}
}


template<class T >
void minHeap<T>::heapSort (const T* array)
{

	buildMinHeap(array);
	for (int i = size; i > 1; i--)
	{
		const T temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		i--;
		minHeapify(array, 0);
	}

}
template<class T>
void minHeap<T>::insert (const T* elemnt)
{
	int index = ++size;
	array[index] = element;
	while (index > 0 && array[parent(index)] < array[index])
	{
		const int pnt = parent(index);
		T temp = array[pnt];
		array[pnt] = array[index];
		array[index] = temp;
		index = pnt;

	}
	

}

template<class T>
T* minHeap<T>::extractMinimum ()
{
	const temp = array[0];
	array[0] = array[size - 1];
	size--;
	minHeapify(array, 0);
	return temp;

}

template<class T>
T* minHeap<T>::minimum()
{
	return array[0];
}


template<class T>
minHeap<T>::minHeap()
{}

template<class T>
minHeap<T>::~minHeap() {
	delete[] array;
}
