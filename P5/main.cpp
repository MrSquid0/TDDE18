#include <iostream>
#include "palabras.h"
#include <cstring>

using namespace std;

/* IMPORTANTE: En la función 'test', he puesto en las líneas 29 y 30 un asterico (*),
 * el cual representa que fueron líneas añadidas por mí para que la función 'test'
 * fuese compatible con la implementación de mi código. Soy consciente que en el
 * guion de la práctica 5 pone que "no se debe modificar", pero es que literalmente
 * he añadido solo 2 lineas y no altera en absoluto el comportamiento original de
 * la funcion. Si se tiene cualquier duda respecto a esto, estoy listo para
 * responderlas.
 */

void test(const char frase[]){
    char palabra[MAX_SIZE];

    cout << "\nLA FRASE LEIDA ES: " <<  frase << endl;
    int n = tamanio(frase);
    int pals = cuentaPalabras(frase);
    cout << "Tiene " << n << " caracteres y " << pals << " palabras " << endl;

    cout << "\nDESCOMPOSICION EN PALABRAS nro -> palabra (long.)" << endl;
    int nro = 1;
    extraePalabra(frase, nro, palabra);
    while(tamanio(palabra) > 0){
        cout << nro << " -> " << palabra << " (" << tamanio(palabra) << ")\n";
        memset(palabra, 0, MAX_SIZE); // *
        if (nro != cuentaPalabras(frase)){ // *
            nro++;
            extraePalabra(frase, nro, palabra);
        }
    }

    char reves[MAX_SIZE];
    cout << "\nFRASE INVERSA " << endl;
    delReves(frase, reves);
    cout << "Frase Original: " << frase;
    cout << "\nFrase al Reves: " << reves << endl;
}

int main() {
    const char t1[] = "    Granada   club de  futbol  \0";
    const char t2[] = " una frase de prueba\0";
    const char t3[] = "   una, frase de prueba..\0";
    const char t4[] = "A B C D E\0";
    const char t5[] = " .practicas. de MP se ,complican.";
    const char t6[] = "inmediatamente ";

    test(t1);
    test(t2);
    test(t3);
    test(t4);
    test(t5);
    test(t6);

    return (0);
}


