#pragma once
#include <cstddef>

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