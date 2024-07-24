#include "empleado.hpp"

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
}
void Empleado::ver_mensaje(int id, std::string titulo, std::string fecha, std::string hora)
{
	Mensaje toShow = buscar_mensaje(id, titulo, fecha, hora);
	std::cout << toShow.get_contenido() << std::endl;
}