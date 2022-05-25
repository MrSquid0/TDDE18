/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: David A. Pelta
 *
  */

#include <iostream>
#include <assert.h>

#include "GestionArrays.h"

using namespace std;



void testMezcla1(int n1, int n2);
void testMezcla2(int n1, int n2);
void testMezcla3();
void testOrden();
void testMaxMin();
void testMasFrecuente();
void testDistintos();


int main() {
    srand(time(0));

    cout << "Test Orden ";
    testOrden();
    cout << " -> OK ";

    cout << "\nTest Mezclas 1 ";
    testMezcla1(5, 0);
    testMezcla1(0, 5);
    testMezcla1(3, 7);
    testMezcla1(7, 3);
    testMezcla1(7, 7);
    cout << " -> OK";

    cout << "\nTest Mezclas 2 ";
    testMezcla2(5, 15);
    cout << " -> OK ";

    cout << "\nTest Mezclas 3 ";
    testMezcla3();
    cout << " -> OK ";

    cout << "\nTest Mas Frecuente ";
    testMasFrecuente();
    cout << " -> OK ";

    cout << "\nTest MaxMin ";
    testMaxMin();
    cout << " -> OK";

    cout << "\nTest TodosDistintos ";
    testDistintos();
    cout << " -> OK";
    return 0;
}


// test con tamaños correctos y arrays ordenados
void testMezcla1(int n1, int n2){
    int v1[MAX];
    int v2[MAX];
    int v3[MAX];
    int n3;

    CargaVectorOrdenado(v1, n1, -2, random()%6 + 1);
    CargaVectorOrdenado(v2, n2, 1, random()%5 + 1);
    MezclaOrdenada(v1, n1, v2, n2, v3, n3);
    assert(EstaOrdenado(v3,n3) && (n3 == n1 + n2));
}

// test con tamaños correctos y arrays desordenados
void testMezcla2(int n1, int n2){
    int v1[MAX];
    int v2[MAX];
    int v3[MAX];
    int n3;

    CargaVector(v1, n1, 1, 10);
    CargaVector(v2, n2, 1, 10);
    MezclaOrdenada(v1, n1, v2, n2, v3, n3);
    assert(n3 == 0);
}

// test con tamaños grandes y arrays ordenados
void testMezcla3(){
    int n1 = MAX-1;
    int n2 = MAX-1;
    int v1[n1];
    int v2[n2];
    int v3[MAX];
    int n3;

    CargaVectorOrdenado(v1, n1, -2, random()%6 + 1);
    CargaVectorOrdenado(v2, n2, 1, random()%5 + 1);
    MezclaOrdenada(v1, n1, v2, n2, v3, n3);
    assert(EstaOrdenado(v3,n3) && (n3 == MAX));
}



void testOrden(){
    int n = MAX/2;
    int v[n];
    for(int i = 0; i < n; i++)
        v[i] = i + 1;

    assert(EstaOrdenado(v,n));
    v[1] = 6;

    assert(!EstaOrdenado(v,n));
}

void testMaxMin(){
    int n = MAX/2;
    int v[n];

    // vector aleatorio con valores entre [0,10}
    CargaVector(v, n, 0, 10);

    v[1] = -1;
    v[n-1] = 11;
    int p_min, p_max;
    MaxMin(v,n,p_max, p_min);

    assert(v[p_min] == -1 && v[p_max] == 11);


}

void testMasFrecuente(){
    int n = MAX/2;
    int v[n];

    for(int i = 0; i < n; i++)
        v[i] = i + 1;

    // pongo el valor -1 en dos posiciones distintas
    // así el más frecuente será el -1, con dos apariciones
    v[0] = -1;
    v[n-1] = -1;

    int valor, veces;
    MasFrecuente(v,n,valor,veces);
    assert(valor == -1 && veces == 2);

}

void testDistintos(){
    int n = MAX/2;
    int v[n];
    for(int i = 0; i < n; i++)
        v[i] = i + 1;

    assert(TodosDistintos(v,n));
    v[1] = 6;
    assert(!TodosDistintos(v,n));
}

