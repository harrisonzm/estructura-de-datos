#pragma once
#include "Usuario.hpp"
#include "DoubleLinkedList.hpp"
#include "Mensaje.hpp"
#include <string>
class Empleado : public Usuario
{
	public:
		void ver_mensaje(int, std::string, std::string, std::string);
		bool eliminar_mensaje(std::string, std::string, std::string);
		bool enviar_mensaje(std::string);
		
		Empleado();
		Empleado(std::string passw):Usuario(std::string , int, Fecha*, std::string, int, std::string , Direccion* );
		~Empleado();

	private:
		std::string contraseña = "";
		DoubleLinkedList<Mensaje> mensajes ;
		Mensaje buscar_mensaje(int id,std::string, std::string, std::string);
};

