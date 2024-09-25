#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <cstddef>
#include <format>

class Fecha
{

    public:
        Fecha();
        Fecha(Fecha& f);
        Fecha(int dd , int mm , int aa );
        void setDia(int d);
        void setMes(int m);
        void setA(int a);

        int getDia();
        int getMes();
        int getA();

        std::string toString();

        std::ostream& operator<< (std::ostream& COUT);

    private:

        int dd = 0;
        int mm = 0;
        int aa = 0;
    };

class Direccion {
    public:
        Direccion();
        Direccion(Direccion& d);
        Direccion(std::string calle , std::string nomencl , std::string barrio , std::string ciudad , std::string edificio , std::string apto );


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
    
private:

        std::string calle = "";
        std::string nomenclatura = "";
        std::string barrio = "";
        std::string ciudad = "";
        std::string edifico = "";
        std::string apto = "";

};

class Usuario {

    public:

        Usuario(void);
        Usuario(const Usuario& u)noexcept;
        Usuario(Usuario&& u) noexcept;
        Usuario(std::string name , int ID , Fecha* fecha , std::string ciudad , int telefono , std::string correo , Direccion* direccion );
        Usuario(std::string name, int ID);
        ~Usuario();


        void setNomebre(std::string n);
        void setId(int id);
        void setFechaNacimiento(Fecha* fecha);
        void setCiudadNacimiento(std::string ciudad);
        void setTel(int tel);
        void setemail(std::string email);
        void setDir(Direccion* direccion);

        std::string getNombre();
        int getId() const ;
        Fecha* getFechaNacimiento();
        std::string getCiudadNacimiento();
        int getTel();
        std::string getEmail();
        Direccion* getDir();

        std::stringstream toString();
        friend std::ostream& operator<<(std::ostream& os, const Usuario& usuario);
        bool operator!=(Usuario& u);
        bool operator==(Usuario& u);
        void operator=(Usuario& u);

    private:

        std::string nombre = "";
        int id = 0;
        Fecha* fecha_nacimiento = nullptr;
        std::string ciudad_nacimiento = "";
        int tel = 0;
        std::string email = "";
        Direccion* dir = nullptr;
};
