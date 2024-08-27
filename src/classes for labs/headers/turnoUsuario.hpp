#pragma once
#include "classes for labs/headers/Usuario.hpp"
#include "DSA/Queue.hpp"
#include "DSA/Stack.hpp"

class turnoUsuario
{
public:
	turnoUsuario();

	void registra(Usuario* user);
	void atenderSiguiente();
	void toFile();

private:
	Queue<Usuario> registro;
	Stack<Usuario> usuarioAtendido;
};

