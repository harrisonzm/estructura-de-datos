#pragma once
#include "classes for labs/headers/Empleado.hpp"
#include "DSA/DoubleLinkedList.hpp"
#include "classes for labs/headers/Mensaje.hpp"
#include "classes for labs/headers/Usuario.hpp"
#include <string>
class Empleado : public Usuario
{
	public:
		void ver_mensaje(int, std::string, std::string, std::string);
		bool eliminar_mensaje(std::string, std::string, std::string);
		void showMessages();
		bool enviar_mensaje(std::string titulo, std::string contenido, NodoDoble<Empleado> destino, std::string fecha);

		void setContraseña(std::string pass);

		bool operator<=(Empleado& member2);
		bool operator>=(Empleado& member2);
		bool operator<(Empleado& member2);
		bool operator>(Empleado& member2);
		
		std::ostream& operator<<(std::ostream& OUT);
		std::string toString();

		Empleado(void);
		Empleado(std::string pass, std::string name , int ID , Fecha* fecha , std::string ciudadN , int telefono , std::string correo , Direccion* direccion );
		~Empleado();
private:
		std::string contraseña = "";
		char employT = ' ';
		DoubleLinkedList<Mensaje> mensajes = nullptr;
		Mensaje buscar_mensaje(int id,std::string, std::string, std::string);
};

