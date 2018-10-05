#include <stdio.h>
#include <stdlib.h>
#include "modelo/cliente.h"
#include "persistencia/clientes_txt.h"

int main (){
    int x;
    int option=0;
    cliente *c;
    c=(cliente*)malloc(sizeof(cliente)*1);
    cad_cliente_txt(c);

    return 0;
}
