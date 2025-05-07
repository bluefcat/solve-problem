#include <cstdio>
#include <utility>
#include <queue>
#include <tuple>
#include <cmath>

using lint = long long;
using pair = std::pair<lint, lint>;
using queue = std::queue<std::tuple<lint, lint, lint>>;

constexpr int N = 1'003;

pair arr[N];

lint d(pair& x, pair& y){
	return std::pow(x.first - y.first,2) + 
		   std::pow(x.second - y.second,2);
}

bool check(lint n, lint k, lint fuel){
	lint visited[N] = { 0, };
	for(int i = 0; i < n; i ++) visited[i] = k+1;
	queue q{};
	q.push({0, 0, fuel});
	visited[0] = 0;
	
	while(!q.empty()){
		auto [cur, cnt, f] = q.front(); q.pop();
		for(lint i = 0; i < n; i ++){
			lint dist = d(arr[i], arr[cur]);
			if(dist > fuel*fuel * 100) continue;
			if(dist > f * f * 100){
				if(visited[i] <= cnt+1) continue;
				q.push({i, cnt+1, fuel});
				visited[i] = cnt+1;
			}
			else{
				if(visited[i] <= cnt) continue;
				lint k = std::ceil(std::sqrt(dist));
				q.push({i, cnt, (f * 10 - k)/10 });
				visited[i] = cnt;
			}
		}
	}
	return visited[n-1] <= k;
}


int main(){
	lint n, k;
	scanf("%lld %lld", &n, &k);
	arr[0] = { 0, 0 };
	for(lint i = 1; i < n+1; i ++){
		lint x, y;
		scanf("%lld %lld", &x, &y);
		arr[i] = {x, y};
	}
	arr[n+1] = { 10000, 10000 };
	n += 2;
	
	lint no = 0, yes = 15000;
	while(no + 1 < yes){
		lint mid = (no + yes) >> 1;
		if(check(n, k, mid)) yes = mid;
		else no = mid;
	}
	printf("%lld\n", yes);	
	return 0;
}
