#pragma once
#include <exception>
#include "DSA/SingleLinkedList.hpp"

template<typename T>
class Queue 
{
public:


    //STATE
    bool isEmpty() noexcept;
    NodoSimple<T>* peek() noexcept;


    //MODIFIERS
    void enqueue( T* value) noexcept;
    T dequeue() noexcept;


    
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
template<class T>
NodoSimple<T>* Queue<T>::peek() noexcept
{
    return  storage->First();
}

template<typename T>
void Queue<T>::enqueue( T* value) noexcept
{
    storage->addFirst( value);
}

template<typename T>
T Queue<T>::dequeue() noexcept
{
    if (isEmpty()) {

        return *(new T());

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