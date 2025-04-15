#include <cstdio>

using lint = long long;
constexpr lint N = 100'001;

lint arr[N];

bool check(lint n, lint m, lint k){
	lint count = 0;
	lint tmp = 0;
	for(int i = 0; i < n; i ++){
		if(tmp < arr[i]){
			lint q = arr[i]/k + (arr[i] % k != 0);
			tmp = k*q;
			count += q;
		}
		tmp -= arr[i];
	}
	return count <= m;
}

int main(){
	lint n, m;
	scanf("%lld %lld", &n, &m);
	for(lint i = 0; i < n; i ++)
		scanf("%lld", arr+i);

	lint no = 0, yes = 100'000 * 10'000 + 1;
	yes = 501;
	while(no + 1 < yes){
		lint mid = (yes + no) >> 1;
		if(check(n, m, mid)) yes = mid;
		else no = mid;
	}

	printf("%lld\n", yes);
	return 0;
}
