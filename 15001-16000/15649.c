#include <stdio.h>
#include <stdlib.h>

void permutation(int arr[], int vis[], int x, int n, int m){
	if(x == m){
		for(int i = 0; i < m; i ++) printf("%d ", arr[i]);
		printf("\n");
		return ;
	}

	for(int i = 0; i < n; i ++){
		if(vis[i]) continue;
		vis[i] = 1;
		arr[x] = i+1;
		permutation(arr, vis, x+1, n, m);
		vis[i] = 0;
	}

	return ;
}

int main(){
	int n, m;
	int arr[9] = { 0, };
	int vis[9] = { 0, };
	
	scanf("%d %d", &n, &m);
	
	permutation(arr, vis, 0, n, m);

	return 0;
}
