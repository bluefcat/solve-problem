#include <cstdio>
#include <algorithm>
#include <utility>

constexpr int N = 100002;
constexpr int tran(int x){ return x*100; }
constexpr int V = 440;

int main(){
	int x[2];
	int t[2][N];
	
	scanf("%d %d", x, x+1);
	for(int i = 0; i < 2; i ++){
		x[i] = tran(x[i]);
		int n;
		scanf("%d", &n);
		for(int j = 0; j < n; j ++)
			scanf("%d", t[i]+j);
	}

	if(x[0] > x[1]){
		std::swap(x[0], x[1]);
		std::swap(t[0], t[1]);
	}
	x[0] += V;
	
	int q0 = 0, q1 = 0;
	int q = 0;
	for(;t[0][q0] != 0 || t[1][q1] != 0; q ++){
		if(q0 & 1) x[0] += tran(1);
		if(q1 & 1) x[1] += tran(1);

		if(t[0][q0] == q) q0 ++;
		if(t[1][q1] == q) q1 ++;
		if(x[0] >= x[1]){
			printf("bumper tab at time %d\n", q);
			return 0;
		}
	}

	if((q0&1) && ((q1&1) == 0)){
		printf("bumper tab at time %d\n", (x[1]-x[0])/100 + q);
		return 0;
	}


	printf("safe and sound\n");
	return 0;
}
