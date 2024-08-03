#pragma once
#include "../src/classes for labs/headers/Empleado.hpp"
#include "../src/DSA/headers/DoubleLinkedList.hpp"
#include "../src/classes for labs/headers/Mensaje.hpp"
#include "../src/classes for labs/headers/Usuario.hpp"
#include <string>
class Empleado : public Usuario
{
	public:
		void ver_mensaje(int, std::string, std::string, std::string);
		bool eliminar_mensaje(std::string, std::string, std::string);
		bool enviar_mensaje(std::string);
		
		Empleado();
		Empleado(std::string passw);
		~Empleado();

	private:
		std::string contraseña = "";
		DoubleLinkedList<Mensaje> mensajes ;
		Mensaje buscar_mensaje(int id,std::string, std::string, std::string);
};

