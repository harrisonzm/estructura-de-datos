#pragma once
#include <string>
#include <iostream>
#include <cstddef>
#include <format>

class Fecha
{
    private:

        int dd = 0;
        int mm = 0;
        int aa = 0;

    public:
        Fecha(void);
        Fecha(Fecha& f);
        Fecha(int dd = 0, int mm = 0, int aa = 0);
        void setDia(int d);
        void setMes(int m);
        void setA(int a);

        int getDia();
        int getMes();
        int getA();

        std::string toString();

        std::ostream& operator<< (std::ostream& COUT);
    };

class Direccion {
    private:

        std::string calle = "";
        std::string nomenclatura = "";
        std::string barrio = "";
        std::string ciudad = "";
        std::string edifico = "";
        std::string apto = "";

    public:
        Direccion(void);
        Direccion(Direccion& d);
        Direccion(std::string calle = "Na", std::string nomencl = "Na", std::string barrio = "Na", std::string ciudad = "Na", std::string edificio = "Na", std::string apto = "Na");


        void setCalle(std::string c);
        void setNomenclatura(std::string n);
        void setBarrio(std::string b);
        void setCiudad(std::string c);
        void setEdificio(std::string e);
        void setApto(std::string a);

        std::string getCalle(std::string c);
        std::string getNomenclatura(std::string n);
        std::string getBarrio(std::string b);
        std::string getCiudad(std::string c);
        std::string getEdificio(std::string e);
        std::string getApto(std::string a);

        std::string toString();
        std::ostream& operator<< (std::ostream& COUT);
};

class Usuario {
    private:

        std::string nombre = "";
        int id = 0;
        Fecha* fecha_nacimiento = nullptr;
        std::string ciudad_nacimiento = "";
        int tel = 0;
        std::string email = "";
        Direccion* dir = nullptr;

    public:

        Usuario(void);
        Usuario(Usuario& u);
        Usuario(std::string name , int ID = 0, Fecha* fecha = nullptr, std::string ciudad = "Na", int telefono = 0, std::string correo = "Na", Direccion* direccion = nullptr);


        void setNomebre(std::string n);
        void setId(int id);
        void setFecha_nacimiento(Fecha* fecha);
        void setCiudad_nacimiento(std::string ciudad);
        void setTel(int tel);
        void setemail(std::string email);
        void setDir(Direccion* direccion);

        std::string getNombre();
        int getId();
        Fecha* getFecha_nacimiento();
        std::string getCiudad_nacimiento();
        int getTel();
        std::string getEmail();
        Direccion* getDir();

        std::string toString();
        std::ostream& operator<< (std::ostream& COUT);
        bool operator!=(Usuario& u);
        ~Usuario();

};
