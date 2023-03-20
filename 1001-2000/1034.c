#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
#define MAXN 51

char table[MAXN][MAXN];

int count(int n, int m){
	int result = 0;
	for(int i = 0; i < n; i ++){
		int flag = 1;
		for(int j = 0; j < m; j ++){
			if(table[i][j] == '0'){
				flag = 0;
			}
		}

		if(flag == 1) result ++;
	}

	return result;
}

int switch_lamp(int c, int n){
	for(int i = 0; i < n; i ++){
		if(table[i][c] == '0') table[i][c] = '1';
		else table[i][c] = '0';
	}
}

void solve(int n, int m, int s, int k, int* result){
	if((s >= m && k % 2 == 0) || k == 0){
		*result = MAX(*result, count(n, m));
		return;
	}

	else if(s >= m){
		for(int i = 0; i < m; i ++){
			switch_lamp(i, n);
			solve(n, m, s, k-1, result);
			switch_lamp(i, n);
		}
	}

	for(int i = s; i < m; i ++){
		switch_lamp(i, n);
		solve(n, m, s+1, k-1, result);
		switch_lamp(i, n);
	}
	return;
}

int main(){
	int result = 0;
	int n, m, k;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++) scanf("%s", table[i]);  
	scanf("%d", &k);

	solve(n, m, 0, k, &result);

	printf("%d\n", result);

	return 0;
}
