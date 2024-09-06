#include <cstdio>

int main(){
	int n;
	bool one = true;
	int result = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x;
		scanf("%d", &x);
		result ^= x;
		one &= (x == 1);
	}
	if((one && (n&1)) || (!one && !result)){
		printf("cubelover\n");
		return 0;
	}
	printf("koosaga\n");
	return 0;
}
