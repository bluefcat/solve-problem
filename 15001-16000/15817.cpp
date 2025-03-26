#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using lint = long long;
using std::vector;
using std::pair;

constexpr int N = 101;
constexpr int X = 10001;

vector<pair<lint, lint>> v{};
lint cache[N][X] = { 0, };

int main(){
	cache[0][0] = 1;
	lint n, x;
	scanf("%lld %lld", &n, &x);
	for(int i = 0; i < n; i ++){
		lint li, ci;
		scanf("%lld %lld", &li, &ci);
		v.push_back({li, ci});
	}

	std::sort(v.begin(), v.end());
	
	for(int i = 1; i <= n; i ++){
		auto& [li, ci] = v[i-1];	
		for(lint l = li; l <= x; l ++){
			for(int c = 1; c <= ci; c ++){
				if(li*c > l) continue;
				//if(cache[i-1][l-li] == 0) continue;
				cache[i][l] = cache[i-1][l-li] * ci;
				cache[i][l] += cache[i][l-li] * (ci -(c-1))/(c);
			}
		}
	}

	for(int i = 0; i <= n; i ++){
		for(int j = 0; j <= x; j ++)
			printf("%2lld ", cache[i][j]);
		printf("\n");
	}

	printf("%lld\n", cache[n][x]);
	return 0;
}
