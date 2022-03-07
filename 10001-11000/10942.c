#include <stdio.h>

int cache[2001][2001];


int main(){
	int num[2001] = { 0, };
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i ++) scanf("%d", num+i);
	
	//init
	for(int i = 1; i <= n; i ++){
		cache[i][i] = 1;
		if(num[i-1] == num[i]) cache[i-1][i] = 1;
	}

	for(int i = 2; i <= n; i ++){
		for(int j = 1; i + j <= n; j ++){
			if(num[j] == num[i+j] && cache[j+1][i+j-1] == 1) cache[j][i+j] = 1;
		}
	}


	int m;
	scanf("%d", &m);

	while(m--){
		int s, e;
		scanf("%d %d", &s, &e);

		printf("%d\n", cache[s][e]);

	}

	return 0;
}
