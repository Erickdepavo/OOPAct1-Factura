#include <iostream>
#include <string>

using namespace std;

class Vendedor{

    public:

        //Atributos vendedor//
        
        string cve_vendedor;
        string nombre;

        // Métodos vendedor //

        Vendedores(string cve_vendedor, string nombre); // Constructor
        void addVendedores(); // Añadir vendedores
};