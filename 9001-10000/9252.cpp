#include <cstdio>
#include <cstring>
#include <cmath>

constexpr int N = 1002;

int main(){
	char x[N] = { 0, };
	char y[N] = { 0, };
	int cache[N][N] = { 0, };
	
	char lcs[N] = { 0, };
	scanf("%s", x);
	scanf("%s", y);

	int lx = strlen(x);
	int ly = strlen(y);
	
	for(int i = 0 ; i < lx; i ++){
		for(int j = 0; j < ly; j ++){
			cache[i+1][j+1] = std::max(
				cache[i+1][j], 
				cache[i][j] + (x[i] == y[j])
			);
			cache[i+1][j+1] = std::max(
				cache[i+1][j+1],
				cache[i][j+1]
			);
		}
	}
	int cur = cache[lx][ly];

	int cx = lx, cy = ly;
	while(cur != 0){
		if(1 <= cx && cur == cache[cx-1][cy]){
			cx --;
			continue;
		}

		if(1 <= cy && cur == cache[cx][cy-1]){
			cy --;
			continue;
		}
		
		lcs[cur-1] = y[cy-1];
		cy --;
		cur = cache[cx][cy];

	}


	printf("%d\n", cache[lx][ly]);
	if(cache[lx][ly] != 0){
		printf("%s\n", lcs);
	}

	return 0;
}
