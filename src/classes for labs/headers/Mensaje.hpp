#pragma once
#include <string>
#include <cstddef>
class Mensaje
{
public:

	Mensaje();
	Mensaje(int id, int idRemitente, int idDestino,std::string tiutlo, std::string contenido, std::string fecha, std::string hora);

	int getId();
	int getIdRemitente();
	int getIdDestinatario();
	std::string getContenido();
	std::string getFecha();
	std::string getHora();
	std::string getTitulo();

	void setId(int);
	void setContenido(std::string);
	void setFecha(std::string);
	void setHora(std::string);
	void setIdRemitente(int);
	void setIdDestinatario(int);

	std::string toString();
	void toShow();
	std::ostream& operator<<(std::ostream OUT);




private:
	int id = NULL;
	int idRemitente = NULL;
	int idDestinatario = NULL;
	std::string titulo = "";
	std::string contenido = "";
	std::string fecha = "";
	std::string hora = "";

};

