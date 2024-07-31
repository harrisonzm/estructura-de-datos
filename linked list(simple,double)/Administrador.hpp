#pragma once
#include "Empleado.hpp"
#include "Mensaje.hpp"
#include "DoubleLinkedList.hpp"
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

