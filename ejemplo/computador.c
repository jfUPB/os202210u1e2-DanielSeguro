#include "computador.h"
static void Destructor(Computador *this)
{
    this->observer->destroy(this->observer);

    if (this != NULL)
    {
        free(this);
        this = NULL;
    }
}

static void Add(Computador *this, Impresora *imp)
{
    imp->registerObserver(imp, this->observer);
}

static void Notify(Computador *this)
{
    printf("Connection done.\n");
}
Computador *COM_create(char *nombre)
{
    Computador *this = (Computador *)malloc(sizeof(*this));
    this->name = nombre;
    this->observer = observerNew(this, (void (*)(void *, int, void *))Notify);
    return this;
}
CompEvent getEvent(Computador *this)
{
    return this->event;
}
