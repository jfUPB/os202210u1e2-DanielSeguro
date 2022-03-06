
#ifndef IMPRESORA_H
#define IMPRESORA_H
#include <stdio.h>
#include <stdlib.h>
#include "../codigo/observer.h"
#include "computador.h"

typedef struct __impresora
{
    char *name;
    void (*destroy)(struct __impresora *);
    Observer *observer;
} Impresora;

Impresora *Impresora_create(char *);
#endif