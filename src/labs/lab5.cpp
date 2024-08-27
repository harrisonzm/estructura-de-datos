#include "labs/headers/lab5.hpp"
#include "classes for labs/headers/Administrador.hpp"
#include  "classes for labs/headers/Empleado.hpp"
#include "classes for labs/headers/Mensaje.hpp"
#include "classes for labs/headers/Bandeja.hpp"
void lab5::puntoA()
{
	Bandeja inicio = *(new Bandeja());
    
    Admin admin = *((Admin*)inicio.iniciar());

    Fecha* fecha1 = new Fecha(1, 1, 1);
    Direccion* dir1 = new Direccion("1", "1", "1", "1", "1", "1");
    Fecha* fecha2 = new Fecha(2, 2, 2);
    Direccion* dir2 = new Direccion("2", "2", "2", "2", "2", "2");
    Fecha* fecha3 = new Fecha(3, 3, 3);
    Direccion* dir3 = new Direccion("3", "3", "3", "3", "3", "3");
    Fecha* fecha4 = new Fecha(4, 4, 4);
    Direccion* dir4 = new Direccion("4", "4", "4", "4", "4", "4");
    Fecha* fecha5 = new Fecha(5, 5, 5);
    Direccion* dir5 = new Direccion("5", "5", "5", "5", "5", "5");

    Empleado* user1 = new Empleado("1111", "harrison", 10, fecha1, "10", 10, "10", dir1);
    Empleado* user2 = new Empleado("2222","largo", 20, fecha2, "20", 20, "20", dir2);
    Empleado* user3 = new Empleado("3333","jose", 30, fecha3, "30", 30, "30", dir3);
    Empleado* user4 = new Empleado("4444", "salome", 40, fecha4, "40", 40, "40", dir4);
    Empleado* user5 = new Empleado("5555","erik", 50, fecha5, "50", 50, "50", dir5);
	admin.agregarEmpleado(user1);
    admin.agregarEmpleado(user2);
    admin.agregarEmpleado(user3);
    admin.agregarEmpleado(user4);
    admin.agregarEmpleado(user5);

    Empleado* empl = inicio.iniciar();



}

void lab5::puntoB()
{

}

void lab5::puntoC()
{

}