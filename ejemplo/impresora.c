#include "impresora.h"


static void _error(Impresora *this, char *error)
{
    this->event = IMPRESORA_ERROR;
    this->error = error;
    this->observable->notifyObservers(this->observable);
}

static int _registerObserver(Impresora *this, Observer *observer)
{
    return this->observable->registerObserver(this->observable, observer);
}

static int _unregisterObserver(Impresora *this, Observer *observer)
{
    return this->observable->unregisterObserver(this->observable, observer);
}

static void _destroy(Impresora *this)
{
    this->observable->destroy(this->observable);

    if (NULL != this)
    {
        free(this);
        this = NULL;
    }
}

Impresora *IMP_create(char *name)
{
    Impresora *this = (Impresora *)malloc(sizeof(*this));

    this->observable = observable_new(this, 1);
    this->registerObserver = _registerObserver;
    this->unregisterObserver = _unregisterObserver;

    return this;
}