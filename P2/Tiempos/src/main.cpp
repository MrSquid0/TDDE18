#include <iostream>
#include "tiempo.h"

using namespace std;

int main(){

    tiempo t1;
    cout << "Introduce el numero de horas: ";
    cin >> t1.horas;

    while (t1.horas > 23 || t1.horas < 0){
        cerr << "ERROR: Las horas deben estar entre 0 y 23" << endl;
        cerr << "Introduce el nuevo numero de horas: ";
        cin >> t1.horas;
    }

    cout << "Introduce el numero de minutos: ";
    cin >> t1.minutos;

    while (t1.minutos > 59 || t1.minutos < 0){
        cerr << "ERROR: Los minutos deben estar entre 0 y 59" << endl;
        cerr << "Introduce el nuevo numero de minutos: ";
        cin >> t1.minutos;
    }

    cout << "Introduce el numero de segundos: ";
    cin >> t1.segundos;

    while (t1.segundos > 59 || t1.segundos < 0){
        cerr << "ERROR: Los segundos deben estar entre 0 y 59" << endl;
        cerr << "Introduce el nuevo numero de segundos: ";
        cin >> t1.segundos;
    }

    int time = -5;

    tiempo t2;

    t2 = obtenerNuevoTiempo(t1, time);

    cout << t2.horas << " " << t2.minutos << " " << t2.segundos;


}
