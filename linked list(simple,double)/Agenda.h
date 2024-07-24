#pragma once
#include "Usuario.h"
#include <cstddef> 
#include <fstream>
#include <iostream>
template<size_t size>
class Agenda {

public:

    int buscar(int id);
    bool agregar(Usuario& user);
    bool eliminar(int id);

    void toFile();
    void import();

    Agenda();
    ~Agenda();

private:

    Usuario* registro = nullptr;
    int no_registro = 0;
};



