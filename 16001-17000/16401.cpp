#include <cstdio>

using lint = long long;
constexpr lint N = 1'000'001;
lint arr[N];

bool check(lint m, lint n, lint l){
	if(l == 0) return false;
	lint count = 0;
	for(lint i = 0; i < n; i ++)
		count += arr[i] / l;
	return count >= m;
}


int main(){
	lint m, n;
	scanf("%lld %lld", &m, &n);
	for(lint i = 0; i < n; i ++)
		scanf("%lld", arr+i);

	lint yes = 0, no = 1'000'000'001;
	
	while(yes + 1 < no){
		lint mid = (yes + no) >> 1;
		if(check(m, n, mid)) yes = mid;
		else no = mid;
	}
	printf("%lld\n", yes);

	return 0;
}
