#include <stdio.h>
#define MAX 101

int main(){
	int backet[MAX] = { 0, };

	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) backet[i] = i;
	
	for(int i = 0; i < m; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		int tmp = backet[x];
		backet[x] = backet[y];
		backet[y] = tmp;
	}

	for(int i = 1; i <= n; i ++) printf("%d ", backet[i]);
	printf("\n");

	return 0;
}
