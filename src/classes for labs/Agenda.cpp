#include "classes for labs/headers/Usuario.hpp"
#include "classes for labs/headers/Agenda.hpp"
#include <cstddef> 
#include <fstream>
#include <iostream>
#include <string>


Agenda::Agenda(int size) 
{
    Usuario *registro = new Usuario[size];
    this->size = size;
}


int Agenda::buscar(int id) 
{   
    if (size == no_registro)
    {
        return -1;
    }
    else if (no_registro == 0) {
        return -1;
    }
    else {
        for (int i = 0; i < (this->no_registro); i++) {
            if ((this->registro)[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }
}


bool Agenda::agregar(Usuario& user) 
{
    if (buscar(user.getId()) > -1) {
        registro[no_registro] = user;
        no_registro++;
        return true;

    }
    else {
        std::cout<<"ya está en la lista"<<"\n";
        return false;
    }
}


bool Agenda::eliminar(int id) 
{
    int index = buscar(id);
    if (index == 1) {
        return false;
    }
    else {
        for (int i = index; i < no_registro - 1; i++) {
            registro[i] = registro[i + 1];
        }
        no_registro--;
        return true;
    }
}


void Agenda::toFile() 
{
    std::ofstream archivo;
    archivo.open("agenda.txt", std::ios::out);
    for (int i = 0; i < no_registro; i++) {
        archivo << registro[i].toString();
    }
    archivo.close();

}


void Agenda::import() 
{
    std::string linea;
    std::ifstream archivo;
    archivo.open("agenda.txt", std::ios::in);
    while (!archivo.eof()) 
    {

        getline(archivo, linea,',');
        std::string info[12];
        std::string infoPiece = "";
        int count = 0;
        for (int i = 0; i < linea.size(); i++){
			if (linea[i] == ','){
				info[count] = infoPiece;
				infoPiece = "";
				count++;
			}
			else{
				infoPiece += linea[i];
			}
            
        }
        Usuario* user = new Usuario(info[0], std::stoi(info[1]), new Fecha(std::stoi(info[2]), std::stoi(info[3]), std::stoi(info[4])), info[5], std::stoi(info[6]), info[7], new Direccion(info[8], info[9], info[10], info[11]));
        registro[no_registro] = *user;
        no_registro++;


        info->clear();
    }
    archivo.close();
}

Agenda::~Agenda() 
{
    delete[] registro;
}



