#include <cstddef> 
#include <fstream>
#include <iostream>
#include <string>
#include "Usuario.hpp"
#include "Agenda.hpp"


Agenda::Agenda(int size) 
{
    registro = new Usuario[size];
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
    if (buscar(user.getId()) != -1) {
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
        archivo << registro[i] << "\n";
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
        std::string info[11];
        std::string infoPiece = "";
        int count = 0;
        for (int i = 0; i < linea.size(); i++){
            std::string letra = std::string(1,linea.at(i));
            std::string salto1 = letra + linea.at(i + 1);
            std::string salto2 =  linea.at(i - 1) + letra;
            if (salto1 == "\n" || salto2 == "\n") {
                continue;
            }
            if ((linea.at(i) - ',') == 0 || linea.at(i) == '-') {
                info[count++];
                infoPiece = "";
                continue;

            }
            else {
                infoPiece += linea.at(i);
            }
        }
        Usuario* user = new Usuario(linea[0], linea[1], new Fecha(linea[2], linea[3], linea[4]), linea[5], linea[6], linea[7], new Direccion(linea[8], linea[9], linea[10], linea[11]));
        registro[no_registro] = user;
        no_registro++;


        info->clear();
    }
    archivo.close();
}

Agenda::~Agenda() 
{
    delete[] registro;
}



