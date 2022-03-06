#include <stdio.h>
#include "../ejemplo/computador.h"
#include "../ejemplo/impresora.h"
#include "../codigo/observable.h"
#include "../codigo/observer.h"

int main(int argc, char **argv)
{

    Impresora *Impr = Impresora_create("Impr");
    Computador *Comput = Com_create("Com");

    Comput->imprimir(Comput, Impr);
   
    Impr->destroy(Impr);
    Comput->destroy(Comput);
}