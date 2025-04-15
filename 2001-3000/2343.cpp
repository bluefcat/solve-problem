#include <cstdio>

using lint = long long;
constexpr lint N = 100'001;

lint arr[N];

bool check(lint n, lint m, lint l){
	lint c = 1, s = 0;
	for(lint i = 0; i < n; i ++){
		if(arr[i] > l) return false;
		if(s + arr[i] > l){
			s = 0;
			c ++;
		}
		s += arr[i];
	}
	return m >= c;
}

int main(){
	lint n, m;
	scanf("%lld %lld", &n, &m);
	for(lint i = 0; i < n; i ++)
		scanf("%lld", arr+i);

	lint no = 0, yes = 100'000 * 10'000 + 1;

	while(no + 1 < yes){
		lint mid = (yes + no) >> 1;
		if(check(n, m, mid)) yes = mid;
		else no = mid;
	}
	printf("%lld\n", yes);

	return 0;
}
