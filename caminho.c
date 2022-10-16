#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "caminho.h"
#include "lista.h"

int *encontrar_caminho(LISTA** l, int n_cidades, int origem){
	int *m_caminho = (int*) malloc((n_cidades+1) * sizeof(int)); // Retorno da função
	assert(m_caminho != NULL);
	ll m_dist = LONG_MAX;

	int atual[n_cidades+1]; // Algoritmo de permutação precisa de acesso direto aos itens por um índice
	for(int i = 1, k = 1; i < n_cidades; i++, k++){
		if(k == origem) // Preencher um caminho inicial genérico, pulando a cidade de origem (fixa nas pontas)
			k++;
		atual[i] = k;
	}
	atual[0] = atual[n_cidades] = origem;

	permutar_caminho(l, atual, n_cidades-1, n_cidades+1, m_caminho, &m_dist);

	return m_caminho;
}

void permutar_caminho(LISTA **l, int *atual, int n, int tam_vet, int *m_caminho, ll *m_dist){
	// Implementação do algoritmo de Heap
	// Forma de gerar permutações de um array com o mínimo de trocas em cada chamada
	if(n == 1){
		// Os caminhos funcionam nos dois sentidos (1 2 3 4 5 1 := 1 5 4 3 2 1)
		// Então não testando caminhos com a segunda cidade maior que a penúltima evitamos essas inversões
		if(atual[1] < atual[tam_vet-2])
			testar_caminho(l, atual, tam_vet, m_caminho, m_dist);
		return;
	}

	permutar_caminho(l, atual, n-1, tam_vet, m_caminho, m_dist);

	int j;
	for(int i = 1; i < n; i++){
		if(n&1) j = 1;
		else j = i;

		int temp = atual[n];
		atual[n] = atual[j];
		atual[j] = temp;

		permutar_caminho(l, atual, n-1, tam_vet, m_caminho, m_dist);
	}
}

void testar_caminho(LISTA **l, int *atual, int n, int *m_caminho, ll *m_dist){
	int aux, res = 0;

	for(int i = 1; i < n; i++){
		if(existe_conexao(l[atual[i]], atual[i-1], &aux))
			res += aux;
		else
			return;
		if(res >= *m_dist) return;
	}

	*m_dist = res;
	for(int i = 0; i < n; i++){
		m_caminho[i] = atual[i];
	}
}

void imprimir_caminho(int *caminho, int tam){
	for(int i = 0; i < tam; i++)
		printf("%d ", caminho[i]);
	printf("\n");
}