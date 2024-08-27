#include "DSA/DoubleLinkedList.hpp"
#include "DSA/SingleLinkedList.hpp"
#include "classes for labs/headers/Usuario.hpp"
#include "labs/headers/lab4.hpp"
#include<format>
#include<iostream>
#include<string>

void lab4::printUsers( SingleLinkedList<Usuario>& L) {
    NodoSimple<Usuario>* curr1 = L.First();
    int count = 1;
    while (curr1->next != nullptr) {
        std::cout << count << curr1->value.getNombre()  << ",";
        curr1 = curr1->next;
        count++;
    }
    std::cout << count << curr1->value.getNombre() << "\n";
}

void lab4::printUsers( DoubleLinkedList<Usuario>& L) {
    NodoDoble<Usuario>* curr2 = L.First();
    int count = 1;
    while (curr2->next != nullptr) {
        std::cout << count << curr2->value.getNombre() << ",";
        curr2 = curr2->next;
        count++;
    }
    std::cout << count << curr2->value.getNombre() << "\n";
}



void lab4::puntoA() {


    // single linked list
    SingleLinkedList<int> simple;

    for (int i = 1; i <= 20; i++) {
        if (i == 1) simple.addLast(&i);
        if (i % 2 == 0) simple.addLast(&i);
    }

    simple.traverse();
    int Testnum = 1;
    NodoSimple<int>* first = simple.find(&Testnum);
    simple.remove(first);
    Testnum *= 10;
    NodoSimple<int>* second = simple.find(&Testnum);
    simple.remove(second);
    Testnum *= 2;
    NodoSimple<int>* third = simple.find(&Testnum);
    simple.remove(third);


    simple.traverse();

    // doubly linked list
    DoubleLinkedList<int> doble;
    
    for (int j = 1; j <= 20; j++) {
        if (j == 1) { doble.addLast(&j); }
        if (j % 2 == 0) { doble.addLast(&j); }
    }

    doble.traverse();
    int i = 1;
    struct NodoDoble<int>* fourth = doble.  find(&i);
    doble.remove(fourth);
    i *= 10;
    struct NodoDoble<int>* fifth = doble.find(&i);
    doble.remove(fifth);
    i *= 2;
    struct NodoDoble<int>* sixth = doble.find(&i);
    doble.remove(sixth);

    doble.traverse();


}

void lab4::puntoB() {

    Fecha* fecha1 = new Fecha(1, 1, 1);
    Direccion* dir1 = new Direccion("1", "1", "1", "1", "1", "1");
    Fecha* fecha2 = new Fecha(2, 2, 2);
    Direccion* dir2 = new Direccion("2", "2", "2", "2", "2", "2");
    Fecha* fecha3 = new Fecha(3, 3, 3);
    Direccion* dir3 = new Direccion("3", "3", "3", "3", "3", "3");
    Fecha* fecha4 = new Fecha(4, 4, 4);
    Direccion* dir4 = new Direccion("4", "4", "4", "4", "4", "4");
    Fecha* fecha5 = new Fecha(5, 5, 5);
    Direccion* dir5 = new Direccion("5", "5", "5", "5", "5", "5");

    Usuario* user1 = new Usuario("harrison", 10, fecha1, "10", 10, "10", dir1);
    Usuario* user2 = new Usuario("largo", 20, fecha2, "20", 20, "20", dir2);
    Usuario* user3 = new Usuario("jose", 30, fecha3, "30", 30, "30", dir3);
    Usuario* user4 = new Usuario("salome", 40, fecha4, "40", 40, "40", dir4);
    Usuario* user5 = new Usuario("erik", 50, fecha5, "50", 50, "50", dir5);
    Usuario* user6 = new Usuario(*user1);
    Usuario* user7 = new Usuario(*user2);
    Usuario* user8 = new Usuario(*user3);
    Usuario* user9 = new Usuario(*user4);
    Usuario* user10 = new Usuario(*user5);

    SingleLinkedList<Usuario> simple;
    DoubleLinkedList<Usuario> doble;

    simple.addLast(user1);
    simple.addLast(user2);
    simple.addLast(user3);
    simple.addLast(user4);
    simple.addLast(user5);

    std::cout << "lista simple: ";
    printUsers(simple);
    

    doble.addLast(user6);
    doble.addLast(user7);
    doble.addLast(user8);
    doble.addLast(user9);
    doble.addLast(user10);

    std::cout << "lista doble: ";
    printUsers(doble);


    int dd, mm, aa;
    std::cout << " ingrese dia: ";
    std::cin >> dd;
    std::cout << " ingrese mes: ";
    std::cin >> mm;
    std::cout << " ingrese ano: ";
    std::cin >> aa;
    std::string di[6];
    int count = 0;
    std::string inpt;
    getline(std::cin, inpt);
    std::cout << "\ningrese calle:";
    getline(std::cin, inpt);
    di[count++] = inpt;
    std::cout << "\ningrese nomenclatura:";
    getline(std::cin, inpt);
    di[count++] = inpt;
    std::cout << "\ningrese barrio:";
    getline(std::cin, inpt);
    di[count++] = inpt;
    std::cout << "\ningrese ciudad:";
    getline(std::cin, inpt);
    di[count++] = inpt;
    std::cout << "\ningrese edificio:";
    getline(std::cin, inpt);
    di[count++] = inpt;
    std::cout << "\ningrese apto:";
    getline(std::cin, inpt);
    di[count++] = inpt;
    std::string name1, name2, name3;
    std::cout << " ingrese nombre del primer usuario: ";
    std::cin >> name1;
    std::cout << " ingrese nombre del segundo usuario: ";
    std::cin >> name2;
    std::cout << "ingrese nombre del ultimo usuario: ";
    std::cin >> name3;
    
    Fecha* F1 = new Fecha(dd, mm, aa);
    Fecha* F2 = new Fecha(*F1);
    Fecha* F3 = new Fecha(*F1);
    Direccion* D1 = new Direccion(di[0], di[1], di[2], di[3], di[4], di[5]);
    Direccion* D2 = new Direccion(*D1);
    Direccion* D3 = new Direccion(*D1);

    Usuario* U1 = new Usuario(name1, 60, F1, "Na", 0, "Na", D1);
    Usuario* U2 = new Usuario(name2, 70, F2, "Na", 0, "Na", D2);
    Usuario* U3 = new Usuario(*U1);
    Usuario* U4 = new Usuario(*U2);
    Usuario* U5 = new Usuario(name3, 80, F3, "Na", 0, "Na", D3);

    simple.addLast(U1);
    simple.addLast(U2);
    doble.addLast(U3);
    doble.addLast(U4);
     NodoDoble<Usuario>* found = doble.find(U4);
    doble.addAfter(found,*U5);
    printUsers(doble);
    

}