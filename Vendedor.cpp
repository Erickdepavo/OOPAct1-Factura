#include <iostream>
#include <string>
#include "Vendedor.h"

using namespace std;

// Constructor de Vendedores //

Vendedor::Vendedor(){} // Constructor Default

Vendedor::Vendedor(string cve_vendedor, string nombre){

    // Corresponder variables en constructor //
    this -> cve_vendedor = cve_vendedor;
    this -> nombre = nombre;
}

void Vendedor::addVendedor(){

}

