#include <stdio.h>

void combination(int a[], int v[], int x, int n, int m){
	if(x == m){
		for(int i = 0; i < m; i ++) printf("%d ", a[i]);
		printf("\n");
		return;
	}

	for(int i = 0; i < n; i ++){
		if(v[i]) continue;
		if(x > 0 && a[x-1] > i+1) continue;
		a[x] = i+1;
		v[i] = 1;
		combination(a, v, x+1, n, m);
		v[i] = 0;
	}
	return ;
}

int main(){
	int a[9] = { 0, };
	int v[9] = { 0, };
	int n, m;

	scanf("%d %d", &n, &m);

	combination(a, v, 0, n, m);

	return 0;
}
