#include <bits/stdc++.h>

int melhor_distancia = 4000000;
int melhor_caminho[12];

void testar_caminho(int **m, int *a, int n){
	int res = 0;
	int prev = a[0]-1;
	for(int i = 1; i < n; i++){
		res += m[prev][a[i]-1];
		prev = a[i]-1;
	}
	res += m[prev][a[0]-1];


	if(res < melhor_distancia){
		melhor_distancia = res;
		for(int i = 0; i < n; i++){
			melhor_caminho[i] = a[i];
		}
	}
}

void permutar(int **m, int n){
	int a[n], p[n+1], i, j;

	for(i = 0; i < n; i++){
		a[i] = i+1;
		p[i] = i;
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

		testar_caminho(m, a, n);

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
	int n, origem;
	scanf("%d %d", &n, &origem);
    int **adj = criar_matriz(n);

	// Leitura das linhas
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF){
		scanf("%d", &adj[x-1][y-1]);
		// Usando uma matriz de adjacências e um grafo não direcionado, preenchemos a "ida e a volta" com a mesma distância
		adj[y-1][x-1] = adj[x-1][y-1];
	}

	permutar(adj, n);

	for(int i = 0; i < n; i++){
		free(adj[i]);
	}
	free(adj);

	printf("%d\n", melhor_distancia);
	for(int i = 0; i < n; i++){
		printf("%d ", melhor_caminho[i]);
	}
	
	return 0;
}