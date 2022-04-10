#include <iostream>
#include "tiempo.h"

using namespace std;

bool esPosterior (tiempo const t1, tiempo const t2){
    if (t2.horas > t1.horas){
        return true;
    }

    if (t2.horas == t1.horas){
        if (t2.minutos > t1.minutos){
            return true;
        }
    }

    if (t2.minutos == t1.minutos){
        if (t2.segundos > t1.segundos){
            return true;
        }
    }

    return false;
}

int tiempoEnSegundos (tiempo const t1){
    int segundosDeHoras = t1.horas * 3600;
    int segundosDeMinutos = t1.minutos * 60;

    int segundosTotales = segundosDeHoras + segundosDeMinutos + t1.segundos;

    return segundosTotales;
}

void segundosEnTiempo (int const s, tiempo &t1){

    t1.horas = s / 3600;
    int restoDeSegundosEnHoras = s % 3600;

    t1.minutos = restoDeSegundosEnHoras / 60;
    int restoDeSegundosEnMinutos = restoDeSegundosEnHoras % 60;

    t1.segundos = restoDeSegundosEnMinutos;
}

tiempo obtenerNuevoTiempo (tiempo &t1, int &s){
    tiempo t2;
    t2.horas = t1.horas;
    t2.minutos = t1.minutos;
    t2.segundos = t1.segundos;

    int segundosOriginales = t2.segundos;

    t2.horas += s / 3600;
    int restoDeSegundosEnHoras = s % 3600;

    t2.minutos += restoDeSegundosEnHoras / 60;
    int restoDeSegundosEnMinutos = s % 60;

    t2.segundos += restoDeSegundosEnMinutos;

    while (t2.segundos >= 60){
        t2.minutos++;
        t2.segundos -= 60;
    }

    while (t2.segundos < 0){
        t2.minutos--;
        if (t2.segundos <= -60){
            t2.minutos--;
            t2.segundos +=60;
        } else {
            t2.segundos = 60 - abs(restoDeSegundosEnMinutos) + segundosOriginales;
        }
    }

    while (t2.minutos >= 60){
        t2.horas++;
        t2.minutos -= 60;
    }

    while (t2.minutos >= 60){
        t2.horas++;
        t2.minutos -= 60;
    }

    if (t2.horas > 23){
        cerr << "ERROR: Las horas no pueden ser superiores a 24.";
        t2.horas = 0;
        t2.minutos = 0;
        t2.segundos = 0;
    }

    return t2;
}
