#pragma once
#include<iostream>
#include <cstddef>


template<class type>
struct NodoSimple {
    NodoSimple<type>* next = nullptr ;
    type value = type() ;
};

template<class T>
class List1 {

public:
        int Len();
        bool isEmpty();

        NodoSimple<T>* First();
        NodoSimple<T>* Last();
        NodoSimple<T>* findIndex(int );
        NodoSimple<T>* find(T );
        void traverse();

        void addFirst(T );
        void addLast(T );
        void addAfter(NodoSimple<T>* , T );

        T removeFirst();
        T removeLast();
        T remove(NodoSimple<T>* );

        List1();
        ~List1();

private:
    NodoSimple<T>* head = nullptr ;
    NodoSimple<T>* tail = nullptr ;
    int len = 0 ;

};

// IMPLEMENTATION

template<class T>
int List1<T>::Len() { return len; }

template<class T>
bool List1<T>::isEmpty() { return len == 0; }

template<class T>
NodoSimple<T>* List1<T>::First() { return head; }

template<class T>
NodoSimple<T>* List1<T>::Last() { return tail; }

template<class T>
void List1<T>::traverse() {
    if (len == 0) {
        std::cout << "nothing here";
    }
    else {
        NodoSimple<T>* curr = this->First();
        while (curr->next != nullptr) {
            std::cout << curr->value << " ";
            curr = curr->next;
        }
        std::cout << curr->value << "\n";



    }
}

template<class T>
NodoSimple<T>* List1<T>::findIndex(int index) {
    int count = 0;
    NodoSimple<T>* curr = this->First();
    while (count != index) {
        curr->next;
        count += 1;
    }
    return curr;
}

template<class T>
NodoSimple<T>* List1<T>::find(T val) {
    NodoSimple<T>* curr = this->First();
    while (curr != nullptr && curr->value != val) {
        curr = curr->next;
    }
    return curr;
}



template<class T>
void List1<T>::addFirst(T objeto) {
    NodoSimple<T>* newNode = new NodoSimple<T>;
    newNode->value = objeto;
    if (this->isEmpty()) {
        tail = newNode;
        head = newNode;
        len++;

    }
    else {
        newNode->next = head;
        head = newNode;
        len++;

    }

}

template<class T>
void List1<T>::addLast(T objeto) {
    NodoSimple<T>* newNode = new NodoSimple<T>;
    newNode->value = objeto;

    if (this->isEmpty()) {
        head = newNode;
        tail = newNode;
        len++;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        len++;
    }

}

template<class T>
void List1<T>::addAfter(NodoSimple<T>* node, T valu) {
    NodoSimple<T>* newNode = new NodoSimple<T>;
    newNode->value = valu;
    if (!isEmpty()) {
        this->head = newNode;
        this->tail = newNode;
        len++;
    }
    else {
        NodoSimple<T>* temp = node->next;
        newNode->next = temp;
        node->next = newNode;
        temp = nullptr;
        len++;
    }
}



template<class T>
T List1<T>::removeFirst() {
    if (isEmpty()) {
        return NULL;
    }
    else if (this->len == 1) {
        T temp = head->value;
        delete head;
        head = nullptr;
        tail = nullptr;
        len--;
        return temp;
    }
    else {
        NodoSimple<T>* temp = head;
        T objet = head->value;
        this->head = temp->next;
        delete temp;
        temp = nullptr;
        len--;
        return objet;
    }
}

template<class T>
T List1<T>::removeLast() {
    if (this->len == 1) {
        T temp = head->value;
        delete head;
        head = nullptr;
        tail = nullptr;
        len--;
        return temp;
    }
    else {
        NodoSimple<T>* temp = this->head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = nullptr;
        T objet = tail->value;
        delete tail;
        tail = temp;
        len--;
        return objet;
    }
}

template<class T>
T List1<T>::remove(NodoSimple<T>* node) {
    if (this->len == 0) {
        return NULL;
    }
    else if (len == 1) {
        T val = node->value;
        delete node;
        head, tail = nullptr;
        len--;
        return val;
    }
    else if (node == head) {

        head = head->next;
        T value = head->value;
        delete  node;
        len--;
        return value;
    }
    else if (node == tail) {

        NodoSimple<T>* temp = this->head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        T value = tail->value;
        tail = temp;
        tail->next = nullptr;
        delete node;
        len--;
        return value;

    }
    else {
        NodoSimple<T>* temp = this->head;
        while (temp->next != node) {

            temp = temp->next;
        }
        T value = node->value;
        temp->next = node->next;
        delete node;
        len--;
        return value;
    }
}

template<class T>
List1<T>::List1() {
    std::cout << "created " << "\n";
}

template<class T>
List1<T>::~List1() {
    if (this->len == 0) {
        std::cout << "exploded" << "\n";
    }
    else {
        NodoSimple<T>* temp = head;
        NodoSimple<T>* temp2 = temp->next;
        while (temp->next != nullptr) {
            delete temp;
            temp = temp2;
            temp2 = temp->next;
        }
        delete temp;

    }
}
