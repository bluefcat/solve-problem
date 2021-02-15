#include <stdio.h>
#include <stdlib.h>

void permutation(int arr[], int x, int n, int m){
	if(x == m){
		for(int i = 0; i < m; i ++) printf("%d ", arr[i]);
		printf("\n");
		return ;
	}

	for(int i = 0; i < n; i ++){
		arr[x] = i+1;
		permutation(arr, x+1, n, m);
	}

	return ;
}

int main(){
	int n, m;
	int arr[9] = { 0, };
	
	scanf("%d %d", &n, &m);
	
	permutation(arr, 0, n, m);

	return 0;
}
