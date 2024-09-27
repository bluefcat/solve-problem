#include <cstdio>

using lint = long long;

constexpr int N = 2001;
lint comb[N][N] = { 0, };

void build(lint p){
	for(int i = 0; i < N; i ++){
		for(int j = 0; j <= i; j ++){
			if(i == j){
				comb[i][j] = 1;
				continue;
			}
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % p;
		}
	}
}

int main(){
	lint n, k, m;
	scanf("%lld %lld %lld", &n, &k, &m);
	build(m);
	
	int result = 1;
	
	while(n | k){
		result = (result * comb[n%m][k%m])%m;	
		n /= m;
		k /= m;
	}


	printf("%d\n", result);
	return 0;
}
