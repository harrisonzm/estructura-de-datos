#include "labs/headers/lab6.hpp"
#include "classes for labs/headers/turnoUsuario.hpp"
#include "DSA/Queue.hpp"
#include "DSA/Stack.hpp"
#include "classes for labs/headers/Usuario.hpp"
#include <iostream>

void lab6::puntoA() 
{
	Stack<int> s;
	for (int i = 2; i <= 10; i+=2) {
		s.push(i);
	}
	std::cout << s.pop() << " ";
	std::cout << s.pop() << " ";
	std::cout << s.pop() << " ";
	std::cout << s.pop() << " ";
	std::cout << s.pop() << " ";

}

void lab6::puntoB()
{
	Queue<int> q;
	for (int i = 2; i <= 10; i+=2) {
		q.enqueue(i);
	}
	std::cout << q.dequeue()<<" ";
	std::cout << q.dequeue() << " ";
	std::cout << q.dequeue() << " ";
	std::cout << q.dequeue() << " ";
	std::cout << q.dequeue() << " ";
}

void lab6::puntoC()
{

	turnoUsuario inter = *(new turnoUsuario());

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


	inter.registra(user1);
	inter.registra(user2);
	inter.registra(user3);
	inter.registra(user4);
	inter.registra(user5);
	inter.toFile();
	inter.atenderSiguiente();
	inter.atenderSiguiente();
	inter.toFile();
	

}