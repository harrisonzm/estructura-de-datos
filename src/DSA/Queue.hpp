#pragma once
#include <exception>
#include "DSA/SingleLinkedList.hpp"

template<typename T>
class Queue 
{
public:


    //STATE
    bool isEmpty() noexcept;
    T* peek() noexcept;


    //MODIFIERS
    void enqueue(const T value) noexcept;
    T* dequeue() noexcept;


    
    Queue();
    ~Queue();

private:    
    SingleLinkedList<T>* storage = nullptr;
};


//IMPLEMENTATION

template<typename T>
bool Queue<T>::isEmpty() noexcept
{
    return storage->isEmpty();

}

template<typename T>
void Queue<T>::enqueue(const T value) noexcept
{
    storage->addFirst(T);
}

template<typename T>
T* Queue<T>::dequeue() noexcept
{
    if (isEmpty()) {

        return nullptr;

    }
    else {
        return storage->removeLast();

    }
}

template<typename T>
Queue<T>::Queue()
{
    storage = new SingleLinkedList<T>();
}

template<typename T>
Queue<T>::~Queue()
{
    delete storage;

}