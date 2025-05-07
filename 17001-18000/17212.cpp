#include <cstdio>
#include <algorithm>

constexpr int N = 100'001;

int main(){
	int cache[N] = { 0, };
	cache[1] = 1;
	cache[2] = 1;
	cache[5] = 1;
	cache[7] = 1;

	int coin[4] = { 1, 2 , 5, 7 };

	for(int i = 3; i < N; i ++){
		for(auto x: coin){
			if(i - x <= 0) continue;	
			if(cache[i] == 0) cache[i] = cache[i-x] + 1;
			cache[i] = std::min(cache[i], cache[i-x] + 1);
		}
	}

	int n;
	scanf("%d", &n);
	printf("%d\n", cache[n]);

	return 0;
}
