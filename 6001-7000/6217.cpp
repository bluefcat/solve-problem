#include <cstdio>
#include <utility>

constexpr int N  =10'000+1;
int dif[N] = { 0, };

int main(){
	int n, idx, h, r;
	scanf("%d %d %d %d", &n, &idx, &h, &r);
	for(int i = 0; i < r; i ++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a > b) std::swap(a, b);
		a ++;
		dif[a] --;
		dif[b] ++;
	}

	for(int i = 0; i < n; i ++) dif[i+1] += dif[i];
	
	for(int i = 1; i < n+1; i ++)
		printf("%d\n", h + dif[i]);


	return 0;
}
