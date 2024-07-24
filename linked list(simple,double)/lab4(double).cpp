#include<iostream>
#include<cstddef>
#include "lab2.cpp"
void main3();

template<class type>
struct Node {
    Node<type>* next = nullptr;
    Node<type>* prev = nullptr;
    type value = NULL;
};

template<typename Auto, size_t size>
class List2 {
private:
    Node<Auto>* head = nullptr;
    Node<Auto>* tail = nullptr;
    int tamaño = size;
    int len    = 0;

public:
    List2() {}

    int Len() { return len; }

    bool isEmpty() { return len == 0; }

    void setSize(size_t tamaño) { this->tamaño = tamaño; }

    Node<Auto>* First() { return head; }

    Node<Auto>* Last() { return tail; }

    void addFirst(Auto objeto) {
        if (this->len == size) {
            std::cout << "overflow";
        }
        else if (len == 0) {
            head = new Node<Auto>;
            tail = head;
            head->value = objeto;
            len++;
        }
        else{
        Node<Auto>* newNode = new Node<Auto>;
        newNode->value = objeto;
        newNode->next = head;
        head = newNode;
        len++;
        }
    }

    void addLast(Auto objeto) {
        if (this->len == size) {
            std::cout << "overflow";

        }
        else if (len == 0) {
            head = new Node<Auto>;
            tail = head;
            tail->value = objeto;
            len++;
        }
        else {
            Node<Auto>* temp = tail;
            std::cout << temp->value;
            Node<Auto>* newNode = new Node<Auto>;
            newNode->value = objeto;
            newNode->prev = temp;
            temp->next = newNode;
            tail = newNode;
            len++;
        }
        
    }
    void addBefore(Node<Auto>* node, Auto val) {
        if (this->len == tamaño) {
            std::cout << "overflow";
        }
        else if (node == head) {
            Node<Auto>* newNode = new Node<Auto>;
            newNode->value = val;
            newNode->next = node;
            newNode->prev = node->prev;
            node->prev = newNode;
            head = newNode;
            len++;
        }
        else {
            Node<Auto>* newNode  = new Node<Auto>;
            newNode->value = val;
            newNode->next  = node;
            newNode->prev  = node->prev;
            node->prev     = newNode;
            len++;

        }

    }
    void addAfter(Node<Auto>* node, Auto val) {
        if (this->len == size) {
            std::cout<<"overflow";
        }
        else if (node == tail) {
            Node<Auto>* newNode = new Node<Auto>;
            newNode->value = val;
            newNode->next = node->next;
            newNode->prev = node;
            node->next = newNode;
            tail = newNode;
            len++;

        }
        else {
            Node<Auto>* newNode  = new Node<Auto>;
            newNode->value = val;
            newNode->next  = node->next;
            newNode->prev  = node;
            node->next     = newNode;
            len++;
        }
    }

    Auto removeFirst() {
        if (this->len == 0) {
            return NULL;
        }
        else if (this->len == 1) {
            Auto temp = head->value;
            delete head;
            len--;
            head = nullptr;
            tail = nullptr;
            return  temp;
        }
        else {
            Node<Auto>* temp = head;
            Auto objet = head->value;
            head = temp->next;
            len--;
            delete temp;
            return objet;
        }

    }

    Auto removeLast() {
        if (this->len == 0) {

            return NULL;
        }
        else if (len == 1) {
            Auto temp = head->value;
            delete head;
            head = nullptr;
            tail = nullptr;
            return temp;
        }
        else {
            Node<Auto>* temp = tail->prev;
            Auto objet = temp->value;
            delete tail;
            temp->next = nullptr;
            tail = temp;
            len--;
            return       objet;
        }

    }
    Auto remove(Node<Auto>* node) {
        if (this->len == 0) {
            return NULL;
        }
        else if(node == head){
        }
        else if (node == tail) {

        }
        else {
            Auto value         = node->value;
            (node->prev)->next = node->next;
            (node->next)->prev = node->prev;
            delete             node;
        }
    }

    ~List2() {
        Node<Auto>* temp = head;
        Node<Auto>* temp2 = nullptr;
        while (temp->next != nullptr) {
            Node<Auto>* temp2 = temp->next;
            delete      temp;
            temp        = temp2;
        }
        delete   temp;
    }
};

void main3() {
    List2<int, 2> lista;
    lista.addFirst(1);
    //-------------------
    lista.addLast(2);
    //---------------------
    lista.removeFirst();
    std::cout << lista.First()->value;

}

int main() {
    main3();
    return 0;
}