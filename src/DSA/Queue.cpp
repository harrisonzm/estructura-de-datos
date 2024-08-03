#include <exception>
#include "../DSA/headers/SingleLinkedList.hpp"
#include"../DSA/headers/Queue.hpp"
#include <iostream>
#include <cstddef>

template<typename T>
bool Queue<T>::isEmpty()
{
    return storage->isEmpty();

}

template<typename T>
void Queue<T>::queue(T value) 
{
    storage->addFirst(T);
}

template<typename T>
T& Queue<T>::dequeue()
{
    if (isEmpty()) {

        return T();

    }
    else {
        return storage->removeLast();

    }
}

template<typename T>
Queue<T>::Queue() 
{

}
   
template<typename T>
Queue<T>::~Queue()
{
    delete storage;

}