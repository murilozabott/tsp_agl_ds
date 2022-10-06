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