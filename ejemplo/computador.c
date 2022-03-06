#include "computador.h"
static void _destroy(Computador* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}

static void _ErrorImp(Computador * this, Impresora* imp)
{
	imp->registerObserver(imp, this->observer);
	printf("Error", imp->error);
}


static void _notify(Computador* this, int numero, void* Observable) {
	_handleCatEvent(this, (Impresora*) Observable);
}

Computador* COM_create(char* dogsName)
{
	Computador* this = (Computador*) malloc(sizeof(*this));
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);

	return this;
}

static void _handle_impr_event(Computador* this , Impresora* printer) {
	ImpresoraEvent event = printer->getEvent(printer);
	switch (event) {
	case IMPRESORA_ERROR:
		printf("Computer received an error from printer [%s]\n", printer->getError(printer));
		break;
	default:
		printf("Computer received an unknown event from printer [%d]\n", event);
		break;
	}