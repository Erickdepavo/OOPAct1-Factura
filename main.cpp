#include <iostream>
#include <ctime>

/*
NOTA:
Importamos el .cpp en vez del .h porque CodeRunner no envía
todos los archivos como argumentos en el comando, de modo
que importar el .cpp es la única manera de que los compile.

Ejemplo:
- Como lo manda Code Runner:
    cd "/path" && g++ -std=c++17 main.cpp -o main && "path"main
- Como debería mandarlo:
    cd "/path" && g++ -std=c++17 main.cpp Vendedor.cpp Inventario.cpp -o main && "path"main
*/
#include "Inventario.cpp"
#include "Vendedor.cpp"

using namespace std;

/*
class Vendedor {
    public:
        string cve_vendedor;
        string nombre;
};

class Inventario {
    public:
        string cve_articulo;
        string descripcion;
        double precio;
};
*/

class Factura {
    public:
        string noFactura;
        string cve_vendedor;
        string cve_articulo;
        int cantidad;
};

string GETDATE() {
    /*
    // Windows
    char out[14];
    std::time_t t=std::time(NULL);
    std::strftime(out, sizeof(out), "%Y%m%d%H%S", std::localtime(&t));
    Sleep(2000);  // pauses for 10 seconds
    return out;
    */

    // Mac
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%Y%m%d%H%S",timeinfo);
    string str(buffer);

    //std::cout << str;
    return str;    
};

void GenerarFactura(int &contador, Factura arreglo[], Vendedor vendedor, Inventario articulo, int cantidad) {
    Factura nuevaFactura;
    nuevaFactura.cve_vendedor = vendedor.cve_vendedor;
    nuevaFactura.cve_articulo = articulo.cve_articulo;
    nuevaFactura.cantidad = cantidad;
    nuevaFactura.noFactura = "F" + GETDATE();
    //cout << nuevaFactura.noFactura << endl;

    arreglo[contador] = nuevaFactura;
    contador++;
};

int main() {

    Vendedor vendedores[4];
    Inventario articulos[5];
    Factura facturas[5];

    int contadorVendedores = 0;
    int contadorArticulos = 0;
    int contadorFacturas = 0;

    Vendedor v1("v100","Don Julio Estrella");
    Vendedor v2("v200","Doña Esperanza Luna");
    v1.addVendedor(vendedores, contadorVendedores);
    v2.addVendedor(vendedores, contadorVendedores);

    Inventario i1("i500","Tornillo sin fin",10.0);
    Inventario i2("i100","Piñon cremallera",10.0);
    Inventario i3("i700","Ángulo de Ackerman",10.0);
    i1.addInventario(articulos, contadorArticulos);
    i2.addInventario(articulos, contadorArticulos);
    i3.addInventario(articulos, contadorArticulos);

    GenerarFactura(contadorFacturas,facturas,v1,i2,32);
    GenerarFactura(contadorFacturas,facturas,v2,i3,23);
    GenerarFactura(contadorFacturas,facturas,v1,i1,14);

    // Imprimimos todas las facturas
    cout << "Facturas Generadas "<< endl;
    cout << "No" <<"\t\t"<<"Vendedor"<<"\t"<<"Articulo"<<"\t"<<"Nombre"<<endl;

    string nombreArticulo;
    for (int j=0; j<=contadorFacturas; j++){
        for (int k=0;k<sizeof(articulos)/sizeof(articulos[0]);k++){
            if (facturas[j].cve_articulo == articulos[k].cve_articulo)
                nombreArticulo = articulos[k].descripcion;
        }
        cout <<facturas[j].noFactura<<"\t"
            <<facturas[j].cve_vendedor<<"\t\t"
            <<facturas[j].cve_articulo<<"\t\t"
            <<nombreArticulo<<endl;
    }

    return 0;
};