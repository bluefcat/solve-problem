#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y){
	int* xa = (int*)x;
	int* ya = (int*)y;
	if(xa[1] == xa[1]) return xa[0] > ya[1];	
	return xa[1] > ya[1];
}

int main(){
	int table[100001][2];
	int n, result = 0;
	int end_time = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		scanf("%d %d", table[i]+0, table[i]+1);
	}

	qsort(table, n, sizeof(int)*2, compare);

	for(int i = 0; i < n; i ++){
		if(end_time > table[i][0]) continue;
		result ++;
		end_time = table[i][1];
	}
	printf("%d\n", result);

	return 0;
}
