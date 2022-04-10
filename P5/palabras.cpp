//Mi programa produce la salida esperada con todos los ejemplos del guion
//IMPORTANTE: Aclaración hecha en "main.cpp"

#include <iostream>
#include <cstring>
#include "palabras.h"

int tamanio(const char s[]) {
    int cont = 0;

    while (s[cont] != TERMINADOR)
        cont++;

    return cont;
}

// funcion "privada".
// PRE: j siempre esta en el rango correcto
bool empiezaPalabra(const char s[], int j) {

    bool es_letra_actual;
    bool hay_sep_previo = true;

    es_letra_actual = s[j] != SEP;
    if ( j > 0)
        hay_sep_previo = (s[j - 1] == SEP);


    return (es_letra_actual && hay_sep_previo);
}

// funcion "privada".
// PRE: j siempre esta en el rango correcto
bool terminaPalabra(const char s[], int j) {

    bool es_letra_actual = (s[j] != SEP);
    bool hay_sep_sig = (s[j + 1] == SEP) || (s[j + 1] == TERMINADOR);

    return (es_letra_actual && hay_sep_sig);
}


int posPalabra(const char msg[], int nroPal) {
    if (nroPal > cuentaPalabras(msg)){
        std::cerr << "El numero de palabra " << nroPal << " no existe.";
        exit(1);
    }

    int pos = 0;
    int k = 0;
    int contadorPalabras = 0;
    bool encontrado = false;

    while (!encontrado && msg[k] != TERMINADOR){
        if (empiezaPalabra(&msg[0], k)){
            contadorPalabras++;
        }
        if (k != 0){
            pos++;
        }
        k++;

        encontrado = contadorPalabras == nroPal;
    }
    return pos;
}

int longPalabra(const char s[], int nroPal) {
    if (nroPal > cuentaPalabras(s)){
        std::cerr << "El numero de palabra " << nroPal << " no existe.";
        exit(1);
    }
    int k = 0;
    int contadorPalabras = 0;
    int posFinal = 0;
    int longitudPalabra;
    int posInicial = posPalabra(s, nroPal); // primera pos de la palabra
    bool encontrado = false;

    while (!encontrado && s[k] != TERMINADOR){
        if (terminaPalabra(&s[0], k)){
            contadorPalabras++;
        }
        posFinal++;
        k++;
        if (contadorPalabras == nroPal){
            longitudPalabra = posFinal - posInicial;
            encontrado = true;
        }
    }
    return longitudPalabra;
}


int cuentaPalabras(const char msg[]) {
    int k = 0;
    int numeroDePalabras = 0;
    while (msg[k] != TERMINADOR) {
        if (empiezaPalabra(&msg[0], k)) {
            numeroDePalabras++;
        }
        k++;
    }
    return numeroDePalabras;
}

void extraePalabra(const char msg[], int nroPal, char salida[]) {

    if (tamanio(salida) > 0){
        memset(salida, 0, MAX_SIZE); //limpiar la cadena de caracteres
    }
    int posInicial = posPalabra(msg, nroPal);

    if (nroPal > cuentaPalabras(msg)){
        std::cerr << "El numero de palabra " << nroPal << " no existe.";
    } else {
        int j = 0;
        int tamanioSalida = longPalabra(msg, nroPal);
        while (j < tamanioSalida){
            salida[j] = msg[posInicial];
            posInicial++;
            j++;
        }
    }
}

void delReves(const char msg[], char msg_reves[]) {
    if (tamanio(msg_reves) > 0){
        memset(msg_reves, 0, MAX_SIZE); //limpiar la cadena de caracteres
    }
    agregaPalabra(msg_reves, msg);
}

void agregaPalabra(char msg[], const char pal[]) {
    int indiceMsg = 0;
    int numPalabrasPal = cuentaPalabras(pal);
    int indicePal = posPalabra(pal, numPalabrasPal);

    while (numPalabrasPal > 0){
        msg[indiceMsg] = pal[indicePal];
        indiceMsg++;
        indicePal++;
        if (pal[indicePal] == TERMINADOR || pal[indicePal] == SEP){
            numPalabrasPal--;
            if (numPalabrasPal != 0){
                msg[indiceMsg] = '-';
            }
            indiceMsg++;
            indicePal = posPalabra(pal, numPalabrasPal);
        }
    }
}