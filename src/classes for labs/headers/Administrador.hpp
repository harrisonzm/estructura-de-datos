#pragma once
#include "classes for labs\headers\Empleado.hpp"
#include "DSA/DoubleLinkedList.hpp"
#include "classes for labs\headers\Usuario.hpp"
#include <string>
class Administrador : public Empleado
{	
	public:
		
		void toFile();
		void fromFile();
		
		Administrador(void);
		Administrador(std::string passw , std::string name , int ID , Fecha* fecha , std::string ciudadN , int tel , std::string email , Direccion* dir );
		~Administrador();

		bool eliminarEmpleado(int);
		bool agregarEmpleado(std::string pass, std::string name, int ID, std::string dd, std::string mm, std::string aa, std::string ciudadN, int tel, std::string email, std::string calle, std::string nomenclatura, std::string barrio, std::string ciudad, std::string edificio, std::string apto);
		bool modificarContraseña(std::string pass, int id);


	private:
		std::string contraseña = "";
		char employT = ' ';
		DoubleLinkedList<Empleado> empleados ;
		void sortEmpleados();
};

