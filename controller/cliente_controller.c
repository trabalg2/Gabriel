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

void salva_cliente(int x,int y,cliente *cli,int qtd){

    c =(c==NULL) ? (cliente*)malloc(sizeof(cliente)*(qtd+1)):
      realloc(c, sizeof(cliente)*(qtd+1));

    if(cli!=NULL){
        *(c+qtd)=*cli;
        gotoxy(x+30,y);
        textcolor(GREEN);
        printf("Cliente Salvo!");
    }
}

void altera_cliente(int x,int y){
    if(c==NULL){
        le_cliente_txt(x,y);
    }
    int codigo=0;
    int qtd=le_qtd_clientes_txt();

    system("cls");
    textcolor(LIGHTRED);
    gotoxy(x,y);
    y++;
    printf("--------------------------------ALTERAR CLIENTES--------------------------------\n");
    textcolor(WHITE);

    printf("Digite o codigo do cliente que deseja alterar:");
    scanf("%d%*c",&codigo);

    for (int i = 0; i <qtd ; ++i) {
        if((c+i)->codigo >= codigo && (i+1)!=qtd){
            gotoxy(x,y);
            printf("Digite o Nome do Cliente(Ex.:João das Couves):\n");
            scanf("%[^\n]*c", (c+i)->nome);
            setbuf(stdin, NULL);

            y++;
            gotoxy(x,y);
            printf("Digite o Endereço do Cliente(Ex.:Rua exemplo,111,Bairro,Cidade):\n");
            scanf("%[^\n]*c", (c+i)->endereco);
            setbuf(stdin, NULL);

            y++;
            gotoxy(x,y);
            printf("Digite o cpf do Cliente (Ex.:00000000000):\n");
            scanf("%s*c", (c+i)->cpf);
            setbuf(stdin, NULL);

            y++;
            gotoxy(x,y);
            printf("Digite o Telefone  do Cliente (Ex.:5537999999999):\n");
            scanf("%s*c",(c+i)->tel);
            setbuf(stdin, NULL);

            y++;
            gotoxy(x,y);
            printf("Digite o email do Cliente (teste@example.com):\n");
            scanf("%s*c", (c+i)->email );
            setbuf(stdin, NULL);

            y++;
            gotoxy(x,y);
            printf("Digite o Sexo do Cliente (M-Masculino/F-Feminino):\n");
            scanf("%s*c",(c+i)->sexo );
            setbuf(stdin, NULL);

            y++;
            gotoxy(x,y);
            printf("Digite o estado civil do Cliente:\n");
            scanf("%s*c",(c+i)->estadocivil);
            setbuf(stdin, NULL);

            y++;
            gotoxy(x,y);
            printf("Digite a Data de Nascimento do Cliente(DD/MM/AAAA):\n");
            scanf("%s*c", (c+i)->datanasc);
            setbuf(stdin, NULL);
        }
    }

    gotoxy(x+30,y);
    textcolor(GREEN);
    printf("Cliente Salvo!");

    qtd-=1;
    grava_cliente_txt(c,qtd);
}

void remove_cliente(int x,int y){
    if(c==NULL){
        le_cliente_txt(x,y);
    }
    int codigo=0;
    int qtd=le_qtd_clientes_txt();

    system("cls");
    textcolor(LIGHTRED);
    gotoxy(x,y);
    y++;
    printf("--------------------------------REMOVE  CLIENTES--------------------------------");
    textcolor(WHITE);

    printf("Digite o codigo do cliente que deseja remover:");
    scanf("%d%*c",&codigo);

    for (int i = 0; i <qtd ; ++i) {
        if((c+i)->codigo >= codigo && (i+1)!=qtd){
            *(c+i)=*(c+i+1);
            textcolor(GREEN);
            gotoxy(x,y);
            printf("Cliente Removido!");
        }
    }

    qtd-=1;
    salva_cliente(x,y,NULL,qtd);
    grava_cliente_txt(c,qtd);
}

void mostra_clientes(int x,int y){
    if(c==NULL){
        le_cliente_txt(x,y);
    }
    system("cls");
    gotoxy(x,y);
    textcolor(BLUE);
    printf("------------------------------CLIENTES CADASTRADOS------------------------------\n");
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

}

void libera_memoria(){
    free(c);
    c=NULL;
}


void le_dados(int x,int y,int qtd){
    if(qtd>0){
        le_cliente_txt(x,y);
    }

    cliente n_cliente;

    n_cliente.codigo=le_ultimo_cliente_txt()+1;

    textcolor(LIGHTRED);
    y++;
    gotoxy(x,y);
    printf("-------------------------------CADASTRAR CLIENTES-------------------------------\n");
    textcolor(WHITE);
    y++;
    gotoxy(x,y);
    printf("Digite o Nome do Cliente(Ex.:João das Couves):\n");
    scanf("%[^\n]*c", n_cliente.nome);
    setbuf(stdin, NULL);

    gotoxy(x,y);
    y++;
    printf("Digite o Endereço do Cliente(Ex.:Rua exemplo,111,Bairro,Cidade):\n");
    scanf("%[^\n]*c", n_cliente.endereco);
    setbuf(stdin, NULL);

    gotoxy(x,y);
    y++;
    printf("Digite o cpf do Cliente (Ex.:00000000000):\n");
    scanf("%s*c", n_cliente.cpf);
    setbuf(stdin, NULL);

    gotoxy(x,y);
    y++;
    printf("Digite o Telefone  do Cliente (Ex.:5537999999999):\n");
    scanf("%s*c",n_cliente.tel);
    setbuf(stdin, NULL);

    gotoxy(x,y);
    y++;
    printf("Digite o email do Cliente (teste@example.com):\n");
    scanf("%s*c", n_cliente.email );
    setbuf(stdin, NULL);

    gotoxy(x,y);
    y++;
    printf("Digite o Sexo do Cliente (M-Masculino/F-Feminino):\n");
    scanf("%s*c",n_cliente.sexo );
    setbuf(stdin, NULL);

    gotoxy(x,y);
    y++;
    printf("Digite o estado civil do Cliente:\n");
    scanf("%s*c",n_cliente.estadocivil);
    setbuf(stdin, NULL);

    gotoxy(x,y);
    y++;
    printf("Digite a Data de Nascimento do Cliente(DD/MM/AAAA):\n");
    scanf("%s*c", n_cliente.datanasc);
    setbuf(stdin, NULL);

    salva_cliente(x,y,&n_cliente,qtd);
    grava_cliente_txt(c,qtd+1);
    salva_ultimo_cliente_txt(n_cliente.codigo);

}

