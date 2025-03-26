#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using pair = std::pair<int, int>;

constexpr int C = 1001;
constexpr int N = 21;

int cache[N][C] = { 0, };
vector<pair> field{};

int main(){
	int c, n;
	scanf("%d %d", &c, &n);
	for(int i = 0; i < n; i ++){
		int cost, w;
		scanf("%d %d", &cost, &w);
		field.push_back({cost, w});
	}

	std::sort(field.begin(), field.end());
	
	for(int i = 1; i <= c; i ++){
		auto& [cost, w] = field[0];	
		cache[1][i] = (i/w + (i%w != 0)) * cost;
	}

	for(int i = 2; i <= n; i ++){
		auto& [cost, w] = field[i-1];
		for(int ci = 1; ci <= c; ci ++){
			if(ci - w <= 0)
				cache[i][ci] = std::min(cache[i-1][ci], (ci/w +(ci%w != 0)) * cost);
			else
				cache[i][ci] = std::min(
					cache[i][ci-w] + cost,
					std::min(cache[i-1][ci], cache[i-1][ci-w] + cost)
				); 
		}
	}
	

	for(int i = 0; i <= n; i ++){
		for(int j = 0; j <= c; j ++){
			printf("%3d ", cache[i][j]);
		}
		printf("\n");
	}

	printf("%d\n", cache[n][c]);

	return 0;
}
