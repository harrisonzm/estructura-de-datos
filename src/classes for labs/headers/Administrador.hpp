#pragma once
#include "../src/classes for labs\headers\Empleado.hpp"
#include "../src/DSA/DoubleLinkedList.hpp"
#include "../src/classes for labs\headers\Usuario.hpp"
#include <string>
class Administrador : public Empleado
{	
	public:
		
		static void toFile();
		static void fromFile();
		~Administrador();
	private:

		bool eliminar_usuario(int);
		bool agregar_usuario(std::string, int, std::string, std::string, int, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
		bool modificar_contrasena(std::string, std::string);

		static DoubleLinkedList<Empleado>* empleados ;
		static DoubleLinkedList<Usuario>* usuarios ;

		void sort_users();
};

