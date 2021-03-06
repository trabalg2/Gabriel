//
// Created by gabri on 05/10/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../../modelo/cliente.h"
#include "../../modelo/ponteiros.h"
#include "../../modelo/variaveis.h"
#include <string.h>
#include "../../controller/cliente_controller.h"
#include "../../bibliotecas/conio.h"

int le_qtd_clientes_txt(){
    int qtd=0;

    struct stat st;

    qtd_cad_txt=fopen("../arquivos/txt/qtd_clientes.txt","r");

    if(qtd_cad_txt!=NULL){

        //pega as informações do  arquivo
        stat("../arquivos/txt/qtd_clientes.txt", &st);
        if(st.st_size==0)
        {
            qtd_clientes_txt=0;
            qtd=0;
            return qtd;
        }
        else
        {
            fscanf(qtd_cad_txt,"%d",&qtd_clientes_txt);
            qtd=qtd_clientes_txt;
            fclose(qtd_cad_txt);
            return qtd;
        }
    }else{
        qtd_clientes_txt=0;
        return qtd;
    }
}




int altera_qtd_clientes_txt(int quantidade){
    le_qtd_clientes_txt();
    qtd_clientes_txt+=quantidade;
    qtd_cad_txt=fopen("../arquivos/txt/qtd_clientes.txt","w");
    if(qtd_cad_txt!=NULL){
        fprintf(qtd_cad_txt,"%d",qtd_clientes_txt);
        fclose(qtd_cad_txt);
        return 1;
    }else{
        return 0;
    }
}

int le_cliente_txt(int x, int y){
    cliente cliente_lido;
    int cont=0;
    char *token;
    char str[500]="";
    int dados=0;

    le_qtd_clientes_txt();

    txt=fopen("../arquivos/txt/clientes.txt","r");

    if(txt!=NULL){
        while (fgets(str, sizeof(str),txt)!=NULL) {
            token=strtok(str, ";");
            while (token!=NULL){
                if (dados == 0) {
                    cliente_lido.codigo = atoi(token);
                } else if (dados == 1) {
                    strcpy(cliente_lido.nome, token);
                } else if (dados == 2) {
                    strcpy(cliente_lido.endereco, token);
                } else if (dados == 3) {
                    strcpy(cliente_lido.cpf, token);
                } else if (dados == 4) {
                    strcpy(cliente_lido.tel, token);
                } else if (dados == 5) {
                    strcpy(cliente_lido.email, token);
                } else if (dados == 6) {
                    strcpy(cliente_lido.sexo,token);
                } else if (dados == 7) {
                    strcpy(cliente_lido.estadocivil, token);
                } else if (dados == 8) {
                    strcpy(cliente_lido.datanasc, token);
                }
                dados++;
//                printf("%s\n",token);
                token=strtok(NULL,";");
            }
            //lendo do txt passar 1
            salva_cliente(x,y,&cliente_lido,cont);
            cont++;
            dados = 0;
        }
        fclose(txt);
        return 1;
    }else{
        return 0;
    }
}



int le_ultimo_cliente_txt(){
    int qtd=0;

    struct stat st;

    qtd_cad_txt=fopen("../arquivos/txt/ultimo_cliente.txt","r");

    if(qtd_cad_txt!=NULL){

        //pega as informações do  arquivo
        stat("../arquivos/txt/ultimo_cliente.txt", &st);
        if(st.st_size==0)
        {
            qtd=0;
            return qtd;
        }
        else
        {
            fscanf(qtd_cad_txt,"%d",&qtd);
            fclose(qtd_cad_txt);
            return qtd;
        }
    }else{
        qtd=0;
        return qtd;
    }

};

int salva_ultimo_cliente_txt(int ultimo){
    ptr_ultimo_cliente_txt=fopen("../arquivos/txt/ultimo_cliente.txt","w");
    if(ptr_ultimo_cliente_txt!=NULL){
        fprintf(ptr_ultimo_cliente_txt,"%d",ultimo);
        fclose(ptr_ultimo_cliente_txt);
        return 1;
    }else{
        return 0;
    }

};

int grava_cliente_txt(cliente *all,int qtd){

    txt=fopen("../arquivos/txt/clientes.txt","w");
    if (txt==NULL) {
        return 0;
    } else {
        for (int i = 0; i <qtd ; i++) {
            if((all+i)->codigo!=0)
            {
               fprintf(txt,"%d;",(all+i)->codigo);
               fprintf(txt,"%s;",(all+i)->nome);
               fprintf(txt,"%s;",(all+i)->endereco);
               fprintf(txt,"%s;",(all+i)->cpf );
               fprintf(txt,"%s;",(all+i)->tel );
               fprintf(txt,"%s;",(all+i)->email );
               fprintf(txt,"%s;",(all+i)->sexo );
               fprintf(txt,"%s;",(all+i)->estadocivil );
               fprintf(txt,"%s;\n",(all+i)->datanasc );

            }
        }
        if(qtd<le_qtd_clientes_txt()){
            altera_qtd_clientes_txt(-1);
        }else{
            altera_qtd_clientes_txt(+1);
        }
        fclose(txt);
        return 1;
    }
}




