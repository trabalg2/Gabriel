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

void remove_cliente(){
    if(c==NULL){
        le_cliente_txt();
    }
    int codigo=0;

    printf("Digite o codigo do cliente que deseja remover:");
    scanf("%d%*c",&codigo);

    int qtd=le_qtd_clientes_txt();

    for (int i = 0; i <qtd ; ++i) {
        if((c+i)->codigo >= codigo && (i+2)!=qtd){
            *(c+i)=*(c+i+1);
        } else if(i+1==qtd){
            free((c+i));
        }
    }
    salva_cliente(NULL,qtd-1);
    grava_cliente_txt(c,qtd-1);
}

void mostra_clientes(int x,int y){
    if(c==NULL){
        le_cliente_txt();
    }
    system("cls");
    gotoxy(x,y);
    textcolor(BLUE);
    printf("-----------------------------------CLIENTES CADASTRADOS----------------------------------\n");
    x+=25;
    for (int i = 0; i <le_qtd_clientes_txt() ; ++i) {
        y++;
        gotoxy(x,y);
        printf("Codigo do Cliente:%d",(c+i)->codigo);
        y++;
        gotoxy(x,y);
        printf("Nome:%s",(c+i)->nome);
        y++;
        gotoxy(x,y);
        printf("Endereço:%s",(c+i)->endereco);
        y++;
        gotoxy(x,y);
        printf("CPF:%s\n",(c+i)->cpf);
        y++;
        gotoxy(x,y);
        printf("Telefone:%s",(c+i)->tel);
        y++;
        gotoxy(x,y);
        printf("E-mail:%s",(c+i)->email);
        y++;
        gotoxy(x,y);
        printf("Sexo:%s",(c+i)->sexo);
        y++;
        gotoxy(x,y);
        printf("Estado Civil:%s",(c+i)->estadocivil);
        y++;
        gotoxy(x,y);
        printf("Data de Nascimento:%s",(c+i)->datanasc);
        y++;
        x-=25;
        gotoxy(x,y);
        printf("-----------------------------------------------------------------------------------------");
        x+=25;
        gotoxy(x,y);
    }
    y++;
    gotoxy(x,y);
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

