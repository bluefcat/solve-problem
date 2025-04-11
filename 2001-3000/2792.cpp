#include <cstdio>

using lint = long long;
constexpr int M = 300'000 + 1;
lint arr[M];

bool check(lint n, lint m, lint c){
	if(c == 0) return false;
	lint count = 0, remain = 0;	
	bool f = false;

	for(int i = 0; i < m; i ++)
		count += (arr[i] / c) + (arr[i] % c != 0);
	
	return count <= n;
}

int main(){
	lint n, m;
	scanf("%lld %lld", &n, &m);
	lint no = 0, yes = 0;
	for(int i = 0; i < m; i ++){
		scanf("%lld", arr+i);
		if(yes < arr[i]) yes = arr[i];
	}
	


	while(no + 1 < yes){
		lint mid = (yes + no) >> 1;
		if(check(n, m, mid)) yes = mid;
		else no = mid;
	}
	
	printf("%lld\n", yes);

	return 0;
}
