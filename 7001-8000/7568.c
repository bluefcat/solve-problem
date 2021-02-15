#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int* arr[2];

	scanf("%d", &n);
	
	arr[0] = (int*)malloc(sizeof(int)*2*n);
	arr[1] = arr[0]+n;
	for(int i = 0; i < n; i ++){
		//weight, height
		scanf("%d %d", arr[0]+i, arr[1]+i);	
	}

	for(int i = 0; i < n; i ++){
		int rank = 1;
		for(int j = 0; j < n; j ++){
			if(i == j) continue;
			
			if(arr[0][i] < arr[0][j] && arr[1][i] < arr[1][j]) rank ++;

		}
		printf("%d ", rank);
	}
	printf("\n");

	free(arr[0]);
	return 0;
}
