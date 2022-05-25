#include <iostream>
#include "GestionArrays.h"

//Comentarios sobre la práctica hechos en "GestionArrays.h"

void CargaVector(int v[], int n, int min, int max){
    int rango = max - min;
    for(int i = 0; i < n; i++)
        v[i] = random()% rango + min;
}


void CargaVectorOrdenado(int v[], int n, int inicial, int incremento){

    v[0] = inicial;
    for(int i = 1; i < n; i++)
        v[i] = v[i-1] + random() % incremento;
}


void MaxMin (int v[], int n, int &pos_max, int &pos_min){
    pos_max = 0;
    pos_min = 0;
    for (int i=0; i<n; i++){
        if (v[i] >= v[pos_max]){
            pos_max = i;
        }

        if (v[pos_min] >= v[i]){
            pos_min = i;
        }
    }
}

void MasFrecuente (int v[], int n, int &valor, int &frec){
    frec = 0;
    int frec_interna = 0;
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (v[i] == v[j]){
                frec_interna++;
            }
        }
        if (frec_interna >= frec){
            valor = v[i];
            frec = frec_interna;
            frec_interna = 0;
        } else {
            frec_interna = 0;
        }
    }
}

bool EstaOrdenado (int v[], int n){
    bool enOrden = false;
    for (int i=0; i<n; i++){
        if (i == n-1){
            if (v[i] >= v[i-1]){
                enOrden = true;
            } else {
                enOrden = false;
            }
        } else if (v[i] <= v[i+1]){
            enOrden = true;
        } else {
            enOrden = false;
            break;
        }
    }
    return enOrden;
}

bool TodosDistintos (int v[], int n){
    int numVeces = 0;
    bool todosDistintos = true;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (v[i] == v[j]){
                numVeces++;
            }
            if (numVeces > 1){
                todosDistintos = false;
                break;
            }
        }
        numVeces = 0;
    }
    return todosDistintos;
}

void MezclaOrdenada (int v1[], int n1, int v2[], int n2, int v3[], int &n3){

int i = 0;
int j = 0;
int k = 0;

if (n1 + n2 < MAX){
    n3 = n1 + n2;
} else {
    n3 = MAX;
    n1=10;
    n2=10;
}


while (i < n1 && j < n2) {
    if (v1[i] <= v2[j]) {
        v3[k++] = v1[i++];
    } else {
        v3[k++] = v2[j++];
    }
}
//Elementos restantes
    while (i < n1){
        v3[k++] = v1[i++];
    }

    while (j < n2){
        v3[k++] = v2[j++];
    }

    //En caso de que no este ordenado v3, significa que los arrays dados no estaban en orden
    if (!EstaOrdenado(v3, n3)){
        n3 = 0;
    }

}