#include <stdio.h>
#define MAX 101


int main(){
	int backet[MAX] = { 0, };
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; i ++){
		int a, b, c;
		scanf("%d %d %d", &a , &b, &c);
		for(int j = a-1; j < b; j ++) backet[j] = c;
	}

	for(int i = 0; i < n; i ++){
		printf("%d ", backet[i]);
	}
	printf("\n");

	return 0;
}
