#include <cstdio>

using lint = long long;

bool check(lint n, lint q){
	return q*q >= n;
}


int main(){
	lint n;
	scanf("%lld", &n);

	lint yes = 0, no = ((lint)1<<32) + 1;
	
	while(yes + 1 < no){
		lint mid = (yes + no) >> 1;
		if(check(n, mid)) no = mid;
		else yes = mid;
	}

	if(!check(n, yes))
		yes ++;

	printf("%lld\n", yes);
	return 0;
}
