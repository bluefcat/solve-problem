#include <cstdio>

constexpr int N = 1001;

int main(){
	int g[N] = { 0, 0, 1, };
	for(int i = 3; i < N; i ++){
		bool flag[N] = { false, };
		for(int j = 0; j < i-2; j ++){
			flag[g[j]^g[i-2-j]] = true;
		}

		for(int j = 0; j < N; j ++)
			if(flag[j] == false){
				g[i] = j;
				break;
			}
	}
	
	int n;
	scanf("%d", &n);
	if(g[n]){
		printf("1\n");
		return 0;
	} 

	printf("2\n");
	return 0;
}
