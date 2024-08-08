#include "classes for labs/headers/Administrador.hpp"
#include "classes for labs/headers/Empleado.hpp"
#include "classes for labs/headers/Usuario.hpp"
#include "classes for labs/headers/Mensaje.hpp"
#include "DSA/DoubleLinkedList.hpp"
#include <string>

bool Administrador::eliminar_usuario(int  id){
	NodoDoble<Empleado>* curr = empleados->First();
	while(curr != nullptr)
	{
		if(curr->value.getId() == id)
		{
			empleados->remove(curr);
			return true;
		}
		curr = curr->next;
	}
	return false;
}

void Administrador:: sort_users() {

}

bool Administrador::agregar_usuario(std::string name, int ID, std::string fecha, std::string ciudadN, int tel, std::string email, std::string calle, std::string nomenclatura, std::string barrio, std::string ciudad, std::string edificio, std::string apto) {
	std::string formatF[3];
	int i = 0;
	for(char c : fecha) {
		if(c == ',') {
			i++;
		} else {
			formatF[i] += c;
		}
	}
	
	Usuario* nuevo = new Usuario(name, ID, new Fecha(stoi(formatF[0]), stoi(formatF[1]), stoi(formatF[2])), ciudadN, tel, email, new Direccion(calle, nomenclatura, barrio, ciudad, edificio, apto));
	this->usuarios;    
	return true;
}


Administrador::~Administrador() {
	delete empleados;
	delete usuarios;;
	
}