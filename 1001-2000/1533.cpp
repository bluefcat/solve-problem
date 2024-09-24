#include <cstdio>

using lint = long long;
constexpr int N = 55;
constexpr int M = 1000003;

void product(lint x[][N], lint y[][N]){
	lint result[N][N] = { 0, };
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < N; j ++){
			for(int k = 0; k < N; k ++){
				result[i][j] = (result[i][j] + (x[i][k] * y[k][j]) % M) % M;
			}
		}
	}

	for(int i = 0; i < N; i ++)
		for(int j = 0; j < N; j ++)
			x[i][j] = result[i][j];
	return;
}

void mpow(lint x[][N], int e){
	lint result[N][N] = { 0, };
	for(int i = 0; i < N; i ++) result[i][i] = 1;

	while(e){
		if(e & 1) product(result, x);
		product(x, x);
		e >>= 1;
	}
	for(int i = 0; i < N; i ++)
		for(int j = 0; j < N; j ++) 
			x[i][j] = result[i][j];
	return;
}


int main(){
	int n, s, e, t;
	scanf("%d %d %d %d", &n, &s, &e, &t);
	lint x[N][N] = { 0, };
	lint result = 0;
	
	for(int i = 0; i < 5*n; i +=5){
		for(int j = 0; j < 5*n; j +=5){
			int q;
			scanf("%1d", &q);
			for(int k = 0; k < q-1; k ++)
				x[i+k][i+k+1] = 1;
			if(q != 0)x[i+q-1][j] = 1;
		}
	}
	
	mpow(x, t);

	printf("%lld\n", x[(s-1)*5][(e-1)*5]);

	return 0;
}
