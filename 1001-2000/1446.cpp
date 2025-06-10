#include <cstdio>
#include <algorithm>
#include <unordered_map>

constexpr int D = 10001;

int cache[D];
std::unordered_map<int, std::unordered_map<int, int>> dist{};
std::unordered_map<int, std::unordered_map<int, bool>> info{};

int main(){

	int n, d;
	scanf("%d %d", &n, &d);

	for(int i = 0; i < n; i ++){
		int s, e, k;
		scanf("%d %d %d", &s, &e, &k);
		if(!info[e][s]) dist[e][s] = k;
		dist[e][s] = std::min(dist[e][s], k);
	}

	for(int cur = 1; cur <= d; cur ++){
		int tmp = cache[cur-1] + 1;
		for(auto [prv, delta]: dist[cur])
			tmp = std::min(tmp, cache[prv] + delta);
		cache[cur] = tmp;
	}

	printf("%d\n", cache[d]);

	return 0;
}
