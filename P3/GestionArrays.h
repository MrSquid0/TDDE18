#ifndef P3_GESTIONARRAYS_H
#define P3_GESTIONARRAYS_H

/* Auto-evaluacion de funciones
MaxMin: bien
MasFrecuente: bien
EstaOrdenado: bien
TodosDistintos: bien
MezclaOrdenada: bien
Nota Autoevaluación: mal - regular - bien (deja la
correcta)
*/

const int MAX = 20;

void CargaVector(int v[], int n, int min, int max);

void CargaVectorOrdenado(int v[], int n, int inicial, int incremento);

void MaxMin (int v[], int n, int &pos_max, int &pos_min); //3 TEST OK

void MasFrecuente (int v[], int n, int &valor, int &frec); //3 TEST OK

bool EstaOrdenado (int v[], int n); //3 TEST OK

bool TodosDistintos (int v[], int n); //3 TEST OK

void MezclaOrdenada (int v1[], int n1, int v2[], int n2, int v3[], int &n3); //3 TEST OK

#endif //P3_GESTIONARRAYS_H
