#include <cstdio>
#include <algorithm>
using lint = long long;
constexpr int N = 100'001;

lint arr[N] = { 0, };

bool check(lint n, lint k, lint mid){
	lint cnt = 1, prev = arr[0];
	for(lint i = 1; i < n; i ++){
		if(arr[i] >= prev + mid){
			prev = arr[i];
			cnt ++;
		}
	}
	return k <= cnt;
}

int main(){
	lint n, k;
	scanf("%lld %lld", &n, &k);
	
	for(int i = 0; i < n; i ++)
		scanf("%lld", arr+i);
	
	std::sort(arr+0, arr+n);

	lint yes = 0, no = 10e9+1;
	while(yes + 1 < no){
		lint mid = (yes + no) >> 1;
		if(check(n, k, mid)) yes = mid;
		else no = mid;
	}
	printf("%lld\n", yes);
	return 0;
}
