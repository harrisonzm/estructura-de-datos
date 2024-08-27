#include "headers/Bandeja.hpp"
#include "classes for labs/headers/Administrador.hpp"
#include "classes for labs/headers/Empleado.hpp"

Empleado* Bandeja::iniciar()
{
	std::string pass;
	int id;

	std::cout << "ingrese ID: ";
	std::cin >> id;
	std::cout << "ingrese contraseña: ";
	std::cin >> pass;
	
	Empleado* temp = this->own->find(pass, id);

	return temp ;
}

Bandeja::Bandeja()
{
	own->fromFile();
	own->setContraseña("admin");
	own->setId(0);
	own->setNomebre("admin");
}