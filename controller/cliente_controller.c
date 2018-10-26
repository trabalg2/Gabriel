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

void mostra_clientes(){

    for (int i = 0; i <le_qtd_clientes_txt() ; ++i) {
        textcolor(BLUE);
        printf("%d\n",(c+i)->codigo);
        printf("%s\n",(c+i)->nome);
        printf("%s\n",(c+i)->endereco);
        printf("%s\n",(c+i)->cpf);
        printf("%s\n",(c+i)->tel);
        printf("%s\n",(c+i)->email);
        printf("%s\n",(c+i)->sexo);
        printf("%s\n",(c+i)->estadocivil);
        printf("%s\n",(c+i)->datanasc);
    }

}

void libera_memoria(){
    free(c);
    c=NULL;
}

int valida_dados(cliente *c){
    if(c.nome)
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

