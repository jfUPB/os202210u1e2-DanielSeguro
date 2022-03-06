#include <stdio.h>
#include "../ejemplo/computador.h"
#include "../ejemplo/impresora.h"
#include "../codigo/observable.h"
#include "../codigo/observer.h"

int main(int argc, char **argv)
{

    Impresora *Impresora = Impresora_create("Impr");
    Computador *Comput = Com_create("Com");


    Comput->registerObserver(Comput, Impresora);
    Comput->imprimir(Comput);

    Impresora->destroy(Impresora);
    Comput->destroy(Comput);
}