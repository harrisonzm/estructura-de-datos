#pragma once
#include "classes for labs/headers/Usuario.hpp"
#include "classes for labs/headers/Administrador.hpp"
#include "classes for labs/headers/Empleado.hpp"
class Bandeja
{

public:

	Empleado* iniciar();
	Bandeja();


private:
	Admin* own = new Admin();
};

