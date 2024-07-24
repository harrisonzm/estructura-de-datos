#pragma once
#include "Empleado.hpp"
#include "Mensaje.hpp"
#include "DoubleLinkedList.hpp"
class Administrador : public Empleado
{	
	public:
		bool eliminar_usuario(std::string);
		bool agregar_usuario(std::string, std::string, std::string, std::string, std::string, std::string);
		bool modificar_contraseña(std::string, std::string);

};

