#include "impresora.h"
#include "computador.h"

static void _destroy(Impresora* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}
/**
 * Método del observador llamado a la recepción de un evento entrante
 */
static void _notify(Impresora*this, int numero, void* subject) {
	_handleEvent(this, (Computador*) subject);
}

Impresora* Impr_create(char* name)
{
	Impresora*this = (Impresora*) malloc(sizeof(*this));

	this->name = name;
	this->destroy = _destroy;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);

	return this;
}