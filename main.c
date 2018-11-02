#include <stdio.h>
#include <stdlib.h>
#include "modelo/cliente.h"
#include "controller/cliente_controller.h"
#include "persistencia/cadastro_txt/clientes_txt.h"
#include "modelo/variaveis.h"
#include <string.h>
#include "bibliotecas/validator.h"
#include "bibliotecas/conio.h"
#include <locale.h>
#include <unistd.h>


int main (){
    int x=10,y=5,option;
    char a[]="gabrielws31@gmail.com";
//    mostra_clientes(0,0);
//    is_valid_email(a);


    setlocale(LC_ALL,"Portuguese");

    do{
        textcolor(WHITE);
        switch (option){
            case 1:
                le_dados(x,y,le_qtd_clientes_txt());
                break;
            case 2:
                remove_cliente(x,y);
                break;
            case 4:
                mostra_clientes(x,y);
                break;
            case 0:
                break;
        }
        gotoxy(x,y);
        printf("1-Cadastrar Cliente");
        y++;
        gotoxy(x,y);
        printf("2-Remover Cliente");
        y++;
        gotoxy(x,y);
        printf("4-Mostrar Clientes");
        y++;
        gotoxy(x,y);
        printf("0-Sair");
        y++;
        gotoxy(x,y);
        printf("Digite o que deseja fazer:");
        y++;
        gotoxy(x,y);
        scanf("%d%*c",&option);
        system("cls");
    }while(option!=0);
//    libera_memoria();
    system("pause");

    return 0;
}