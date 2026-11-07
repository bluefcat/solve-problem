#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y){
	return *(int*)x > *(int*)y;
}

int binary_search(int* arr, int key, int l, int r){
	int result = -1;

	while(l < r){
		int m = (l+r) >> 1;
		if(arr[m] == key){
			result = m;
			break;
		}
		else if(arr[m] < key){
			l = m+1;
		}
		else{
			r = m;
		}
	
	}
	return result;
}

int main(){
	
	int card[500001] = { 0, };
	int check[500001] = { 0, };

	int n, m;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		scanf("%d", card+i);
	}

	scanf("%d", &m);

	for(int i = 0; i < m; i ++){
		scanf("%d", check+i);
	}


	qsort(card, n, sizeof(int), compare);
	
	for(int i = 0; i < m; i ++){
		int r = binary_search(card, check[i], 0, n);
		printf("%d ", (r!=-1)?1:0);
	}

	return 0;
}
