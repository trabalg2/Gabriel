//
// Created by gabri on 05/10/2018.
//

#include <stdio.h>
#include "../../modelo/cliente.h"
#include "../../modelo/ponteiros.h"
#include "../../modelo/variaveis.h"

int pesquisa_cliente(cliente *c){

}

int le_qtd_clientes_txt(){
    qtd_cad_txt=fopen("../arquivos/txt/qtd_clientes.txt","r");
    if(qtd_cad_txt!=NULL){
        fscanf(qtd_cad_txt,"%d",&qtd_clientes_txt);
        fclose(qtd_cad_txt);
        return 1;
    }else{

    }
}

int aumenta_clientes_txt(){
    if(le_qtd_clientes_txt()){
        qtd_clientes_txt++;

        qtd_cad_txt=fopen("../arquivos/txt/qtd_clientes.txt","w");
        if(qtd_cad_txt!=NULL){
            fprintf(qtd_cad_txt,"%d",qtd_clientes_txt);
            fclose(qtd_cad_txt);
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }

}

int cad_cliente_txt(cliente *c){
    txt=fopen("../arquivos/txt/clientes.txt","a");
    if (txt==NULL) {
        return 0;
    } else {
        fprintf(txt,"%d\n%s\n%s\n%s\n%s\n%s\n%c\n%s\n%s\n\n",c->codigo,c->nome,c->endereco,c->cpf,c->tel,c->email,c->sexo,c->estadocivil,c->datanasc);
        aumenta_clientes_txt();

        fclose(txt);
        return 1;
    }
}
