#ifndef COMPUTADOR_H
#define COMPUTADOR_H
#include <stdio.h>
#include <stdlib.h>
#include "../codigo/observer.h"
#include "impresora.h"

typedef struct __computador
{
    char *nombre;
    Observer *observer;

} Computador;



#endif