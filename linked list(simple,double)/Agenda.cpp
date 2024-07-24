#include <cstddef> 
#include <fstream>
#include <iostream>
#include <string>
#include "Usuario.h"
#include "Agenda.h"

template<size_t size>
Agenda<size>::Agenda() 
{
    registro = new Usuario[size];
}

template<size_t size>
int Agenda<size>::buscar(int id) 
{
    if (no_registro == 0) {
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

template<size_t size>
bool Agenda<size>::agregar(Usuario& user) 
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

template<size_t size>
bool Agenda<size>::eliminar(int id) 
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

template<size_t size>
void Agenda<size>::toFile() 
{
    std::ofstream archivo;
    archivo.open("agenda.txt", std::ios::out);
    for (int i = 0; i < no_registro; i++) {
        archivo << registro[i] + "\n";
    }
    archivo.close();

}

template<size_t size>
void Agenda<size>::import() 
{
    std::string linea;
    std::ifstream archivo;
    archivo.open("agenda.txt", std::ios::in);
    while (!archivo.eof()) 
    {

        archivo.getline(archivo, linea);
        std::string info[11];
        std::string infoPiece = "";
        for (int i = 0; i < linea.size(); i++){
            char   letra = linea.at(i);
            std::string salto1 = letra + linea.at(i + 1);
            std::string salto2 = linea.at(i - 1) + letra;
            if (salto1 == "\n" || salto2 == "\n") {
                continue;
            }
            if ((linea.at(i) - ',') == 0 || linea.at(i) == '-') {
                info.append(infoPiece);
                infoPiece = "";
                continue;

            }
            else {
                infoPiece += linea.at(i);
            }
        }
        Usuario user = Usuario(linea[0], linea[1], Fecha((int)linea[2], (int)linea[3], (int)linea[4]), linea[5], (int)linea[6], linea[7], Direccion(linea[8], linea[9], linea[10], linea[11]));
        (this->registro)[no_registro] = user;
        no_registro++;


        info->clear();
    }
    archivo.close();
}
template<size_t size>
Agenda<size>::~Agenda() 
{
    delete[] registro;
}



