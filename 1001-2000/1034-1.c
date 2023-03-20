#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
#define MAXN 51

char table[MAXN][MAXN];

int zero_count(int c, int m){
	int result = 0;
	for(int i = 0; i < m; i ++){
		result += (int)(table[c][i] == '0');
	}
	return result;
}

int is_same(int x, int y, int m){
	for(int i = 0; i < m; i ++){
		if(table[x][i] != table[y][i]) return 0;
	}
	return 1;
}

int main(){
	int result = 0;
	int n, m, k;
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++) scanf("%s", table[i]);
	scanf("%d", &k);

	for(int i = 0; i < n; i ++){
		int x = zero_count(i, m);

		if((x > k) || ((x & 1) != (k & 1))) continue;
		
		int s = 0;
		for(int j = 0; j < n; j ++){
			s += is_same(i, j, m);
		}

		result = MAX(result, s);
	}

	printf("%d\n", result);
	return 0;
}
