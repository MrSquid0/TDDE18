#ifndef TIEMPO_H
#define TIEMPO_H

struct tiempo{
    int horas = 0;
    int minutos = 0;
    int segundos = 0;
};

bool esPosterior (tiempo const t1, tiempo const t2);

int tiempoEnSegundos (tiempo const t1);

void segundosEnTiempo (int const s, tiempo &t1);

tiempo obtenerNuevoTiempo (tiempo &t1, int &s);

#endif
