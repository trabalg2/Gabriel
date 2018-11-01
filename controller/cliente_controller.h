//
// Created by gabri on 25/10/2018.
//

#ifndef TRABALHO_ALG2_CLIENTE_CONTROLLER_H
#define TRABALHO_ALG2_CLIENTE_CONTROLLER_H

#include "../modelo/cliente.h"

void le_dados(int qtd);
void salva_cliente(cliente *cli,int qtd);
void libera_memoria();
void mostra_clientes(int x,int y);
void remove_cliente();

#endif //TRABALHO_ALG2_CLIENTE_CONTROLLER_H
