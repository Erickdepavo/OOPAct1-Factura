#include <iostream>
#include <string>

using namespace std;

class Vendedor{

    public:

        //Atributos vendedor//
        
        string cve_vendedor;
        string nombre;

        // Métodos vendedor //
        Vendedor(); // Constructor Default 
        Vendedor(string cve_vendedor, string nombre); // Constructor
        void addVendedor(Vendedor vendedores[], int cont); // Añadir vendedores
};