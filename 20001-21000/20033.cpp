#include <cstdio>
#include <algorithm>
using lint = long long;
constexpr int N = 300'001;

lint arr[N];

bool check(lint n, lint h){
	lint result = 0;
	lint tmp = 0;
	for(lint i = 0; i < n; i ++){
		if(arr[i] >= h)
			tmp ++;
		else{
			result = std::max(result, tmp);
			tmp = 0;
		}
	}
	result = std::max(result, tmp);
	
	return result >= h;
}

int main(){
	lint n;
	scanf("%lld", &n);
	for(int i = 0; i < n; i ++)
		scanf("%lld", arr+i);
	
	lint yes = 0, no = 10e9+1;
	while(yes + 1 < no){
		lint mid = (yes + no) >> 1;
		if(check(n, mid)) yes = mid;
		else no = mid;
	}
	printf("%lld\n", yes);

	return 0;
}
