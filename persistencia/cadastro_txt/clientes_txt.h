//
// Created by gabri on 05/10/2018.
//

#ifndef TRABALHO_ALG2_CLIENTES_TXT_H
#define TRABALHO_ALG2_CLIENTES_TXT_H

#include <stdio.h>
#include "../../modelo/cliente.h"

int grava_cliente_txt(cliente *all,int qtd);
int le_qtd_clientes_txt();
int altera_qtd_clientes_txt(int quantidade);
int le_cliente_txt(int x, int y);
int salva_ultimo_cliente_txt(int ultimo);
int le_ultimo_cliente_txt();
int altera_cliente_txt();
int remove_cliente_txt();

#endif //TRABALHO_ALG2_CLIENTES_TXT_H
