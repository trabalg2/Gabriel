//
// Created by gabri on 05/10/2018.
//

#ifndef TRABALHO_ALG2_CLIENTES_TXT_H
#define TRABALHO_ALG2_CLIENTES_TXT_H

#include <stdio.h>
#include "../../modelo/cliente.h"

int grava_cliente_txt();
int le_qtd_clientes_txt();
int altera_qtd_clientes_txt(int quantidade);
int le_cliente_txt();
void libera_memoria();
void aloca_memoria(int qtd);
void le_dados();
int altera_cliente_txt();
int remove_cliente_txt();

#endif //TRABALHO_ALG2_CLIENTES_TXT_H
