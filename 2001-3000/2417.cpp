#include <cstdio>

using lint = unsigned long long;

bool check(lint n, lint q){
	return q*q >= n;
}


int main(){
	lint n;
	scanf("%lld", &n);

	lint no = -1, yes = ((lint)1<<32) + 1;
	
	while(yes > no + 1){
		lint mid = (yes + no) >> 1;
		if(check(n, mid)) yes = mid;
		else no = mid;
	}

	printf("%lld\n", yes);
	return 0;
}
