#include <iostream>
#include "Inventario.h"

using namespace std;

Inventario::Inventario() {};
Inventario::Inventario(string cve_articulo, string descripcion, double precio) {
  this -> cve_articulo = cve_articulo;
  this -> descripcion = descripcion;
  this -> precio = precio;
}

void Inventario::addInventario(Inventario inventarios[], int &contador) {
  inventarios[contador] = *this;
  contador++;
};