#include <stdio.h>
#include <stdlib.h>
#include "modelo/cliente.h"
#include "controller/cliente_controller.h"
#include "persistencia/cadastro_txt/clientes_txt.h"
#include "modelo/variaveis.h"
#include "bibliotecas/utilidades.h"
#include <string.h>
#include <locale.h>
#include <unistd.h>


int main (){

    setlocale(LC_ALL,"Portuguese");
//    le_dados(le_qtd_clientes_txt());
    mostra_clientes();
    libera_memoria();
    system("pause");

    return 0;
}