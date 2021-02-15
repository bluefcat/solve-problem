#include <stdio.h>

void permutation(int a[], int x, int n, int m){
	if(x == m){
		for(int i = 0; i < m; i ++) printf("%d ", a[i]);
		printf("\n");
		return;
	}

	for(int i = 0; i < n; i ++){
		if(x > 0 && a[x-1] > i+1) continue;
		a[x] = i+1;
		permutation(a, x+1, n, m);
	}
	return ;
}

int main(){
	int a[9] = { 0, };
	int n, m;

	scanf("%d %d", &n, &m);

	permutation(a, 0, n, m);

	return 0;
}
