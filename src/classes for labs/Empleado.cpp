#include "classes for labs/headers/Empleado.hpp"
#include "classes for labs/headers/Empleado.hpp"
#include "DSA/DoubleLinkedList.hpp"
#include "classes for labs/headers/Mensaje.hpp"
#include "classes for labs/headers/Usuario.hpp"
#include <string>

Mensaje Empleado::buscar_mensaje(int id, std::string titulo, std::string fecha, std::string hora)
{
	NodoDoble<Mensaje>* curr = mensajes.First();
	while(curr != nullptr)
	{
		if(curr->value.get_id() == id && curr->value.get_titulo() == titulo && curr->value.get_fecha() == fecha && curr->value.get_hora() == hora)
		{
			return curr->value;
		}
		curr = curr->next;
	}
	return Mensaje();
}

void Empleado::ver_mensaje(int id, std::string titulo, std::string fecha, std::string hora)
{
	Mensaje toShow = buscar_mensaje(id, titulo, fecha, hora);
	std::cout << toShow.get_contenido() << std::endl;
}

bool Empleado::eliminar_mensaje(std::string titulo, std::string fecha, std::string hora)
{
	NodoDoble<Mensaje>* curr = mensajes.First();
	while(curr != nullptr)
	{
		if(curr->value.get_titulo() == titulo && curr->value.get_fecha() == fecha && curr->value.get_hora() == hora)
		{
			mensajes.remove(curr);
			return true;
		}
	}
	return false;
}

bool Empleado::enviar_mensaje(std::string contenido)
{
	return true;
	
}



