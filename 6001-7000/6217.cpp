#include <cstdio>
#include <unordered_set>
//#include <utility>

constexpr int N  =10'000+2;
int dif[2][N] = { 0, };
std::unordered_set<int> s{};

int main(){
	int n, idx, h, r;
	scanf("%d %d %d %d", &n, &idx, &h, &r);
	for(int i = 0; i < r; i ++){
		int a, b;
		scanf("%d %d", &a, &b);
		int k = (a > b)?(a * N + b) :(b * N + a);
		if(s.count(k) != 0) continue;

		if(a < b){
			a ++; dif[0][a] --; dif[0][b] ++;
		}
		if(a > b){ 
			a --; dif[1][b] ++; dif[1][a] --;
		}
		s.insert(k);
	}

	for(int i = 0; i < n; i ++) dif[0][i+1] += dif[0][i];
	for(int i = n+1; i > 0; i --) dif[1][i-1] += dif[1][i];
	
	for(int i = 1; i < n+1; i ++) printf("%d\n", h + dif[0][i] + dif[1][i]);


	return 0;
}
