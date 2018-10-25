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

void aloca_memoria(int qtd){
    le_qtd_clientes_txt();
    c=(c==NULL) ? (cliente*)malloc(sizeof(cliente)*(qtd)):
            realloc(c, sizeof(cliente)*qtd);
}

void libera_memoria(){
    free(c);
    c=NULL;
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

int le_cliente_txt(){
    int cont=0;
    char *token;
    char str[500]="";
    int dados=0;

    le_qtd_clientes_txt();

    aloca_memoria(le_qtd_clientes_txt()+1);

    txt=fopen("../arquivos/txt/clientes.txt","r");

    if(txt!=NULL){
        while (fgets(str, sizeof(str),txt)!=NULL) {
            token=strtok(str, ";");
            while (token!=NULL){
                if (dados == 0) {
                    (c+cont)->codigo = atoi(token);
                } else if (dados == 1) {
                    strcpy((c+cont)->nome, token);
                } else if (dados == 2) {
                    strcpy((c+cont)->endereco, token);
                } else if (dados == 3) {
                    strcpy((c+cont)->cpf, token);
                } else if (dados == 4) {
                    strcpy((c+cont)->tel, token);
                } else if (dados == 5) {
                    strcpy((c+cont)->email, token);
                } else if (dados == 6) {
                    strcpy((c+cont)->sexo,token);
                } else if (dados == 7) {
                    strcpy((c+cont)->estadocivil, token);
                } else if (dados == 8) {
                    strcpy((c+cont)->datanasc, token);
                }
                dados++;
                printf("%s\n",token);
                token=strtok(NULL,";");
            }
            cont++;
            dados = 0;
        }
        fclose(txt);
        return 1;
    }else{
        return 0;
    }
}

int grava_cliente_txt(cliente *cnovo,int qtd){

    txt=fopen("../arquivos/txt/clientes.txt","w");
    if (txt==NULL) {
        return 0;
    } else {
        for (int i = 0; i <qtd_clientes_txt+1 ; i++) {
            if((c+i)->codigo!=0)
            {
               fprintf(txt,"%d;",(c+i)->codigo);
               fprintf(txt,"%s;",(c+i)->nome);
               fprintf(txt,"%s;",(c+i)->endereco);
               fprintf(txt,"%s;",(c+i)->cpf );
               fprintf(txt,"%s;",(c+i)->tel );
               fprintf(txt,"%s;",(c+i)->email );
               fprintf(txt,"%s;",(c+i)->sexo );
               fprintf(txt,"%s;",(c+i)->estadocivil );
               fprintf(txt,"%s;",(c+i)->datanasc );

            }
        }
        altera_qtd_clientes_txt(qtd);
        fclose(txt);
        return 1;
    }
}

int remove_cliente_txt(){
    int cod,cont;
    cont=0;
    le_cliente_txt();
    printf("Digite o codigo do clliente que deseja Remover:\n");
    scanf("%d%*c",&cod);
    for (int i = 0; i < qtd_clientes_txt; ++i) {
        if(c[i].codigo==cod){
            c[i].codigo=0;
            cont++;
        }
    }
//    grava_cliente_txt(-1);
}



void le_dados(){

    cliente c;

    c.codigo=1;

    printf("Digite o Nome do Cliente(Ex.:João das Couves):\n");
    scanf("%[^\n]*c", c.nome);
    setbuf(stdin, NULL);

    printf("Digite o Endereço do Cliente(Ex.:Rua exemplo,111,Bairro,Cidade):\n");
    scanf("%[^\n]*c", c.endereco);
    setbuf(stdin, NULL);

    printf("Digite o cpf do Cliente (Ex.:00000000000):\n");
    scanf("%s*c", c.cpf);
    setbuf(stdin, NULL);

    printf("Digite o Telefone  do Cliente (Ex.:5537999999999):\n");
    scanf("%s*c",c.tel);
    setbuf(stdin, NULL);

    printf("Digite o email do Cliente (teste@example.com):\n");
    scanf("%s*c", c.email );
    setbuf(stdin, NULL);

    printf("Digite o Sexo do Cliente (M-Masculino/F-Feminino):\n");
    scanf("%s*c",c.sexo );
    setbuf(stdin, NULL);

    printf("Digite o estado civil do Cliente:\n");
    scanf("%s*c",c.estadocivil);
    setbuf(stdin, NULL);

    printf("Digite a Data de Nascimento do Cliente(DD/MM/AAAA):\n");
    scanf("%s*c", c.datanasc);
    setbuf(stdin, NULL);

    textcolor(BLUE);
    printf("%d\n",c.codigo);
    printf("%s\n",c.nome);
    printf("%s\n",c.endereco);
    printf("%s\n",c.cpf);
    printf("%s\n",c.tel);
    printf("%s\n",c.email);
    printf("%s\n",c.sexo);
    printf("%s\n",c.estadocivil);
    printf("%s\n",c.datanasc);
    textcolor(WHITE);


    grava_cliente_txt(&c,le_qtd_clientes_txt()+1);
}


