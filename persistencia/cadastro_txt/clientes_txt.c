//
// Created by gabri on 05/10/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../../modelo/cliente.h"
#include "../../modelo/ponteiros.h"
#include "../../modelo/variaveis.h"
#include "../../bibliotecas/utilidades.h"
#include <string.h>
#include "../../bibliotecas/conio.h"


int le_qtd_clientes_txt(){

    struct stat st;

    qtd_cad_txt=fopen("../arquivos/txt/qtd_clientes.txt","r");

    if(qtd_cad_txt!=NULL){

        //pega as informações do  arquivo
        stat("../arquivos/txt/qtd_clientes.txt", &st);
        if(st.st_size==0)
        {
            qtd_clientes_txt=0;
            return 1;
        }
        else
        {
            fscanf(qtd_cad_txt,"%d\n",&qtd_clientes_txt);
            fclose(qtd_cad_txt);
            return 1;
        }
    }else{
        return 0;
    }
}

void aloca_memoria(int qtd){
    le_qtd_clientes_txt();
    c=(cliente *)malloc(sizeof(cliente)*(qtd));
}

void libera_memoria(){
    free(c);
    c=NULL;
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

int diminui_clientes_txt(){
    if(le_qtd_clientes_txt()){
        qtd_clientes_txt--;
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

int le_cliente_txt(){
    int cont=0;
    char str[100]="";
    int dados=0;

    le_qtd_clientes_txt();

    aloca_memoria(qtd_clientes_txt+1);

    txt=fopen("../arquivos/txt/clientes.txt","r");

    if(txt!=NULL){
        while ((fgets(str, sizeof(str),txt))!=EOF && cont<qtd_clientes_txt) {
            if (dados==9) {
                dados = 0;
                cont++;
            }
            strtok(str, "\n");
            if (dados == 0) {
                c[cont].codigo = atoi(str);
            } else if (dados == 1) {
                strcpy(c[cont].nome, str);
            } else if (dados == 2) {
                strcpy(c[cont].endereco, str);
            } else if (dados == 3) {
                strcpy(c[cont].cpf, str);
            } else if (dados == 4) {
                strcpy(c[cont].tel, str);
            } else if (dados == 5) {
                strcpy(c[cont].email, str);
            } else if (dados == 6) {
                c[cont].sexo=str[0];
            } else if (dados == 7) {
                strcpy(c[cont].estadocivil, str);
            } else if (dados == 8) {
                strcpy(c[cont].datanasc, str);
            }
            dados++;
        }
        fclose(txt);
        return 1;
    }else{
        return 0;
    }
}

int grava_cliente_txt(){
    char cod[100];
    txt=fopen("../arquivos/txt/clientes.txt","w");
    if (txt==NULL) {
        return 0;
    } else {
        for (int i = 0; i <qtd_clientes_txt+1 ; ++i) {
            itoa(c[i].codigo,cod,100);
            if(!(is_empty(cod)) && !(is_empty(c[i].nome)) &&
                !(is_empty(c[i].endereco))&& !(is_empty(c[i].cpf)) &&
                !(is_empty(c[i].tel)) && !(is_empty(c[i].email)) && !(is_empty(c[i].estadocivil)) &&
                !(is_empty(c[i].datanasc)))
            {
                fputs(cod,txt);
                fprintf(txt,"\n");
                fputs(c[i].nome,txt);
                fprintf(txt,"\n");
                fputs(c[i].endereco,txt);
                fprintf(txt,"\n");
                fputs(c[i].cpf,txt);
                fprintf(txt,"\n");
                fputs(c[i].tel,txt);
                fprintf(txt,"\n");
                fputs(c[i].email,txt);
                fprintf(txt,"\n");
                fputc(c[i].sexo,txt);
                fprintf(txt,"\n");
                fputs(c[i].estadocivil,txt);
                fprintf(txt,"\n");
                fputs(c[i].datanasc,txt);
                fprintf(txt,"\n");
            }
        }
        aumenta_clientes_txt();
        fclose(txt);
        return 1;
    }
}



void le_dados(){
    le_qtd_clientes_txt();
    if(qtd_clientes_txt>0){
        le_cliente_txt();
    }else{
        aloca_memoria(1);
    }
    c[qtd_clientes_txt].codigo=qtd_clientes_txt+1;
    printf("Digite o Nome do Cliente(Ex.:João das Couves):\n");
    gets(c[qtd_clientes_txt].nome);
    fflush(stdin);
    printf("Digite o Endereço do Cliente(Ex.:Rua exemplo,111,Bairro,Cidade):\n");
    gets(c[qtd_clientes_txt].endereco);
    fflush(stdin);
    printf("Digite o cpf do Cliente (Ex.:00000000000):\n");
    gets(c[qtd_clientes_txt].cpf);
    fflush(stdin);
    printf("Digite o Telefone  do Cliente (Ex.:5537999999999):\n");
    gets(c[qtd_clientes_txt].tel);
    fflush(stdin);
    printf("Digite o email do Cliente (teste@example.com):\n");
    gets(c[qtd_clientes_txt].email );
    fflush(stdin);
    printf("Digite o Sexo do Cliente (M-Masculino/F-Feminino):\n");
    scanf("%c",&c[qtd_clientes_txt].sexo );
    fflush(stdin);
    printf("Digite o estado civil do Cliente:\n");
    gets(c[qtd_clientes_txt].estadocivil);
    fflush(stdin);
    printf("Digite a Data de Nascimento do Cliente(DD/MM/AAAA):\n");
    gets(c[qtd_clientes_txt].datanasc);
    fflush(stdin);
    grava_cliente_txt();
}


