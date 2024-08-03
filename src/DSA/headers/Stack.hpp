#pragma once
#include "../DSA/headers/SingleLinkedList.hpp"

template<typename T>
class Stack 
{
public:
    bool isEmpty();

    T& pop();
    void push(T& elemnt);

    T& peek();

    ~Stack();

private:
    SingleLinkedList<T> storage ;
};