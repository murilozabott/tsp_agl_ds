/* TO DO
	TAD	separar essas funções de permutação e teste
	Estrutura de dados - Lista pra checar adjacencia > matriz
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int melhor_distancia = 4000000;
int melhor_caminho[13];

void testar_caminho(LISTA **l, int *caminho, int n, int origem){
	int dist, res = 0;

	for(int i = 1; i < n; i++){
		//if(caminho[i] < caminho[i-1])
		
		if(dist = get_distancia(l[caminho[i]], caminho[i-1])) res += dist;
		else return;
		
		//else
		//	if(dist = get_distancia(l[caminho[i-1]], caminho[i])) res += dist;
		//	else return;

		if(res >= melhor_distancia) return;
	}

	melhor_distancia = res;
	for(int i = 0; i < n; i++){
		melhor_caminho[i] = caminho[i];
	}
}

void imprime(int *caminho, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", caminho[i]);
	} printf("\n");
}

void permutar(LISTA** l, int n, int origem){
	/*
		Implementação do algoritmo 'quickperm' (quickperm.org)
		Forma de transformar o algoritmo recursivo de permutações de Heap numa versão iterativa
	*/
	int caminho[n+1]; // Cria um array da ordem de cidades a visitar (necessário acesso direto pro algoritmo de permutação)
	int p[n+1]; // Cria um vetor com o número de trocas p/ uma determinada posição (usado para "simular" recursão)

	for(int i = 1, k = 1; i <= n; i++, k++){
		p[i] = i-1;
		if(k == origem) k++;
		caminho[i] = k;
	}
	caminho[0] = caminho[n] = origem;

	int i = 1, j;
	while(i < n){
		p[i]--;

		if(i&1) j = 1;
		else j = p[i]+1;

		// Troca posições do caminho, gerando permutações com o minimo de trocas
		int temp = caminho[j];
		caminho[j] = caminho[i];
		caminho[i] = temp;

		testar_caminho(l, caminho, n+1, origem);

		i = 2;
		while(p[i] == 0){
			p[i] = i-1;
			i++;
		}
	}
}

int main(){
	int n_cidades, origem;
	scanf("%d %d", &n_cidades, &origem);

	LISTA* adjacencias[n_cidades+1];
	for(int i = 1; i <= n_cidades; i++)
		adjacencias[i] = criar_lista();

	int c1, c2, dist;
	while(scanf("%d %d %d", &c1, &c2, &dist) != EOF){
		inserir(adjacencias[c1], c2, dist);
		inserir(adjacencias[c2], c1, dist);
	}

	permutar(adjacencias, n_cidades, origem);

	for(int i = 1; i <= n_cidades; i++)
		liberar_lista(adjacencias[i]);

	if(melhor_caminho[1] < melhor_caminho[n_cidades-1])
		imprime(melhor_caminho, n_cidades+1);
	else
		imprime(melhor_caminho, n_cidades+1);
		//imprime_reverso(melhor_caminho, n_cidades+1);

	return 0;
}