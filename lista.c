#include <stdlib.h>
#include <assert.h>
#include "lista.h"

typedef struct _no NO;

struct _no {
	int cidade;
	int distancia;
	NO* prox;
};

struct _lista {
	NO* ini;
	NO* fim;
};

LISTA* criar_lista() {
	LISTA* l = (LISTA*) malloc(sizeof(LISTA));
	assert(l != NULL);
	l->ini = NULL;
	l->fim = NULL;
	return l;
}

void liberar_lista(LISTA* l){
	assert(l != NULL);
	NO *n;

	n = l->ini;
	while(n != NULL) {
		l->ini = l->ini->prox;
		free(n);
		n = l->ini;
	}
	l->fim = NULL;
	
	free(l);
}

void inserir(LISTA* l, int c, int dist){
	assert(l != NULL);

	NO* n = (NO*) malloc(sizeof(NO));
	assert(n != NULL);

	n->cidade = c;
	n->distancia = dist;
	n->prox = NULL;

	if(l->ini == NULL)
		l->ini = n;
	else
		l->fim->prox = n;

	l->fim = n;
}

int get_distancia(LISTA* l, int c){
	assert(l != NULL);
	
	NO* n = l->ini;

	while(n != NULL){
		if(n->cidade == c) return n->distancia;
		n = n->prox;
	}

	return 0; // Assumindo que se existe caminho entre cidades distintas, sua distância não é 0
}