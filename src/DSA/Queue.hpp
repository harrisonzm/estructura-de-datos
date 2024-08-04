#pragma once
#include <exception>
#include "../src/DSA/SingleLinkedList.hpp"

template<typename T>
class Queue 
{
public:

    bool isEmpty();

    void queue(T value);
    T& dequeue();
    
    Queue();
    ~Queue();

private:    
    SingleLinkedList<T>* storage = nullptr;
};


//IMPLEMENTATION

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