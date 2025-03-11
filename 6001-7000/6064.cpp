#include <cstdio>
#include <utility>

using std::swap;
using std::pair;

pair<int, int> eea(int x, int y){
	int s[2] = { 1, 0 };
	int t[2] = { 0, 1 };
	while(y > 0){
		int q = x / y;
		int r = x % y;
		int ns = s[0] - q*s[1];
		int nt = t[0] - q*t[1];
		x = y; y = r;
		s[0] = s[1], s[1] = ns;
		t[0] = t[1], t[1] = nt;
	}
	return {s[0], t[0]};
}

int main(){
	int t;
	int M, N, x, y;
	scanf("%d", &t);
	while(t-->0){
		scanf("%d %d %d %d", &M, &N, &x, &y);
		if(y < x){
			swap(M, N);
			swap(x, y);
		}
		auto [a, b] = eea(M, N);
		int g = a*M+b*N;
		int l = N*M/g;
		for(int i = 0; i <= l/N+1; i ++){
			for(int j = 0; j <= l/M+1; j ++){
				if(i*M+(x-1) == j*N+(y-1)){
					printf("%d\n", i*M+(x-1)+1);
					goto END;
				}
			}
		}
		printf("-1\n");
END:
		continue;

	}
	return 0;
}
