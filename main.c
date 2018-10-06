#include <stdio.h>
#include <stdlib.h>
#include "modelo/cliente.h"
#include "persistencia/cadastro_txt/clientes_txt.h"
#include "modelo/variaveis.h"

int main (){

    scanf("%d",&c->codigo);
    fflush(stdin);
    gets(c->nome);
    fflush(stdin);
    gets(c->endereco);
    fflush(stdin);
    gets(c->cpf );
    fflush(stdin);
    gets(c->tel );
    fflush(stdin);
    gets(c->email );
    fflush(stdin);
    scanf("%c",&c->sexo );
    fflush(stdin);
    gets(c->estadocivil);
    fflush(stdin);
    gets(c->datanasc);
    fflush(stdin);
    c=(cliente*)malloc(sizeof(cliente)*1);
    cad_cliente_txt(c);

    return 0;
}
