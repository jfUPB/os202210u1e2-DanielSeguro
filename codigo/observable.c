/*

 * observable.c
 *
 *  Created on: 11 oct. 2012
 *      Author: Alexandre Melard
 */
#include "common.h"
#include "observable.h"

/**
 * Destructor for Observable object.
 * use to clean up the memory
 * @param this
 */
static void _destroy(Observable* this) {
	if (NULL != this) {
		free(this);
		this = NULL;
	}
}




static int _registerObserver(Observable* this, Observer* observer)
{
	int i = 0;

	for (; i < MAX_OBSERVERS; i++) {
		if (this->observers[i] == NULL) {
			this->observers[i] = observer;

			return OK;
		}
	}

	printf("[INF] [SUBJECT] we have rush the max number of observers\n");
	return KO;
}

static int _unregisterObserver(Observable*this, Observer* observer)
{
	int i = 0;

	for (; i < MAX_OBSERVERS; i++) {
		void* pObserver = this->observers[i];

		if (observer == pObserver) {
			pObserver = NULL;
			return OK;
		}
	}

	return KO;
}

static void _notifyObservers(Observable* this)
{
	int i = 0;

	for (; i < MAX_OBSERVERS; i++) {
		if (this->observers[i] != NULL) {
			this->observers[i]->notify(this->observers[i], this->type, this->impl);
		}
	}
}
/**
 * Constructor
 * @return Instancia del observable
 */
Observable * observable_new(void* impl, int type) {
	Observable * this;
	this = (Observable *) calloc(1, sizeof(*this));
	this->destroy = _destroy;
	this->impl = impl;
	this->type = type;
	this->registerObserver = _registerObserver;
	this->unregisterObserver = _unregisterObserver;
	this->notifyObservers = _notifyObservers;
	return this;
}