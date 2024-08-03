#include "../DSA/headers/Stack.hpp"
#include "../DSA/headers/SingleLinkedList.hpp"
#include <iostream>

template<class T>
T& Stack<T>::pop() 
{
    return storage.removeFirst;

}

template<class T>
void Stack<T>::push(T& elemnt) 
{
    storage.addFirst(elemnt);

}

template<class T>
T& Stack<T>::peek() 
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
    delete storage;
}
