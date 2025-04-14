#include <cstdio>
#include <algorithm>

using lint = long long;
constexpr int N = 52;
lint arr[N];

bool check(lint n, lint m, lint d){
	int total = 0;
	for(int i = 0; i < n; i ++)
		total += (arr[i] / d) - (arr[i] % d == 0);
	
	return !(total > m);
}

int main(){
	lint n, m, l;
	scanf("%lld %lld %lld", &n, &m, &l);
	
	arr[0] = 0, arr[n+1] = l-1;
	for(int i = 1; i <= n; i ++)
		scanf("%lld", arr+i);
	std::sort(arr, arr+n+2);
	
	for(int i = 0; i <= n; i ++)
		arr[i] = arr[i+1] - arr[i]; 
	
	std::sort(arr, arr+n+1, [](lint x, lint y){ return x > y; });

	lint no = 0, yes = l;
	
	while(no + 1 < yes){
		lint mid = (yes + no) >> 1;
		if(check(n+1, m, mid)) yes = mid;
		else no = mid;
	}
	printf("%lld\n", yes);

	return 0;
}
