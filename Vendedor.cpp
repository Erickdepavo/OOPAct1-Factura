#include <iostream>
#include <string>
#include "Vendedor.h"

using namespace std;

// Constrcutor de Vendedores //

Vendedor::Vendedor(string cve_vendedor, string nombre){

    // Corresponder variables en constructor //
    this -> cve_vendedor = cve_vendedor;
    this -> nombre = nombre;
}

void Vendedor::addVendedor(){

}

