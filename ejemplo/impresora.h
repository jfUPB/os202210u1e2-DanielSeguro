#include <stdio.h>
#include <stdlib.h>
#include "../codigo/observer.h"
#include "../codigo/observable.h"

#ifndef IMPRESORA_H
#define IMPRESORA_H
typedef enum __impresora_event
{
    IMPRESORA_ERROR,
} ImpresoraEvent;

typedef struct __impresora
{
   
char *error;
ImpresoraEvent event;
ImpresoraEvent (*getEvent)(struct __impresora *);
char *(*getError)(struct __impresora *);

// Metodos
Observable *observable;
int (*registerObserver)(struct __impresora *, Observer *);
int (*unregisterObserver)(struct __impresora *, Observer *);
} Impresora;

Impresora* IMP_create(char *error);
#endif