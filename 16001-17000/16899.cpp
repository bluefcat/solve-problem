#include <cstdio>

using lint = long long;

int main(){
	lint result = 0;
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		lint x, m;
		scanf("%lld %lld", &x, &m);
		lint rx[4] = { x, 1, x+1, 0 }, rm[4] = { x+m-1, 1, x+m, 0 };
		result ^= rx[(x-1)%4] ^ rm[(x+m-1)%4];
	}

	if(result){
		printf("koosaga\n");
		return 0;
	}

	printf("cubelover\n");
	return 0;
}
