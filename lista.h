#pragma once

#include <stdbool.h>

typedef struct _lista LISTA;

LISTA* criar_lista();
void liberar_lista(LISTA* l);
void inserir(LISTA* l, int c, int dist);
int get_distancia(LISTA* l, int c);