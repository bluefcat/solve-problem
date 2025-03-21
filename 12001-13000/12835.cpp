#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
using lint = long long;
constexpr lint N = 50001;

constexpr int get_idx(char x){
	return x-'A';
}

int main(){
	lint result[3] = { 0, };
	std::unordered_map<lint, std::vector<lint>> ant{};

	lint t = 0;

	lint n, l;
	scanf("%lld %lld", &n, &l);
	
	for(int i = 0; i < n; i ++){
		char idx;
		lint p, d;
		scanf("\n%c %lld %lld", &idx, &p, &d);
		
		if(d == 1){
			t += l-p; 
			result[get_idx(idx)] ++;
			continue;
		}

		ant[p].push_back(get_idx(idx));
		t += l+p;
	}

	for(auto& [p, v]: ant){
		if(v.size() > 1){
			for(auto& idx: v) result[idx] ++;
			continue;
		}
		result[(v[0] + 1) % 3] ++;
	}

	printf("%lld\n", t);
	for(int i = 0; i < 3; i ++)
		printf("%lld ", result[i]);
	printf("\n");

	return 0;
}
