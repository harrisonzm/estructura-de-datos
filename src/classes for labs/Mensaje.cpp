#include "classes for labs/headers/Mensaje.hpp"
#include <iostream>
#include <string>
#include <format>


Mensaje::Mensaje()
{
}

Mensaje::Mensaje(int id, int idR, int idD, std::string contenido, std::string fecha, std::string hora, std::string titulo)
{
	this->id = id;
	this->idRemitente = idR;
	this->idDestinatario = idD;
	this->titulo = titulo;
	this->contenido = contenido;
	this->fecha = fecha;
	this->hora = hora;
}


int Mensaje::getId()
{
	return id;
}

int Mensaje::getIdRemitente()
{
	return idRemitente;
}

int Mensaje::getIdDestinatario()
{
	return idDestinatario;
}

std::string Mensaje::getContenido()
{
	return contenido;
}

std::string Mensaje::getFecha()
{
	return fecha;
}

std::string Mensaje::getHora()
{
	return hora;
}

std::string Mensaje::getTitulo()
{
	return titulo;
}

void Mensaje::setId(int id)
{
	this->id = id;
}

void Mensaje::setContenido(std::string contenido)
{
	this->contenido = contenido;
}

void Mensaje::setFecha(std::string fecha)
{
	this->fecha = fecha;
}

void Mensaje::setHora(std::string hora)
{
	this->hora = hora;
}

void Mensaje::setIdRemitente(int idRemitente)
{
	this->idRemitente = idRemitente;
}
void Mensaje::setIdDestinatario(int idDestinatario)
{
	this->idDestinatario = idDestinatario;
}

std::string Mensaje::toString()
{
	return  std::format("remitente = %s\nfecha = %s\ntitulo = %s\n", this->getIdRemitente(), this->getFecha(), this->getTitulo());
}

void Mensaje::toShow()
{
	std::cout << toString();
}

std::ostream& Mensaje::operator<<(std::ostream OUT)
{
	OUT << this->getContenido();
	return OUT;

}