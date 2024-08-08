#pragma once
#include "classes for labs/headers/Usuario.hpp"
#include <cstddef> 
#include <fstream>
#include <iostream>

class Agenda {

public:

    int buscar(int id);
    bool agregar(Usuario& user);
    bool eliminar(int id);

    void toFile();
    void import();

    Agenda(int);
    ~Agenda();

private:

    Usuario* registro = nullptr;
    int no_registro = 0;
    int size = 0;
};



