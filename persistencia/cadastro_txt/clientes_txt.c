//
// Created by gabri on 05/10/2018.
//

#include <stdio.h>
#include "../../modelo/cliente.h"
#include "../../modelo/ponteiros.h"

int cad_cliente_txt(cliente *c){
    txt=fopen("../../clientes.txt","a");
    if (txt==NULL) {
        return 0;
    } else {
        fprintf(txt,"%d\n%s\n%s\n%s\n%s\n%s\n%c\n%s\n%s\n\n",c->codigo,c->nome,c->endereco,c->cpf,c->tel,c->email,c->sexo,c->estadocivil,c->datanasc);
        fclose(txt);
        return 1;
    }
}