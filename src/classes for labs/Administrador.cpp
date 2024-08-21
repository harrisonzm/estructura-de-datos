#include "classes for labs/headers/Administrador.hpp"
#include "classes for labs/headers/Empleado.hpp"
#include "classes for labs/headers/Usuario.hpp"
#include "classes for labs/headers/Mensaje.hpp"
#include "DSA/DoubleLinkedList.hpp"
#include "DSA/Sort.hpp"
#include <iostream>
#include <fstream>
#include <string>


void Administrador::toFile()
{
	std::ofstream file;
	file.open("../Empleado.txt", std::ios::out);
	NodoDoble<Empleado>* curr = empleados.First();
	while (curr != nullptr)
	{
		file << curr->value.toString();
	}
	file.close();
}

void Administrador::fromFile()
{

	std::string linea;
	std::ifstream archivo;
	archivo.open("Empleado.txt", std::ios::in);
	while (getline(archivo, linea))
	{

		
		std::string info[14];
		std::string infoPiece = "";
		int count = 0;
		for (int i = 0; i < linea.size(); i++) {
			if (linea[i] == ',') {
				info[count] = infoPiece;
				infoPiece = "";
				count++;
			}
			else {
				infoPiece += linea[i];
			}

		}
		Empleado* employed = new Empleado();
		agregarEmpleado("0000", info[0], std::stoi(info[1]), info[2], info[3], info[4], info[5], std::stoi(info[6]), info[7], info[8], info[9], info[10], info[11],info[12],info[13]);
		sortEmpleados();


		info->clear();
	}
	archivo.close();

	sortEmpleados();

}
bool Administrador::eliminarEmpleado(int  id){
	NodoDoble<Empleado>* curr = empleados.First();
	while(curr != nullptr)
	{
		if(curr->value.getId() == id)
		{
			empleados.remove(curr);
			return true;
		}
		curr = curr->next;
	}
	return false;
}

void Administrador:: sortEmpleados()
{
	empleados.setFirst(sort::mergeSortList(&empleados)->First());
}

bool Administrador::agregarEmpleado(std::string pass, std::string name, int ID, std::string dd,std::string mm,std::string aa, std::string ciudadN, int tel, std::string email, std::string calle, std::string nomenclatura, std::string barrio, std::string ciudad, std::string edificio, std::string apto) 
{	
	try
	{
		int i = 0;
		int j = 0;
		std::string formatF[3];

		Direccion* dir = new Direccion(calle, nomenclatura, barrio, ciudad, edificio, apto);

		Fecha* fechaO = new Fecha(std::stoi(dd), std::stoi(mm), std::stoi(aa));
		Empleado* nuevo = new Empleado(pass, name, ID, fechaO, ciudadN, tel, email, dir);
		empleados.addLast(*nuevo);
		sortEmpleados();
		return true;
	}
	catch (std::exception e)
	{
		return false;
	}
}

bool Administrador::modificarContraseña(std::string pass, int id)
{
	try {
		NodoDoble<Empleado>* curr = empleados.First();
		while (curr->value.getId() != id)
		{
			curr = curr->next;
		}
		curr->value.setContraseña(pass);
		return true;
	}
	catch (std::exception e)
	{
		return false;
	}
}



Administrador::Administrador( std::string name , std::string passw = "0000", int ID = 0, Fecha* fecha = nullptr, std::string ciudadN = "Na", int tel = 0, std::string email = "Na", Direccion* dir = nullptr)
{
	this->contraseña = passw;
	setNomebre(name);
	setId(ID);
	setFechaNacimiento(fecha);
	setCiudadNacimiento(ciudadN);
	setTel(tel);
	setemail(email);
	setDir(dir);
	employT = 'a';

}

Administrador::Administrador() {

}

Administrador::~Administrador() {}