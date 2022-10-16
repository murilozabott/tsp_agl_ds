#pragma once

#include "lista.h"

typedef long long int ll;

int *encontrar_caminho(LISTA** l, int n, int origem);
void permutar_caminho(LISTA **l, int *atual, int n, int tam_vet, int *m_caminho, ll *m_dist);
void testar_caminho(LISTA **l, int *atual, int n, int *m_caminho, ll *m_dist);
void imprimir_caminho(int *caminho, int tam);