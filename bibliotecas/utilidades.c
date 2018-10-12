//
// Created by gabri on 11/10/2018.
//

#include <string.h>
#include <ctype.h>
#include "utilidades.h"

int is_empty(char str[]){
    int tam=0;
    int cont=0;
    tam=strlen(str);
    for(int i=0;i<tam;i++){
        if(isspace(str[i])){
            cont++;
        }
    }
    if(cont==tam){
        return 1;
    }else{
        return 0;
    }

}