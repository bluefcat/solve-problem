#include <cstdio>
#include <climits>
#include <algorithm>

using lint = long long;

constexpr int N = 21;

lint village[N] = { 0, };
lint post[N] = { 0, };
lint result[N] = { 0, };
lint dist = LONG_LONG_MAX;

void solution(lint l, int p, int idx, int s, int v){
	if(p == idx){
		lint tmp = 0;
		for(int i = 0; i < v; i ++){
			lint d = LONG_LONG_MAX;
			for(int j = 0; j < p; j ++){
				d = std::min({
	  				d, 
	  				std::abs(village[i] - post[j]),
					l - std::abs(village[i] - post[j])
				});
			}
			tmp += d;
		}

		if(dist > tmp){
			dist = tmp;
			for(int i = 0; i < p; i ++) result[i] = post[i];
		}

	}
	
	for(int i = s; i < v; i ++){
		post[idx] = village[i];
		solution(l, p, idx+1, i+1, v);
	}

}


int main(){
	int v, p, l;
	scanf("%d %d %d", &v, &p, &l);
	
	for(int i = 0; i < v; i ++)
		scanf("%lld", village + i);

	solution(l, p, 0, 0, v);

	printf("%lld\n", dist);
	for(int i = 0; i < p; i ++) printf("%lld ", result[i]);
	printf("\n");

	return 0;
}
