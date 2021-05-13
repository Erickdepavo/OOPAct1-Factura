#include <iostream>
#include <string>
#include "Vendedor.h"

using namespace std;

// Constructor de Vendedores //

<<<<<<< HEAD
Vendedor::Vendedor(){} // Constructor Default
=======
Vendedor::Vendedor() {} // Constrcutor Default
>>>>>>> main

Vendedor::Vendedor(string cve_vendedor, string nombre){

    // Corresponder variables en constructor //
    this -> cve_vendedor = cve_vendedor;
    this -> nombre = nombre;
}

void Vendedor::addVendedor(){
    cout << "Añadido" << endl;
}

