#pragma once
#include <exception>
#include "../src/DSA/headers/SingleLinkedList.hpp"

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