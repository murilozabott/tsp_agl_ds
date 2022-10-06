/* TO DO
	TAD	separar essas funções de permutação e teste
	Estrutura de dados - Lista pra checar adjacencia > matriz
*/

#include <stdio.h>
#include <stdlib.h>

int melhor_distancia = 4000000;
int melhor_caminho[12];

void testar_caminho(int **m, int *a, int n, int origem){
	int res = 0;

	if(m[origem][a[0]] == 0) return; // Não tem caminho entre a origem e o primeiro elemento da permutação
	res += m[origem][a[0]];

	for(int i = 1; i < n; i++){
		if(m[a[i]][a[i-1]] == 0) return;
		res += m[a[i]][a[i-1]];
	}

	if(m[origem][a[n-1]] == 0) return; // Não tem caminho entre a ultima posição da permutação e a origem
	res += m[origem][a[n-1]];

	if(res < melhor_distancia){
		melhor_distancia = res;
		for(int i = 0; i < n; i++){
			melhor_caminho[i] = a[i] + 1;
		}
	}
}

void permutar(int **m, int n, int origem){
	// Implementação do algoritmo 'quickperm'
	int a[n], p[n+1], i, j, k;

	for(i = 0, k = 0; i < n; i++, k++){
		p[i] = i;
		
		if(k == origem) ++k; // Pula a cidade de origem, ela não precisa permutar
		a[i] = k;
	}
	p[n] = n;

	i = 1;
	while(i < n){
		p[i]--;

		if(i&1) j = p[i];
		else j = 0;

		int temp = a[j];
		a[j] = a[i];
		a[i] = temp;

		testar_caminho(m, a, n, origem);

		i = 1;
		while(p[i] == 0){
			p[i] = i;
			i++;
		}
	}
}

int **criar_matriz(int n){
    int **matriz = (int **) calloc(n, sizeof(int *));
	
	for(int i = 0; i < n; i++)
		matriz[i] = (int *) calloc(n, sizeof(int));
    
    return matriz;
}

int main(){
	int n_cidades, origem;
	scanf("%d %d", &n_cidades, &origem);
    int **adj = criar_matriz(n_cidades);

	// Leitura das linhas
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF){
		scanf("%d", &adj[x-1][y-1]);
		// Usando uma matriz de adjacências e um grafo não direcionado, preenchemos a "ida e a volta" com a mesma distância
		adj[y-1][x-1] = adj[x-1][y-1];
	}

	permutar(adj, n_cidades-1, origem-1);

	for(int i = 0; i < n_cidades; i++){
		free(adj[i]);
	}
	free(adj);

	printf("%d ", origem);
	
	// Como o caminho funciona nos 2 sentidos, segue o padrão das saidas no runcodes que é a primeira cidade depois da origem ser a de menor número
	if(melhor_caminho[0] > melhor_caminho[n_cidades-2])
		for(int i = n_cidades-2; i >= 0; i--)
			printf("%d ", melhor_caminho[i]);
	else
		for(int i = 0; i < n_cidades-1; i++)
			printf("%d ", melhor_caminho[i]);
	
	printf("%d", origem);

	return 0;
}