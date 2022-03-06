#ifndef DOG_H
	#define DOG_H
 	#include <stdio.h>
	#include <stdlib.h>
	#include "../codigo/observer.h"
	#include "impresora.h"

	typedef struct __computador
	{
		Observer* observer;
	} Computador;

	Computador* COM_create(char *);

#endif