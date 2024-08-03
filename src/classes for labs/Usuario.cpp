#include "../src/classes for labs/headers/Usuario.hpp"
#include <iostream>
#include <cstddef>
#include <format>


Fecha::Fecha(void) {}
Fecha::Fecha(Fecha& f) {
    aa = f.aa;
    dd = f.dd;
    mm = f.mm;
}
Fecha::Fecha(int dd, int mm, int aa) {
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

std::ostream& Fecha::operator <<  (std::ostream& COUT) {
    std::string txt = toString();
    COUT << txt;
    return COUT;
}



Direccion::Direccion(void) {}
Direccion::Direccion(Direccion& d) {
    this->calle = d.calle;
    this->nomenclatura = d.nomenclatura;
    this->barrio = d.barrio;
    this->ciudad = d.ciudad;
    this->edifico = d.edifico;
    this->apto = d.apto;

}
Direccion::Direccion(std::string calle , std::string nomencl , std::string barrio , std::string ciudad , std::string edificio , std::string apto ) {
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
    COUT << txt;
    return COUT;
}



Usuario::Usuario(void) {}
Usuario::Usuario(Usuario& u) {
    nombre = u.nombre;
    id = u.id;
    fecha_nacimiento =new Fecha( *u.fecha_nacimiento);
    ciudad_nacimiento = u.ciudad_nacimiento;
    tel = u.tel;
    email = u.email;
    dir = new Direccion(*u.dir);

}
Usuario::Usuario(std::string name , int ID , Fecha* fecha , std::string ciudad , int telefono , std::string correo , Direccion* direccion ) {
nombre            = name;
id                = ID;
fecha_nacimiento  = fecha;
ciudad_nacimiento = ciudad;
tel               = telefono;
email             = correo;
dir               = direccion;
}


void Usuario::setNomebre(std::string n) { this->nombre = n; }
void Usuario::setId(int id) { this->id = id; }
void Usuario::setFecha_nacimiento(Fecha* fecha) { this->fecha_nacimiento = fecha; }
void Usuario::setCiudad_nacimiento(std::string ciudad) { this->ciudad_nacimiento = ciudad; }
void Usuario::setTel(int tel) { this->tel = tel; }
void Usuario::setemail(std::string email) { this->email = email; }
void Usuario::setDir(Direccion* direccion) { this->dir = direccion; }

std::string Usuario::getNombre() { return this->nombre; }
int Usuario::getId() { return this->id; }
Fecha* Usuario::getFecha_nacimiento() { return this->fecha_nacimiento; }
std::string Usuario::getCiudad_nacimiento() { return this->ciudad_nacimiento; }
int Usuario::getTel() { return this->tel; }
std::string Usuario::getEmail() { return this->email; }
Direccion* Usuario::getDir() { return this->dir; }

std::string Usuario::toString() {
    return std::format("%s,%d,%s,%s,%d,%s,%s\n", nombre, id, (fecha_nacimiento->toString()), ciudad_nacimiento, tel, email, dir->toString());
}
std::ostream& Usuario::operator<< (std::ostream& COUT) {
    std::string txt = toString();
    COUT << txt;
    return COUT;
}
bool Usuario::operator!= (Usuario& u) {
	return &u != this;
}

Usuario::~Usuario() {
    delete fecha_nacimiento;
    delete dir;
}


