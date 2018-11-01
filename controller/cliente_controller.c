//
// Created by gabri on 25/10/2018.
//
#include <stdio.h>
#include "cliente_controller.h"
#include "../modelo/cliente.h"
#include "../bibliotecas/conio.h"
#include "../modelo/variaveis.h"
#include "../persistencia/cadastro_txt/clientes_txt.h"

cliente *c=NULL;

void salva_cliente(cliente *cli,int qtd){

    c =(c==NULL) ? (cliente*)malloc(sizeof(cliente)*(qtd+1)):
      realloc(c, sizeof(cliente)*(qtd+1));

    if(cli!=NULL){
        *(c+qtd)=*cli;
    }
}

void remove_cliente(int id){
    for (int i = 0; i <le_qtd_clientes_txt() ; ++i) {

    }

}

void mostra_clientes(int x,int y){
    if(c==NULL){
        le_cliente_txt();
    }
    system("clrscr");
    gotoxy(x,y);
    textcolor(BLUE);
    printf("----------------------CLIENTES CADASTRADOS---------------------\n");
    for (int i = 0; i <le_qtd_clientes_txt() ; ++i) {
        x++;
        x++;
        gotoxy(x,y);
        printf("%d\n",(c+i)->codigo);
        x++;
        gotoxy(x,y);
        printf("%s\n",(c+i)->nome);
        x++;
        gotoxy(x,y);
        printf("%s\n",(c+i)->endereco);
        x++;
        gotoxy(x,y);
        printf("%s\n",(c+i)->cpf);
        x++;
        gotoxy(x,y);
        printf("%s\n",(c+i)->tel);
        x++;
        gotoxy(x,y);
        printf("%s\n",(c+i)->email);
        x++;
        gotoxy(x,y);
        printf("%s\n",(c+i)->sexo);
        x++;
        gotoxy(x,y);
        printf("%s\n",(c+i)->estadocivil);
        x++;
        gotoxy(x,y);
        printf("%s\n",(c+i)->datanasc);
        x++;
    }
    textcolor(WHITE);

}

void libera_memoria(){
    free(c);
    c=NULL;
}

int valida_dados(cliente *c){
}

void le_dados(int qtd){
    if(qtd>0){
        le_cliente_txt();
    }

    cliente n_cliente;

    n_cliente.codigo=le_qtd_clientes_txt()+1;
    textcolor(YELLOW);
    printf("-----------------------Cadastrar Cliente-----------------------\n");
    textcolor(WHITE);

    printf("Digite o Nome do Cliente(Ex.:João das Couves):\n");
    scanf("%[^\n]*c", n_cliente.nome);
    setbuf(stdin, NULL);

    printf("Digite o Endereço do Cliente(Ex.:Rua exemplo,111,Bairro,Cidade):\n");
    scanf("%[^\n]*c", n_cliente.endereco);
    setbuf(stdin, NULL);

    printf("Digite o cpf do Cliente (Ex.:00000000000):\n");
    scanf("%s*c", n_cliente.cpf);
    setbuf(stdin, NULL);

    printf("Digite o Telefone  do Cliente (Ex.:5537999999999):\n");
    scanf("%s*c",n_cliente.tel);
    setbuf(stdin, NULL);

    printf("Digite o email do Cliente (teste@example.com):\n");
    scanf("%s*c", n_cliente.email );
    setbuf(stdin, NULL);

    printf("Digite o Sexo do Cliente (M-Masculino/F-Feminino):\n");
    scanf("%s*c",n_cliente.sexo );
    setbuf(stdin, NULL);

    printf("Digite o estado civil do Cliente:\n");
    scanf("%s*c",n_cliente.estadocivil);
    setbuf(stdin, NULL);

    printf("Digite a Data de Nascimento do Cliente(DD/MM/AAAA):\n");
    scanf("%s*c", n_cliente.datanasc);
    setbuf(stdin, NULL);

    salva_cliente(&n_cliente,qtd);
    grava_cliente_txt(c,qtd);

}

