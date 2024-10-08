#include "classes for labs/headers/Usuario.hpp"
#include <iostream>
#include <cstddef>
#include <format>
#include <string>
#include <sstream>

Fecha::Fecha()
{

}
Fecha::Fecha(Fecha& f) {
    aa = f.aa;
    dd = f.dd;
    mm = f.mm;
}
Fecha::Fecha(int dd = 0, int mm = 0, int aa = 0) {
    this->dd = dd;
    this->mm = mm;
    this->aa = aa;

}
void Fecha::setDia(int d) {
    this->dd = d;
}
void Fecha::setMes(int m) {
    this->mm = m;
}
void Fecha::setA(int a) {
    this->aa = a;
}

int Fecha::getDia() { return this->dd; }
int Fecha::getMes() { return this->mm; }
int Fecha::getA() { return this->aa; }

std::string Fecha::toString() {
    return std::format("%d,%d,%d", dd, mm, aa);
}

std::ostream& Fecha::operator<<(std::ostream& COUT) {
    
    COUT << dd << "," << mm << "," << aa <<",";
    return COUT;
}

Direccion::Direccion()
{

}
Direccion::Direccion(Direccion& d) {
    this->calle = d.calle;
    this->nomenclatura = d.nomenclatura;
    this->barrio = d.barrio;
    this->ciudad = d.ciudad;
    this->edifico = d.edifico;
    this->apto = d.apto;

}
Direccion::Direccion(std::string calle = "Na", std::string nomencl = "Na", std::string barrio = "Na", std::string ciudad = "Na", std::string edificio = "Na", std::string apto = "Na") {
    this->calle        = calle;
    this->nomenclatura = nomencl;
    this->barrio       = barrio;
    this->ciudad       = ciudad;
    this->edifico      = edificio;
    this->apto         = apto;
}


void Direccion::setCalle(std::string c) { this->calle = c; }
void Direccion::setNomenclatura(std::string n) { this->nomenclatura = n; }
void Direccion::setBarrio(std::string b) { this->barrio = b; }
void Direccion::setCiudad(std::string c) { this->ciudad = c; }
void Direccion::setEdificio(std::string e) { this->edifico = e; }
void Direccion::setApto(std::string a) { this->apto = a; }

std::string Direccion::getCalle(std::string c) { return this->calle; }
std::string Direccion::getNomenclatura(std::string n) { return this->nomenclatura; }
std::string Direccion::getBarrio(std::string b) { return this->barrio; }
std::string Direccion::getCiudad(std::string c) { return this->ciudad; }
std::string Direccion::getEdificio(std::string e) { return this->edifico; }
std::string Direccion::getApto(std::string a) { return this->apto; }

std::string Direccion::toString() {
    return std::format("%s,%s,%s,%s,%s,%s,%s", calle, nomenclatura, barrio, ciudad, edifico, apto);
}
std::ostream& Direccion::operator<< (std::ostream& COUT) {
    std::string txt = toString();
    COUT << calle << "," << nomenclatura << "," << barrio << "," << ciudad << "," << edifico << "," << apto << "," ;
    return COUT;
}

Usuario::Usuario()
{

}
// Copy constructor
Usuario::Usuario(const Usuario& u) noexcept {
    nombre = u.nombre;
    id = u.id;
    // Deep copy of dynamically allocated members
    fecha_nacimiento = new Fecha(*u.fecha_nacimiento);
    ciudad_nacimiento = u.ciudad_nacimiento;
    tel = u.tel;
    email = u.email;
    dir = new Direccion(*u.dir);  // Assuming Direccion has a copy constructor
}


// Move constructor
Usuario::Usuario(Usuario&& u) noexcept {
    nombre = std::move(u.nombre);  // Move the string member
    id = u.id;
    fecha_nacimiento = u.fecha_nacimiento;  // Steal the pointer
    u.fecha_nacimiento = nullptr;  // Leave the source in a valid state
    ciudad_nacimiento = std::move(u.ciudad_nacimiento);  // Move the string member
    tel = u.tel;
    email = std::move(u.email);  // Move the string member
    dir = u.dir;  // Steal the pointer
    u.dir = nullptr;  // Leave the source in a valid state
}


Usuario::Usuario(std::string name, int ID = 0, Fecha* fecha = nullptr, std::string ciudad = "Na", int telefono = 0, std::string correo = "Na", Direccion* direccion = nullptr) {
nombre            = name;
id                = ID;
fecha_nacimiento  = fecha;
ciudad_nacimiento = ciudad;
tel               = telefono;
email             = correo;
dir               = direccion;
}

Usuario::Usuario(std::string name, int id)
{
    nombre = name;
    this->id = id;
}

Usuario::~Usuario() {
    delete fecha_nacimiento;
    delete dir;
}

void Usuario::setNomebre(std::string n) { this->nombre = n; }
void Usuario::setId(int id) { this->id = id; }
void Usuario::setFechaNacimiento(Fecha* fecha) { this->fecha_nacimiento = fecha; }
void Usuario::setCiudadNacimiento(std::string ciudad) { this->ciudad_nacimiento = ciudad; }
void Usuario::setTel(int tel) { this->tel = tel; }
void Usuario::setemail(std::string email) { this->email = email; }
void Usuario::setDir(Direccion* direccion) { this->dir = direccion; }

std::string Usuario::getNombre() { return this->nombre; }
int Usuario::getId() const { return this->id; }
Fecha* Usuario::getFechaNacimiento() { return this->fecha_nacimiento; }
std::string Usuario::getCiudadNacimiento() { return this->ciudad_nacimiento; }
int Usuario::getTel() { return this->tel; }
std::string Usuario::getEmail() { return this->email; }
Direccion* Usuario::getDir() { return this->dir; }

std::stringstream Usuario::toString() {
    std::stringstream toPrint;
    toPrint << std::format("%s,%d,%s,%s,%d,%s,%s\n", nombre, id, (fecha_nacimiento->toString()), ciudad_nacimiento, tel, email, dir->toString());
    return toPrint;
} 

std::ostream& operator<<(std::ostream& os, const Usuario& usuario) {
    os << "Usuario ID: " << usuario.getId();
    return os;
}
bool Usuario::operator!= (Usuario& u) {
	return  ( this->getId() != u.getId());
}
bool Usuario::operator==(Usuario& u) {
    return  (this->getId() == u.getId());
}

void  Usuario::operator=(Usuario& u)
{
    nombre = u.nombre;
    id = u.id;
    fecha_nacimiento = u.getFechaNacimiento();
    ciudad_nacimiento = u.ciudad_nacimiento;
    tel = u.tel;
    email = u.email;
    dir = u.getDir();
    
}

