#include <stdio.h>

int network[101][101];
int visited[101];

void check(int* result, int n, int s){
	visited[s] = 1;
	(*result) ++;
	for(int i = 0; i <= n; i ++){
		if((visited[i] == 0) && (network[s][i] == 1)) check(result, n, i);
	}
	return;
}

int main(){
	int result = 0, N = 0, M = 0;
	scanf("%d", &N);
	scanf("%d", &M);

	for(int i = 0; i < M; i ++){
		int p = 0, q = 0;
		scanf("%d %d", &p ,&q);
		network[p][q] = 1;
		network[q][p] = 1;
	}

	check(&result, N, 1);
	
	printf("%d\n", result - 1);
	return 0;
}
