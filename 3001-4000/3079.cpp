#include <cstdio>
using lint = unsigned long long;
constexpr int N = 100'001;
lint arr[N] = { 0, };

bool check(lint n, lint m, lint t){
	if(t == 0) return false;
	
	lint total = 0;
	for(int i = 0; i < n; i ++){
		total += t / arr[i];
	}
	return total >= m;
}

int main(){
	lint n, m;
	n = 1e5; m = 1e9;
	scanf("%lld %lld", &n, &m);
	lint k = 0;
	for(int i = 0; i < n; i ++){
		scanf("%lld", arr+i);
		if(k < arr[i]) k = arr[i];	
	}
	
	lint no = 0, yes = m * k;

	while(no+1 < yes){
		lint mid = (no + yes) >> 1;
		if(check(n, m, mid)) yes = mid;
		else no = mid;
	}

	printf("%lld\n", yes);
	return 0;
}
