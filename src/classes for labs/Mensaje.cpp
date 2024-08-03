#include "../src/classes for labs/headers/Mensaje.hpp"
#include <iostream>
#include <string>


int Mensaje::get_id()
{
	return id;
}

int Mensaje::get_id_remitente()
{
	return id_remitente;
}

int Mensaje::get_id_destinatario()
{
	return id_destinatario;
}

std::string Mensaje::get_contenido()
{
	return contenido;
}

std::string Mensaje::get_fecha()
{
	return fecha;
}

std::string Mensaje::get_hora()
{
	return hora;
}

std::string Mensaje::get_titulo()
{
	return titulo;
}

void Mensaje::set_id(int id)
{
	this->id = id;
}

void Mensaje::set_contenido(std::string contenido)
{
	this->contenido = contenido;
}

void Mensaje::set_fecha(std::string fecha)
{
	this->fecha = fecha;
}

void Mensaje::set_hora(std::string hora)
{
	this->hora = hora;
}

void Mensaje::set_id_remitente(int id_remitente)
{
	this->id_remitente = id_remitente;
}
void Mensaje::set_id_destinatario(int id_destinatario)
{
	this->id_destinatario = id_destinatario;
}


Mensaje::Mensaje()
{
}

Mensaje::Mensaje(int id, int idR, int idD, std::string contenido, std::string fecha, std::string hora, std::string)
{
	this->id = id;
	this->id_remitente = idR;
	this->id_destinatario = idD;
	this->contenido = contenido;
	this->fecha = fecha;
	this->hora = hora;
}
