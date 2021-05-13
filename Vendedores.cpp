#include <iostream>
#include <string>
#include "Vendedores.h"

using namespace std;

// Constrcutor de Vendedores //

Vendedores::Vendedores(string cve_vendedor, string nombre){

    // Corresponder variables en constructor //

    this -> cve_vendedor = cve_vendedor;
    this -> nombre = nombre;
}

