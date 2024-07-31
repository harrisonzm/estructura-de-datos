#pragma once
#include<iostream>
#include<cstddef>

template<typename T>
struct NodoDoble {
    struct NodoDoble<T>* next = nullptr;
    struct NodoDoble<T>* prev = nullptr;
    T value = T();
};

template<typename T>
class DoubleLinkedList {

public:
    int Len();
    bool isEmpty();

    struct NodoDoble<T>* First();
    struct NodoDoble<T>* Last();
    struct NodoDoble<T>* find(T );
    void traverse();

    void addFirst(T );
    void addLast(T );
    void addBefore(struct NodoDoble<T>* , T );
    void addAfter(struct NodoDoble<T>* , T );

    T& removeFirst();
    T& removeLast();
    T& remove(struct NodoDoble<T>* );

    DoubleLinkedList();
    DoubleLinkedList(NodoDoble<T>*, int);
    DoubleLinkedList(NodoDoble<T>*);
    ~DoubleLinkedList();

private:
    struct NodoDoble<T>* head = nullptr;
    struct NodoDoble<T>* tail = nullptr;
    size_t len = 0;
};

//IMPLEMENTATION

template<class T>
int DoubleLinkedList<T>::Len() { return len; }

template<class T>
bool DoubleLinkedList<T>::isEmpty() { return len == 0; }

template<class T>
NodoDoble<T>* DoubleLinkedList<T>::First() { return head; }

template<class T>
NodoDoble<T>* DoubleLinkedList<T>::Last() { return tail; }

template<class T>
NodoDoble<T>* DoubleLinkedList<T>::find(T val) {
    NodoDoble<T>* curr = head;
    while (curr != nullptr && curr->value != val) {
        curr = curr->next;
    }
    return curr;
}

template<class T>
void DoubleLinkedList<T>::addFirst(T objeto) {
    struct NodoDoble<T>* newNode = new struct NodoDoble<T>;
    newNode->value = objeto;
    if (len == 0) {
        head, tail = newNode;
        len++;
    }
    else {
        newNode->next = head;
        head = newNode;
        len++;
    }
}

template<class T>
void DoubleLinkedList<T>::addLast(T objeto) {
    NodoDoble<T>* newNode = new NodoDoble<T>;
    newNode->value = objeto;
    if (len == 0) {
        head = newNode, tail = newNode;
        len++;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        len++;
    }

}

template<class T>
void DoubleLinkedList<T>::addBefore( NodoDoble<T>* node, T val) {
    NodoDoble<T>* newNode = new NodoDoble<T>;
    newNode->value = val;
    if (node == head) {
        newNode->next = node;
        newNode->prev = node->prev;
        node->prev = newNode;
        head = newNode;
        len++;
    }
    else {

        newNode->next = node;
        newNode->prev = node->prev;
        node->prev = newNode;
        len++;

    }

}

template<class T>
void DoubleLinkedList<T>::addAfter(NodoDoble<T>* node, T val) {
    NodoDoble<T>* newNode = new NodoDoble<T>;
    newNode->value = val;
    if (node == tail) {
        newNode->prev = node;
        node->next = newNode;
        tail = newNode;
        len++;

    }
    else {

        newNode->next = node->next;
        newNode->prev = node;
        node->next = newNode;
        len++;
    }
}

template<class T>
T& DoubleLinkedList<T>::removeFirst() {
    if (this->len == 0) {
        return NULL;
    }
    else if (this->len == 1) {
        T temp = head->value;
        delete head;
        len--;
        head = nullptr;
        tail = nullptr;
        return  temp;
    }
    else {
        NodoDoble<T>* temp = head;
        T objet = head->value;
        head = head->next;
        len--;
        delete temp;
        return objet;
    }

}

template<class T>
T& DoubleLinkedList<T>::removeLast() {
    if (this->len == 0) {

        return NULL;
    }
    else if (len == 1) {
        T temp = head->value;
        delete head;
        head = nullptr;
        tail = nullptr;
        return temp;
    }
    else {
        NodoDoble<T>* temp = tail;
        tail = tail->prev;
        T obj = temp->value;
        tail->next = nullptr;
        delete temp;
        len--;
        return obj;
    }

}

template<class T>
T& DoubleLinkedList<T>::remove(NodoDoble<T>* node) {
    if (this->len == 0) {
        T temp ;
        return temp ;
    }
    else if (node == head && len == 1) {
        T val = head->value;
        delete head;
        head, tail = nullptr;
        len--;
        return val;

    }
    else if (node == head) {
        T val = node->value;
        head = node->next;
        head->prev = nullptr;
        delete node;
        len--;
        return val;
    }
    else if (node == tail) {

        tail = node->prev;
        tail->next = nullptr;
        T val = node->value;
        delete node;
        len--;
        return val;
    }
    else {
        T val = node->value;
        (node->prev)->next = node->next;
        (node->next)->prev = node->prev;
        delete node;
        len--;
        return val;
    }
}

template<class T>
void DoubleLinkedList<T>::traverse() {
    if (len == 0) {
        std::cout << "nothing here";
    }
    else {
        struct NodoDoble<T>* curr = this->First();
        while (curr->next != nullptr) {
            std::cout << curr->value << " ";
            curr = curr->next;
        }
        std::cout << curr->value << "\n";

    }
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    std::cout << "created " << "\n";
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(NodoDoble<T>* head, int n) {

    while (n > 0) {
		this->addLast(head->value);
		head = head->next;
		n--;
	}
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(NodoDoble<T>* head) {
    while(head != nullptr) {
		this->addLast(head->value);
		head = head->next;
	}
}


template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    if (this->len == 0) {}
    else {
        NodoDoble<T>* temp = head;
        NodoDoble<T>* temp2 = nullptr;
        while (temp->next != nullptr) {
            NodoDoble<T>* temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
        delete temp;
    }
}
