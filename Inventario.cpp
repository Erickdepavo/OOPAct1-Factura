#include <iostream>
#include "Inventario.h"

using namespace std;

void Inventario::addInventario(Inventario inventarios[], int contador) {
  inventarios[contador] = *this;
  contador++;
};