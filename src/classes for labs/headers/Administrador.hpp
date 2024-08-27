#pragma once
#include "classes for labs\headers\Empleado.hpp"
#include "DSA/DoubleLinkedList.hpp"
#include "classes for labs/headers/Mensaje.hpp"
#include "classes for labs\headers\Usuario.hpp"
#include <string>
class Admin : public Empleado
{	
	public:
		
		void toFile();
		void fromFile();
		
		Admin(void);
		Admin(Admin& admn);
		Admin(std::string passw , std::string name , int ID , Fecha* fecha , std::string ciudadN , int tel , std::string email , Direccion* dir );
		~Admin();

		void enviarMensaje(Mensaje* msg);
		bool eliminarEmpleado(int);
		bool agregarEmpleado(std::string pass, std::string name, int ID, std::string dd, std::string mm, std::string aa, std::string ciudadN, int tel, std::string email, std::string calle, std::string nomenclatura, std::string barrio, std::string ciudad, std::string edificio, std::string apto);
		void agregarEmpleado(Empleado* empl);
		bool modificarContraseña(std::string pass, int id);
		Empleado* find(std::string pass, int ID);


	private:
		std::string contraseña = "";
		char employT = ' ';
		DoubleLinkedList<Empleado> empleados ;
		void sortEmpleados();
};

