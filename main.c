#include <stdio.h>
#include <stdlib.h>
#include "modelo/cliente.h"
#include "persistencia/cadastro_txt/clientes_txt.h"
#include "modelo/variaveis.h"
#include "bibliotecas/utilidades.h"
#include <string.h>



int main (){
//    char str[4];
//    strcpy(str,"1500");
//    printf("%d",strtoint(str));
    le_dados();
    le_cliente_txt();
    libera_memoria();
    system("pause");

    return 0;
}