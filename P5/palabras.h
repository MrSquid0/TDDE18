/*
 * File:   palabras.h
 * Author: David A. Pelta
 *
 * Created on 1 de abril de 2021
 */

#ifndef PALABRAS_H
#define PALABRAS_H

const int MAX_SIZE = 1000;
const char TERMINADOR = '\0';
const char SEP = ' ';

/**
 * @brief devuelve el nro de caracteres de la cadena msg
 * @param msg texto de entrada (cstring)
 * @return un valor entero
 */
int tamanio(const char msg[]);


/**
 * @brief devuelve la posición donde empieza la palabra nroPal
 * @param msg texto de entrada (cstring)
 * @param nroPal el nro de palabra
 * @return un valor entero entre 0 y tamanio(msg)-1 si existe tal palabra. -1 en caso contrario
 */
int posPalabra(const char msg[], int nroPal);


/**
 * @brief devuelve la longitud de la palabra nroPal
 * @param msg texto de entrada (cstring)
 * @param nroPal el nro de palabra
 * @return la longitud de la palabra. 0 (cero) si no existe
 */
int longPalabra(const char s[], int nroPal);


/**
 * @brief devuelve el número de palabras de la cadena msg
 * @param msg texto de entrada (cstring)
 * @return un valor entero
 */
int cuentaPalabras(const char msg[]);


/**
 * @brief extrae la palabra nroPal de la cadena
 * @param cadenaOriginal texto de entrada (cstring)
 * @param salida cstring donde se guarda la palabra solicitada. Si la palabra no existe, se devuelve una cadena de longitud cero.
  */

void extraePalabra(const char msg[], int nroPal, char salida[]);


/**
 * @brief construye una nueva cadena, con las palabras de msg en orden inverso
 * @param msg texto de entrada (cstring)
 * @param msg_reves cstring con la cadena inversa
 */

void delReves(const char msg[], char msg_reves[]);

/**
 * @brief agrega una palabra a la cadena, insertando un guion previamente (salvo que sea la primera palabra de la cadena)
 * @param msg text de entrada (cstring) al que que agrega la palabra pal
 * @param pal cstring con la palabra a agregar
 */
void agregaPalabra(char msg[], const char pal[]);

#endif /* PALABRAS_H */