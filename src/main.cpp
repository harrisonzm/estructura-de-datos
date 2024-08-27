#include "labs/headers/lab4.hpp"
#include "labs/headers/lab5.hpp"
#include "labs/headers/lab6.hpp"


    /*
int main() {
    std::cout << " lab4 ---/-/-/-//-/-/-/-/-/-/-//-/-/-/-/-/-/-/-/-/-/-//-/-/-/-/-//-/-/-/-/-\n";
    lab4::puntoA();
    lab4::puntoB();
    
    std::cout << " lab5 -/-/-/-/-/-/-/-/-/-/-/-/-/-/-//-/-/-/-/-/-/-/-/-/-//-/-/-/-/-/-/-/-/-\n";
    lab5::puntoA();
    lab5::puntoB();
    lab5::puntoC();
    
    std::cout << "lab6 -/-/-/-/-//--//-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-//-/-/-/-/-/-/-\n";
    lab6::puntoA();
    lab6::puntoB();
    lab6::puntoC();
    std::cout << "end";
    return 0;
}
    */
#include <iostream>
#include "classes for labs/headers/Administrador.hpp"
#include "classes for labs/headers/Empleado.hpp"

int main() {
    // Step 1: Create an Admin instance and add employees
    Admin admin;
    admin.setContraseña("admin");
    admin.setNomebre("admin");
    admin.setId(0);

    admin.agregarEmpleado("pass1", "John Doe", 1001, "01", "01", "1980", "City A", 1234567, "john.doe@example.com", "Street 1", "No", "Neighborhood A", "City A", "Building 1", "Apt 1");
    admin.agregarEmpleado("pass2", "Jane Smith", 1002, "02", "02", "1985", "City B", 9876543, "jane.smith@example.com", "Street 2", "No", "Neighborhood B", "City B", "Building 2", "Apt 2");

    // Step 2: Save employees to file
    admin.toFile();

    // Step 3: Clear the current list of employees (simulate fresh start)
    // Here we just create a new Admin instance for simplicity
    Admin admin2;

    // Step 4: Load employees from file
    admin2.fromFile();

    // Step 5: Print out the loaded employees to verify
    

    return 0;
}

