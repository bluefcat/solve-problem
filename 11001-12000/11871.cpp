#include <cstdio>

using ull = unsigned long long;

int main(){
	int n;
	scanf("%d", &n);

	ull tmp = 0;
	for(int i = 0; i < n; i ++){
		ull x = 0;
		scanf("%lld", &x);
		if(x & 1)
			tmp ^= ((x + 1) >> 1);
		else
			tmp ^= (x >> 1)-1;
	}

	if(tmp){
		printf("koosaga\n");
		return 0;
	}
	printf("cubelover\n");
	return 0;
}
