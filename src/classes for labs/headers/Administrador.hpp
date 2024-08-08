#pragma once
#include "classes for labs\headers\Empleado.hpp"
#include "DSA/DoubleLinkedList.hpp"
#include "classes for labs\headers\Usuario.hpp"
#include <string>
class Administrador : public Empleado
{	
	public:
		
		static void toFile();
		static void fromFile();

		bool eliminar_usuario(int);
		bool agregar_usuario(std::string, int, std::string, std::string, int, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
		bool modificar_contrasena(std::string, std::string);

		~Administrador();

	private:

		DoubleLinkedList<Empleado>* empleados = nullptr;
		DoubleLinkedList<Usuario>* usuarios = nullptr;
		void sort_users();
};

