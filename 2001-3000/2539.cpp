#include <cstdio>
#include <algorithm>

using lint = long long;
constexpr lint N = 1'000'001;
lint arr[N];
lint h = 0;

bool check(lint c, lint n, lint s){
	lint idx = 1, used = 0;
	if(h > s) return false;
	while(idx <= c){


		if(arr[idx] != 0){
			used ++;
			idx += s;
			continue;
		}
		idx ++;
	}
	return n >= used;	
}

int main(){
	lint r, c;
	scanf("%lld %lld", &r, &c);
	lint n, k;
	scanf("%lld %lld", &n, &k);
	for(int i = 0; i < k; i ++){
		lint r1, c1;
		scanf("%lld %lld", &r1, &c1);
		arr[c1] = std::max(arr[c1], r1);
		h = std::max(h, r1);
	}

	lint no = 0, yes = c;
	while(no + 1 < yes){
		lint mid = (no + yes) >> 1;
		if(check(c, n, mid)) yes = mid;
		else no = mid;
	}
	printf("%lld\n", yes);
	return 0;
}
