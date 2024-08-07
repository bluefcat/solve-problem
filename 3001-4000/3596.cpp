#include <cstdio>
#include <algorithm>

constexpr int N = 2001;

int main(){
	int g[N] = { 0, 1, 1, 1, 2, };
	for(int i = 5; i < N; i ++){
		int check[N] = { 0, };
		for(int j = 0; j < i-2; j ++)
			check[g[std::max(0, j-3+1)]^g[i-j-3]] = true;

		for(int v = 0; v < N; v ++){
			if(check[v] == false){
				g[i] = v;
				break;
			}
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
