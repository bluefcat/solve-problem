#include <cstdio>
#include <array>
#include <queue>
#include <string>
#include <algorithm>

using std::array;
using std::queue;

constexpr int N = 4;
constexpr int MOD = 10000;

int to_int(const array<int, N>& reg){
	int result = 0;
	for(auto x: reg){
		result *= 10;
		result += x;
	}
	return result;
}

array<int, N> to_array(int x){
	array<int, N> result{};
	int idx = N;
	while(x){
		result[--idx] = x % 10;
		x /= 10;
	}
	return result;
}


array<int, N> D(const array<int, N>& reg){
	int x = to_int(reg);
	return to_array((2*x)%MOD);
}


array<int, N> S(const array<int, N>& reg){
	int x = to_int(reg)-1;
	if(x < 0) x = 9999;	
	return to_array(x);
}

array<int, N> L(const array<int, N>& reg){
	array<int, N> result{};
	for(int i = 0; i < N; i ++)
		result[(i+3)%N] = reg[i];
	return result;
}

array<int, N> R(const array<int, N>& reg){
	array<int, N> result{};
	for(int i = 0; i < N; i ++)
		result[(i+1)%N] = reg[i];
	return result;
}

void print(const array<int, N>& reg){
	for(auto x: reg) printf("[%d]", x);
	printf("\n");
}

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		array<std::tuple<int, int, char>, MOD> cache{};
		int src, dest;
		scanf("%d %d", &src, &dest);

		queue<std::pair<int, int>> q{};
		q.push({src, 1});
		cache[src] = {src, 1, 0};
	
		while(!q.empty()){
			auto [x, c] = q.front(); q.pop();
			auto a = to_array(x);
			
			int d = to_int(D(a));
			int s = to_int(S(a));
			int l = to_int(L(a));
			int r = to_int(R(a));

			if(std::get<1>(cache[d]) == 0){
				q.push({d, c+1});
				cache[d] = {x, c+1, 'D'};
			}
			
			if(std::get<1>(cache[s]) == 0){
				q.push({s, c+1});
				cache[s] = {x, c+1, 'S'};
			}

			if(std::get<1>(cache[l]) == 0){
				q.push({l, c+1});
				cache[l] = {x, c+1, 'L'};
			}

			if(std::get<1>(cache[r]) == 0){
				q.push({r, c+1});
				cache[r] = {x, c+1, 'R'};
			}
		}
		std::string result{};
		auto [a, b, c] = cache[dest];
		int p = a, cnt = b; 
		char oper = c;
		while(cnt > 1){
			result += oper;
			auto [a, b, c] = cache[p];
			p = a, cnt = b, oper = c;
		}
		std::reverse(result.begin(), result.end());
		printf("%s\n", result.c_str());
	}
	return 0;
}
