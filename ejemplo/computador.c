#include "computador.h"
static void _destroy(Computador* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}

static void _handle_printer_event(Computador* this , Impresora* printer) {
	ImpresoraEvent event = printer->getEvent(printer);
	switch (event) {
	case IMPRESORA_ERROR:
		printf("[ERR] [COMPUTER] received an error from printer [%s]\n", printer->getError(printer));
		break;
	default:
		printf("[WAR] [COMPUTER] received an unknown event from printer [%d]\n", event);
		break;
	}
}
static void _ErrorImp(Computador * this, Impresora* imp)
{
	imp->registerObserver(imp, this->observer);
	printf("Error", imp->error);
}

static void _notify(Computador* this) {
	 printf("Connection done.\n");
}
Computador *COM_create(char* nombre)
{
    
	Computador* this = (Computador*) malloc(sizeof(*this));
    this->nombre = nombre;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);

	return this;
}

