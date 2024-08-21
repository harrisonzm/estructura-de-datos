#pragma once
#include "DSA/SingleLinkedList.hpp"

template<typename T>
class Stack 
{
public:
    bool isEmpty();

    T pop();
    void push(T elemnt);

    NodoSimple<T>* peek() ;

    ~Stack();

private:
    SingleLinkedList<T> storage ;
};


//IMPLEMENTATION

template<class T>
T Stack<T>::pop()
{
    return storage.removeFirst();

}

template<class T>
void Stack<T>::push(T elemnt)
{
    storage.addFirst(elemnt);

}

template<class T>
NodoSimple<T>* Stack<T>::peek()
{
    return storage.First();
}

template<class T>
bool Stack<T>::isEmpty()
{
    return storage.isEmpty();
}

template<class T>
Stack<T>::~Stack()
{

}
