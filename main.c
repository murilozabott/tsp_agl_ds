#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "caminho.h"
#include "lista.h"

int main(){
	int n_cidades, origem;
	scanf("%d %d", &n_cidades, &origem);

	LISTA *adjacencias[n_cidades+1];
	for(int i = 1; i <= n_cidades; i++){
		adjacencias[i] = criar_lista();
		assert(adjacencias[i] != NULL);
	}

	int c1, c2, dist;
	while(scanf("%d %d %d", &c1, &c2, &dist) != EOF){
		inserir(adjacencias[c1], c2, dist);
		inserir(adjacencias[c2], c1, dist);
	}

	int *melhor_caminho = encontrar_caminho(adjacencias, n_cidades, origem);

	imprimir_caminho(melhor_caminho, n_cidades+1);

	free(melhor_caminho);
	for(int i = 1; i <= n_cidades; i++)
		liberar_lista(adjacencias[i]);

	return 0;
}