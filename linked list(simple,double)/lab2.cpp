#include <iostream>
#include <cstddef>
#include <format>

using namespace std;

class Fecha {

private:
    int dd = 0;
    int mm = 0;
    int aa = 0;

public:
    Fecha(int dd = 0, int = 0, int aa = 0) {
        this->dd = dd;
        this->mm = mm;
        this->aa = aa;
    }
    void setDia(int d) { this->dd = d; }
    void setMes(int m) { this->mm = m; }
    void setA(int a)   { this->aa = a; }

    int getDia() { return this->dd; }
    int getMes() { return this->mm; }
    int getA()   { return this->aa; }

    string toString() {
        return format("%d-%d-%d", dd, mm, aa);
    }

    ostream& operator<< (ostream& COUT) {
        string txt = toString();
        COUT << txt;
        return COUT;

    }

};

class Direccion {
private:
    string calle        = "";
    string nomenclatura = "";
    string barrio       = "";
    string ciudad       = "";
    string edifico      = "";
    string apto         = "";
public:

    Direccion(string c = "Na", string n = "Na", string b = "Na", string ci = "Na", string e = "Na", string a = "Na") {
        this->calle        = c;
        this->nomenclatura = n;
        this->barrio       = b;
        this->ciudad       = ci;
        this->edifico      = e;
        this->apto         = a;
    }


    void setCalle(string c) { this->calle = c; }
    void setNomenclatura(string n) { this->nomenclatura = n; }
    void setBarrio(string b) { this->barrio = b; }
    void setCiudad(string c) { this->ciudad = c; }
    void setEdificio(string e) { this->edifico = e; }
    void setApto(string a) { this->apto = a; }

    string getCalle(string c) { return this->calle; }
    string getNomenclatura(string n) { return this->nomenclatura; }
    string getBarrio(string b) { return this->barrio; }
    string getCiudad(string c) { return this->ciudad; }
    string getEdificio(string e) { return this->edifico; }
    string getApto(string a) { return this->apto; }

    string toString() {
        return format("%s,%s,%s,%s,%s,%s,%s", calle, nomenclatura, barrio, ciudad, edifico, apto);
    }
    ostream& operator<< (ostream& COUT) {
        string txt = toString();
        COUT << txt;
        return COUT;
    }
};

class Usuario {
private:
    string nombre            = "";
    int id                   = 0;
    Fecha* fecha_nacimiento  = nullptr;
    string ciudad_nacimiento = "";
    int tel                  = 0;
    string email             = "";
    Direccion* dir           = nullptr;
public:
    Usuario(string n, int i, Fecha* f = nullptr, string c = "Na", int t = 0, string e = "Na", Direccion* d = nullptr) {
        nombre            = n;
        id                = i;
        fecha_nacimiento  = f;
        ciudad_nacimiento = c;
        tel               = t;
        email             = e;
        dir               = d;
    }


    void setNomebre(string n) { this->nombre = n; }
    void setId(int id) { this->id = id; }
    void setFecha_nacimiento(Fecha* fecha) { this->fecha_nacimiento = fecha; }
    void setCiudad_nacimiento(string ciudad) { this->ciudad_nacimiento = ciudad; }
    void setTel(int tel) { this->tel = tel; }
    void setemail(string email) { this->email = email; }
    void setDir(Direccion* direccion) { this->dir = direccion; }

    string getNombre() { return this->nombre; }
    int getId() { return this->id; }
    Fecha* getFecha_nacimiento() { return this->fecha_nacimiento; }
    string getCiudad_nacimiento() { return this->ciudad_nacimiento; }
    int getTel() { return this->tel; }
    string getEmail() { return this->email; }
    Direccion* getDir() { return this->dir; }

    string toString() {
        return format("%s,%d,%s,%s,%d,%s,%s", nombre, id, (fecha_nacimiento->toString()), ciudad_nacimiento, tel, email, dir->toString());
    }
    ostream& operator<< (ostream& COUT) {
        string txt = toString();
        COUT << txt;
        return COUT;
    }

    ~Usuario() {
        delete[] fecha_nacimiento;
        delete[] dir;
        delete fecha_nacimiento;
        delete dir;
    }

};
