#pragma once

#include <stdbool.h>

typedef struct _lista LISTA;

LISTA* criar_lista();
void liberar_lista(LISTA* l);
void inserir(LISTA* l, int c, int dist);
bool existe_conexao(LISTA* l, int c, int *dist);