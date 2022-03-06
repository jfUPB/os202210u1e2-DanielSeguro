#ifndef COMPUTADOR_H
#define COMPUTADOR_H
#include <stdio.h>
#include <stdlib.h>
#include "../codigo/observer.h"
#include "impresora.h"

typedef enum __comp_event
{
    IDK
} CompEvent;

typedef struct __computador
{
    char *name;
    CompEvent event;
    Observer *observer;

} Computador;

void Add(Computador *this, Impresora *imp);
void Notify(Computador *);
void Destructor(Computador *);
Computador *COMP_new(char *);
CompEvent getEvent(Computador *this);

#endif