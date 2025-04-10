#include <cstdio>
#include <algorithm>

using lint = long long;
constexpr int N = 1'000'000;
lint arr[N] = { 0, };

bool check(lint n, lint m, lint k){
	lint result = 0;
	for(int i = 0; i < n; i ++)
		result += std::max(arr[i] - k, (lint)0);
	
	return !(result >= m);
};

int main(){
	lint n, m;
	scanf("%lld %lld", &n, &m);
	for(int i = 0; i < n; i ++)
		scanf("%lld", arr+i);

	lint yes = 0, no = 2*10e9;

	while(yes+1 < no){
		lint mid = (yes + no) >> 1;	
		if(check(n, m, mid)) no = mid;
		else yes = mid;
	}
	printf("%lld\n", yes);
	return 0;
}
