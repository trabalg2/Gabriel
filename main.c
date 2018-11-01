#include <stdio.h>
#include <stdlib.h>
#include "modelo/cliente.h"
#include "controller/cliente_controller.h"
#include "persistencia/cadastro_txt/clientes_txt.h"
#include "modelo/variaveis.h"
#include <string.h>
#include "bibliotecas/validator.h"
#include <locale.h>
#include <unistd.h>


int main (){
    int x=0,y=0;
    char a[]="gabrielws31@gmail.com";
//    mostra_clientes(0,0);
//    is_valid_email(a);


    setlocale(LC_ALL,"Portuguese");
//    le_dados(le_qtd_clientes_txt());
    mostra_clientes(0,0);
//    libera_memoria();
    system("pause");

    return 0;
}