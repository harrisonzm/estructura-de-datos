#include "classes for labs/headers/Empleado.hpp"
#include "classes for labs/headers/Empleado.hpp"
#include "DSA/DoubleLinkedList.hpp"
#include "classes for labs/headers/Mensaje.hpp"
#include "classes for labs/headers/Usuario.hpp"
#include <iostream>
#include <string>
#include <sstream>

Empleado::Empleado()
{

}
Empleado::Empleado(std::string passw = "0000", std::string name = "manolo", int ID = 0, Fecha* fecha = new Fecha(), std::string ciudadN = "Na", int tel = 0, std::string email = "Na", Direccion* dir = new Direccion())
{

	contraseña = passw;
	setNomebre(name);
	setId(ID);
	setFechaNacimiento(fecha);
	setCiudadNacimiento(ciudadN);
	setTel(tel);
	setemail(email);
	setDir(dir);
	employT = 'e';

}
Empleado::~Empleado() {}

Mensaje Empleado::buscar_mensaje(int id, std::string titulo, std::string fecha, std::string hora)
{
	NodoDoble<Mensaje>* curr = mensajes.First();
	while(curr != nullptr)
	{
		if(curr->value.getId() == id && curr->value.getTitulo() == titulo && curr->value.getFecha() == fecha && curr->value.getHora() == hora)
		{
			return curr->value;
		}
		curr = curr->next;
	}
	return Mensaje();
}

void Empleado::ver_mensaje(int id, std::string titulo, std::string fecha, std::string hora)
{
	Mensaje msg = buscar_mensaje(id, titulo, fecha, hora);
	std::cout << msg.toString() << "\n";
}

bool Empleado::eliminar_mensaje(std::string titulo, std::string fecha, std::string hora)
{
	NodoDoble<Mensaje>* curr = mensajes.First();
	while(curr != nullptr)
	{
		if(curr->value.getTitulo() == titulo && curr->value.getFecha() == fecha && curr->value.getHora() == hora)
		{
			mensajes.remove(curr);
			return true;  
		}
	}
	return false;
}
void Empleado::showMessages()
{
	std::cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << "\n";
	NodoDoble<Mensaje>* curr = this->mensajes.First();
	while (curr != nullptr)
	{
		curr->value.toShow() ;
		curr = curr->next;
	}

	std::cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << "\n";
}

void agregarMensaje(Mensaje* msg)
{
	mensajes.addLast(msg);
}
bool Empleado::enviar_mensaje(std::string titulo,std::string contenido,NodoDoble<Empleado> destino,std::string fecha)
{
	Mensaje  mesg = Mensaje();
	admin.enviarMensaje(mesg);


	

	return true;
	
}

void Empleado::setContraseña(std::string pass)
{
	contraseña = pass;
}

std::string Empleado::getContraseña()
{
	return this->contraseña;
}
bool Empleado::operator<=(Empleado& member2)
{
	return this->getId() <= member2.getId();

}
bool Empleado::operator>=(Empleado& member2)
{
	return this->getId() >= member2.getId();
}
bool Empleado::operator<(Empleado& member2)
{
	return this->getId() < member2.getId();
}
bool Empleado::operator>(Empleado& member2)
{   
	return this->getId() > member2.getId();
}

std::ostream& Empleado::operator<<(std::ostream& OUT)
{	
	OUT << this->toString().str();
	return  OUT;
}


std::stringstream Empleado::toString()
{
	std::stringstream toPrint;
	toPrint << format("%s %s %s %s %s %s %s", getNombre(), getId(), getFechaNacimiento()->toString(), getCiudadNacimiento(), getTel(), getEmail(), getDir()->toString());
	return toPrint;
}

