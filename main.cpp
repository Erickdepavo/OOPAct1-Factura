#include <iostream>
#include <ctime>
#include <string>

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

class Factura {
    public:
        string noFactura;
        string cve_vendedor;
        string cve_articulo;
        int cantidad;
};

string GETDATE() {
    // Windows y Mac
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%Y%m%d%H%S",timeinfo);
    string str(buffer);

    return str;    
};

void GenerarFactura(int &contador, Factura arreglo[], Vendedor vendedor, Inventario articulo, int cantidad) {
    Factura nuevaFactura;
    nuevaFactura.cve_vendedor = vendedor.cve_vendedor;
    nuevaFactura.cve_articulo = articulo.cve_articulo;
    nuevaFactura.cantidad = cantidad;
    nuevaFactura.noFactura = "F" + GETDATE() + to_string(contador);

    arreglo[contador] = nuevaFactura;
    contador++;
};

void solicitarVendedor(Vendedor vendedores[], int &cont){
    
    string cve_vendedor;
    string nombre;

    cout << "Ingrese el código del vendedor: ";
    cin >> cve_vendedor;
    cout << "Ingresa el nombre del vendedor: ";
    cin >> nombre;

    Vendedor nuevoVendedor(cve_vendedor, nombre);
    nuevoVendedor.addVendedor(vendedores, cont);
}

void solicitarArticulos(Inventario inventarios[], int &contador){

    string cve_articulo;
    string descripcion;
    double precio;

    cout << "Ingresa el código del artículo: ";
    cin >> cve_articulo;
    cout << "Ingresa el nombre del artículo: ";
    cin >> descripcion;
    cout << "Ingresa el precio del artículo: ";
    cin >> precio;

    Inventario nuevoArticulo(cve_articulo, descripcion, precio);
    nuevoArticulo.addInventario(inventarios, contador);
}

void imprimirFacturas(Factura facturas[], int &contadorFacturas, Vendedor vendedores[], int &contadorVendedores, Inventario articulos[], int &contadorInventarios) {

    // Generar las facturas
    for (int index = 0; index < contadorInventarios; index++) {
        int vendedorIndex = rand() % contadorVendedores; 
        int cantidad = rand() % 100 + 1;
        GenerarFactura(contadorFacturas,facturas,vendedores[vendedorIndex],articulos[index],cantidad);
    }

    // Imprimimos todas las facturas
    cout << "No" <<"\t\t"<<"Vendedor"<<"\t"<<"Articulo"<<"\t"<<"Cantidad"<<"\t"<<"Importe"<<"\t\t"<<"Nombre"<<endl;

    string nombreArticulo;
    double precioArticulo;
    for (int j=0; j<contadorFacturas; j++){
        for (int k=0; k<contadorInventarios; k++){
            if (facturas[j].cve_articulo == articulos[k].cve_articulo)
                nombreArticulo = articulos[k].descripcion;
                precioArticulo = articulos[k].precio;
        }
        cout <<facturas[j].noFactura<<"\t"
            <<facturas[j].cve_vendedor<<"\t\t"
            <<facturas[j].cve_articulo<<"\t\t"
            <<facturas[j].cantidad<<"\t\t"
            <<"$"<<facturas[j].cantidad * precioArticulo <<"\t\t"
            <<nombreArticulo<<endl;
    }
    cout << endl << endl;
}

void clear() {
    cout << "\x1B[2J\x1B[H"; // clear multiplataforma!
}

int main() {
    
    Vendedor vendedores[4];
    Inventario articulos[5];
    Factura facturas[5];

    int contadorVendedores = 0;
    int contadorArticulos = 0;
    int contadorFacturas = 0;

    // Menu
    bool muestraAviso = false;
    string aviso = "";
    
    while (true) {
        clear();
        
        cout << "-------------- Menú --------------" << endl;
        cout << "1) Añadir vendedor" << endl;
        cout << "2) Añadir inventario (artículo)" << endl;
        cout << "3) Imprimir facturas" << endl;
        cout << "4) Salir" << endl;

        if (muestraAviso) {
            cout << endl << aviso << endl;
            aviso = "";
            muestraAviso = false;
        }

        cout << endl << "Elige una opción:" << endl;

        string option;
        cin >> option;

        // Manejar la elección
        if (option == "1") { // Añadir vendedores
            clear();
            cout << "--------- Añadir Vendedor --------" << endl << endl;

            if (contadorVendedores < sizeof(vendedores)/sizeof(vendedores[0])) {
                solicitarVendedor(vendedores, contadorVendedores);
                aviso = "Se añadió correctamente el vendedor";
            } else {
                aviso = "No se pudo añadir el vendedor; ya has llegado al máximo";
            }
            muestraAviso = true;

        } else if (option == "2") {
            clear();
            cout << "--------- Añadir Artículo --------" << endl;
            
            if (contadorArticulos < sizeof(articulos)/sizeof(articulos[0])) {
                solicitarArticulos(articulos, contadorArticulos);
                aviso = "Se añadió correctamente el artículo";
            } else {
                aviso = "No se pudo añadir el artículo; ya has llegado al máximo";
            }   
            muestraAviso = true;

        } else if (option == "3") {
            clear();
            cout << "----------------------------------- Facturas Generadas -----------------------------------" << endl << endl;

            if (contadorArticulos > 0 && contadorVendedores > 0) {
                imprimirFacturas(facturas, contadorFacturas, vendedores, contadorVendedores, articulos, contadorArticulos);
                break;
            } else {
                if (contadorArticulos == 0 && contadorVendedores == 0) {
                    aviso = "No puedes generar facturas porque no tienes articulos ni vendedores.";
                } else if (contadorArticulos == 0) {
                    aviso = "No puedes generar facturas porque no tienes articulos.";
                } else {
                    aviso = "No puedes generar facturas porque no tienes vendedores.";
                }
                muestraAviso = true;
            }
        } else if (option == "4") {
            clear();
            break;
        } else {
            aviso = "La opción que elegiste no existe.";
            muestraAviso = true;
        }
    }

    return 0;
};