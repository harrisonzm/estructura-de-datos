#pragma once
#include <string>
#include <cstddef>
class Mensaje
{public:


	int get_id();
	int get_id_remitente();
	int get_id_destinatario();
	std::string get_contenido();
	std::string get_fecha();
	std::string get_hora();
	std::string get_titulo();

	void set_id(int);
	void set_contenido(std::string);
	void set_fecha(std::string);
	void set_hora(std::string);
	void set_id_remitente(int);
	void set_id_destinatario(int);

	Mensaje();
	Mensaje(int, int, int,std::string, std::string, std::string, std::string);


private:
	int id = NULL;
	int id_remitente = NULL;
	int id_destinatario = NULL;
	std::string titulo = "";
	std::string contenido = "";
	std::string fecha = "";
	std::string hora = "";

};

