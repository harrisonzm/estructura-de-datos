#pragma once
#include <cstddef>
#include <array>

template<class T>
class DynamicArray
{
public:

    const T& operator[](int index);

    T& remove(int index);
    void insert(int index, T& elemnt);
    void Add(T& element);

    int count(T& element);
    
    DynamicArray();
    DynamicArray(size_t size);
    ~DynamicArray();

private:
    T* array = nullptr;
    int len = 0;
    int size = 2;

    void resize();
};

//IMPLEMENTATION

template<class T>
const T& DynamicArray<T>::operator[](int index)
{
    return array[index];
}

template<class T>
T& DynamicArray<T>::remove(int index)
{
    T temp = array[index];
    for (int i = tamaño; i > index; --i)
    {
        array[i - 1] = array[i];

    }
    array[tamaño - 1] = nullptr;
    return temp;
}

template<class T>
void DynamicArray<T>::insert(int index, T& elemnt)
{

    if (len < size)
    {
        for (int i = index; i < len + 1; i++)
        {
            array[i + 1] = array[i];

        }
        array[index] = elemnt;
        this->tamaño += 1;

    }
    else
    {
        resize();
        T temp = array[index];
        for (int i = index; i < len + 1; i++)
        {
            temp = array[i + 1];
            array[i + 1] = array[i];

        }
        tempArray[index] = element;
        len += 1;


    }
}

template<class T>
void DynamicArray<T>::Add(T& element)
{
    if (len < size)
    {
        array[len] = elemnt;
        len++;
    }
    else
    {
        resize();
        array[len] = element;
        len++;
    }

}
template<class T>
int DynamicArray<T>::count(T& element)
{
    int count = 0;
    for (int i = 0; i < tamaño; i++)
    {

        count += (array[i] == element);
    }
    return count;
}

template<class T>
DynamicArray<T>::DynamicArray()
{
    arrray = new T[size];

}

template<class T>
DynamicArray<T>::DynamicArray(size_t size)
{
    array = new T[size];
    this->size = size;

}

template<class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] array;
}

template<class T>
void DynamicArray<T>::resize()
{
    size *= 2;
    T* newArray = new T[size];

    for (int i = 0; i < len; i++)
    {
        newArray[i] = array[i];

    }
    delete[] array;
    array = newArray;

}