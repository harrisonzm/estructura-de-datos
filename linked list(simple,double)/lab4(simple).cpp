#include<iostream>
#include <cstddef>
#include "lab2.cpp"

void main1();

template<class type>
struct Node{
        Node<type>* next = nullptr;
        type value = NULL;
};
template<typename Auto,size_t size>
class List1{
public:

private:
    struct Node<Auto>* head = nullptr;
    struct Node<Auto>* tail = nullptr;
    int tamaño = size;
    int len    = 0;

public:
    List1() {};
    int Len() { return len; }

    bool isEmpty() { return len == 0; }

    void setSize(int tamaño) { this->tamaño = tamaño; }

    int getSize() { return size; }

    struct Node<Auto>* Firs() { return head; }

    struct Node<Auto>* Last() { return tail; }

    void addFirst(Auto objeto) {
        struct Node<Auto>* newNode  = new Node<Auto>;
        newNode->value = objeto;
        if (len == size) {
            std::cout << "overflow";
           
        }
        else if (len == 0) {
            tail = newNode;
            head = newNode;
            len++;
            
        }
        else {
            newNode->next  = head;
            head           = newNode;
            len++;
            
        }
        
    }

    void addLast(Auto objeto) {
        struct Node<Auto>* newNode = new Node<Auto>;
        newNode->value = objeto;
        if (len == size) {
            std::cout << "overflow";

        }
        else if (len == 0) {
            head = newNode;
            tail = newNode;
            len++;
        }
        else {
            Node<Auto>* ultimo = Last();
            ultimo->next = newNode;
            this->tail = newNode;
            len++;
        }
        
    }
    void addAfter(Node<Auto>* node, Auto valu) {
        struct Node<Auto>* newNode  = new Node<Auto>;
        newNode->value = valu;
        if (this->len == tamaño) { 
            return NULL; 
        }
        else if (!isEmpty()) {
            head = newNode;
            tail = newNode;
            len++;
        }
        else {
            Node<Auto>* temp     = node->next;
            newNode->next  = temp;
            node->next     = newNode;
            delete           temp;
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
            return temp;
        }
        else {
            struct Node<Auto>* temp = head;
            Auto objet = head->value;
            this->head       = temp->next;
            delete       temp;
            len--;
            return       objet;
        }
     }

    Auto removeLast() {
        if (this->len < 2) {
            return removeFirst();
        }
        else {
            struct Node<Auto>* temp = this->head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = nullptr;
            Auto objet = tail->value;
            delete       tail->next;
            delete       tail;
            tail       = temp;
            len--;
            return       objet;
        }
    }

    Auto remove(Node<Auto>* nod) {
        if (this->len == 0) {
            return NULL;
        }
        else {
            struct Node<Auto>* temp = this->head;
            while (temp->next != nod) {
                temp = temp->next;
            }
            Auto valu  = nod->value;
            temp->next = nod->next;
            delete       nod;
            len--;
            return       valu;
        }
    }
    void traverse() {
        if (len == 0) {
            std::cout << "nothing here";
        }
        else {
            struct Node<Auto>* curr = head;
            while (curr->next != nullptr) {
                std::cout << curr->value << ",";
                curr = curr->next;
            }
            std::cout << curr->value<<"\n";
            
        }
    }    
    struct Node<Auto>* findIndex(int index) {
        int count = 0;
        struct Node<Auto>* curr = Firs();
        while (count != index) {
            curr->next;
            count += 1;
        }
        return count;
    }

    struct Node<Auto>* findValue(Auto val) {
        struct Node<Auto>* curr = head;
        while (curr->value != val) {
            curr = curr->next;
        }
        return curr;
    }

    ~List1() {
        if (this->len == 0) {

        }
        else {
            struct Node<Auto>* temp = this->Firs();
            struct Node<Auto>* temp2 = head->next;
            while (temp->next != nullptr) {
                delete      temp;
                temp = temp2;
                temp2 = temp->next;
            }
            delete temp;

             }
        }
    };

 void main1() {
     List1<int, 20> lista;
     lista.addFirst(2);
     lista.addLast(3);
     lista.removeFirst();
   

        


}
