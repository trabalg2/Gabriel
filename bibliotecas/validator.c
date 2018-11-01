//
// Created by gabri on 27/10/2018.
//
#include <string.h>
#include <ctype.h>
#include "conio.h"

int is_empty(char* str){
    int tam=0;
    int cont=0;
    tam=strlen(str);
    for(int i=0;i<tam;i++){
        if(isspace(str[i])){
            cont++;
        }
    }
    if(cont==tam){
        textcolor(RED);
        printf("O texto que você digitou não contém palavras!");
        textcolor(WHITE);
        return 1;
    }else{
        return 0;
    }

}

int is_valid_name(char* str){
    int tam=0;
    int cont=0;
    tam=strlen(str);
    for(int i=0;i<tam;i++){
        if(isdigit(str[i]) || ispunct(str[i]) || iscntrl(str[i])){
            cont++;
        }
    }
    if(cont>0){
        textcolor(RED);
        printf("O nome que você digitou é invalido!");
        textcolor(WHITE);
        return 0;
    }else{
        return 1;
    }

}

int is_valid_email(char* str){
    int tam=0;
    int arroba=0;
    int irregulares=0;
    int ponto=0;
    tam=strlen(str);
    for(int i=0;i<tam;i++){
        if(str[i]=='@'){
            arroba++;
        }else
        if(iscntrl(str[i]) || (ispunct(str[i]) && str[i]!='.')){
            irregulares++;
        }else
        if(str[i]=='.'){
            ponto++;
        }else if(arroba==0){

        }
    }
    if(irregulares>0 || arroba==0 || ponto<1){
        textcolor(RED);
        printf("O e-mail que você digitou é invalido!");
        textcolor(WHITE);
        return 0;
    }else{
        return 1;
    }

}