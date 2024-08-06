#include <cstdio>

int main(){
	int n;
	int result = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x;
		scanf("%d", &x);
		result ^= x;
	}
	if(result){
		printf("koosaga\n");
		return 0;
	}
	printf("cubelover\n");
	return 0;
}
