cmake_minimum_required(VERSION 3.12)
project(Trabalho_Alg2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Trabalho_Alg2 main.c persistencia/cadastro_txt/clientes_txt.h modelo/cliente.h persistencia/cadastro_txt/clientes_txt.c modelo/ponteiros.h)