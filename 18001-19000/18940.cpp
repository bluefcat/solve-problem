#include <cstdio>
#include <algorithm>

constexpr int N = 1001; //5000001;
int g[N] = { 0, 1, 1, }; 

int main(){
	for(int i = 3; i < N; i ++){
		bool check[100] = { false, };
		for(int j = 0; j < i-1; j ++){
			check[g[std::max(0, j-1)]^g[i-1-(j+1)]] = true;
		}
		int v = 0;
		while(true){
			if(check[v] == false){
				g[i] = v;
				break;
			}
			v ++;
		}
	}
	
	int result = 0;
	for(int i = 0; i < 100; i ++){
		if(i % 10 == 9) printf("\n");
		printf("g(%2d) = %2d, ", i, g[i]);
	}
	printf("%d\n", result);


	return 0;
}
