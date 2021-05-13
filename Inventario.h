#include <iostream>

using namespace std;

class Inventario {
    public:
        string cve_articulo;
        string descripcion;
        double precio;
        
        Inventario();
        Inventario(string cve_articulo, string descripcion, double precio);
        void addInventario(Inventario inventarios[], int &contador);
};
