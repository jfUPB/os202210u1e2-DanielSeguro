  #include <stdio.h>
  #include <stdlib.h>
  #include "../codigo/observer.h"
  #include "../codigo/observable.h"

typedef enum __impresora_event {
	IMPRESORA_ERROR,
} ImpresoraEvent;

	char* error;
	ImpresoraEvent event;
	ImpresoraEvent (*getEvent)(struct __impresora*);
	char* (*getError)(struct __impresora*);

	//Metodos
	Observable * observable;
	int (*registerObserver)(struct __impresora*, Observer*);
	int (*unregisterObserver)(struct __impresora *, Observer*);