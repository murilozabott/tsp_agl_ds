#include <bits/stdc++.h>

int main(){
	int n, origem;

	scanf("%d %d", &n, &origem);

	// Alocar matriz
	int **adj = (int **) calloc(n, sizeof(int *));
	for(int i = 0; i < n; i++)
		adj[i] = (int *) calloc(n, sizeof(int));

	// Leitura das linhas
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF){
		scanf("%d", &adj[x-1][y-1]);
		// Usando uma matriz de adjacências e um grafo não direcionado, preenchemos a "ida e a volta" com a mesma distância
		adj[y-1][x-1] = adj[x-1][y-1];
	}

	return 0;
}