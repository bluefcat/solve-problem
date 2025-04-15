#include <cstdio>

using lint = long long;
constexpr lint N = 10'002;

lint arr[N];

bool check(lint n, lint k, lint s){
	lint c = 0, sum = 0;
	for(lint i = 0; i < n; i ++){
		if(s <= sum){
			c ++;
			sum = 0;
		}
		sum += arr[i];
	}
	if(s <= sum) c++;
	return k <= c;
}

int main(){
	lint n, k;
	scanf("%lld %lld", &n, &k);
	for(lint i = 0; i < n; i ++) scanf("%lld", arr+i);

	lint yes = 0, no = 20 * N;
	while(yes + 1 < no){
		lint mid = (no + yes) >> 1;
		if(check(n, k, mid)) yes = mid;
		else no = mid;
	}
	printf("%lld\n", yes);

	return 0;
}
