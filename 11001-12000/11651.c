#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int** arr, int p, int q, int r){
	int lsize = q-p, rsize = r-q;

	int** larr = (int**)malloc(sizeof(int*)*(lsize+1));
	larr[0] = (int*)malloc(sizeof(int)*2*(lsize+1));
	for(int i = 1; i <= lsize; i ++) larr[i] = larr[i-1]+2;
	for(int i = 0; i < lsize; i ++){
		larr[i][0] = arr[i+p][0];
		larr[i][1] = arr[i+p][1];
	}
	larr[lsize][0] = INT_MAX;
	larr[lsize][1] = INT_MAX;

	int** rarr = (int**)malloc(sizeof(int*)*(rsize+1));
	rarr[0] = (int*)malloc(sizeof(int)*2*(rsize+1));
	for(int i = 1; i <= rsize; i ++) rarr[i] = rarr[i-1]+2;
	for(int i = 0; i < rsize; i ++){
		rarr[i][0] = arr[i+q][0];
		rarr[i][1] = arr[i+q][1];
	}
	rarr[rsize][0] = INT_MAX;
	rarr[rsize][1] = INT_MAX;

	int i = 0, j = 0;
	for(int k = p; k < r; k ++){
		if(larr[i][1] < rarr[j][1]){
			arr[k][0] = larr[i][0];
			arr[k][1] = larr[i][1];
			i ++;
		}
		else if(larr[i][1] == rarr[j][1]){
			if(larr[i][0] < rarr[j][0]){
				arr[k][0] = larr[i][0];
				arr[k][1] = larr[i][1];
				i ++;
			}	
			else {
				arr[k][0] = rarr[j][0];
				arr[k][1] = rarr[j][1];
				j ++;
			}
		}
		else{
			arr[k][0] = rarr[j][0];
			arr[k][1] = rarr[j][1];
			j ++;
		}
	}
	
	free(rarr[0]);
	free(rarr);

	free(larr[0]);
	free(larr);
	return ;
}

void merge_sort(int** arr, int p, int r){
	if(p+1 >= r) return;
	int q = (p+r)/2;
	merge_sort(arr, p, q);
	merge_sort(arr, q, r);
	merge(arr, p, q, r);
	return ;
}

int main(){
	int n;
	scanf("%d", &n);

	int** points = (int**)malloc(sizeof(int*)*n);
	points[0] = (int*)malloc(sizeof(int)*2*n);
	for(int i = 1; i < n; i ++) points[i] = points[i-1]+2;
	
	for(int i = 0; i < n; i ++){
		scanf("%d %d", points[i]+0, points[i]+1);
	}

	merge_sort(points, 0, n);

	for(int i = 0; i < n; i ++){
		printf("%d %d\n", points[i][0], points[i][1]);
	}

	free(points[0]);
	free(points);

	return 0;
}
