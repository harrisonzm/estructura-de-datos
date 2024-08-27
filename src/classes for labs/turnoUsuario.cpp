#include "headers/turnoUsuario.hpp"
#include "classes for labs/headers/Usuario.hpp"
#include "DSA/Queue.hpp"
#include "DSA/Stack.hpp"
#include <fstream>

turnoUsuario::turnoUsuario()
{
	registro = *(new Queue<Usuario>());
	usuarioAtendido = *(new Stack<Usuario>());
}



void turnoUsuario::registra(Usuario* user)
{
	registro.enqueue(*user);

}

void turnoUsuario::atenderSiguiente()
{	
	Usuario temp = registro.dequeue();
	 
	this->usuarioAtendido.push(temp);//need move constructor or a push overloaded with && objects
}

void turnoUsuario::toFile()
{
	std::ofstream archivoPendiente;

	archivoPendiente.open("usuariospendientes.txt", std::ios::out);
	NodoSimple<Usuario>* tempUser = registro.peek();
	while (tempUser != nullptr)
	{	
		archivoPendiente << tempUser->value.getNombre() << "," << tempUser->value.getId() << "\n";
		tempUser = tempUser->next;
	}

	archivoPendiente.close();

	std::ofstream archivoAtendido;
	archivoPendiente.open("usuariosatendidos.txt", std::ios::out);
	tempUser = usuarioAtendido.peek();
	while (tempUser != nullptr)
	{
		archivoAtendido << tempUser->value.getNombre() << "," << tempUser->value.getId() << "\n";
		tempUser = tempUser->next;
	}
	archivoAtendido.close();
}