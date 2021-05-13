#include <iostream>
#include <ctime>

#include <Inventario.h>
#include <Vendedor.h>

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

void GenerarFactura(int contador, Factura arreglo[], Vendedor vendedor, Inventario articulo, int cantidad) {
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

    Vendedor v1 = {"v100","Don Julio Estrella"};
    Vendedor v2 = {"v200","Doña Esperanza Luna"};
    vendedores[0] = v1;
    vendedores[1] = v2;

    Inventario i1 = {"i500","Tornillo sin fin",10.0};
    Inventario i2 = {"i100","Piñon cremallera",10.0};
    Inventario i3 = {"i700","Ángulo de Ackerman",10.0};
    articulos[0] = i1;
    articulos[1] = i2;
    articulos[2] = i3;

    GenerarFactura(contadorFacturas,facturas,v1,i2,32);

    // imprimimos todas las facturas
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