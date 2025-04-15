#include <cstdio>
#include <algorithm>

using lint = long long;
constexpr lint N = 5'001;

lint arr[N];
lint diff[N][N];

bool check(lint n, lint k, lint s){
	if(s == -1) return false;
	lint c = 1, idx = 0;
	
	for(lint i = 0; i < n;){
		lint d = 0;
		for(;d < n; d ++){
			if(diff[i][i+d] > s){
				d --;
				c ++;
				break;
			}
		}
		i += d + 1;
	}

	return k >= c;
}

int main(){
	lint n, k;
	scanf("%lld %lld", &n, &k);
	for(lint i = 0; i < n; i ++) scanf("%lld", arr+i);

	for(lint i = 0; i < n; i ++){
		lint m = arr[i], M = arr[i];
		for(lint j = i; j < n; j ++){
			m = std::min(m, arr[j]);
			M = std::max(M, arr[j]);
			diff[i][j] = M-m;
		}
	}

	lint no = -1, yes = 10'001;
	while(no + 1 < yes){
		lint mid = (no + yes) >> 1;
		if(check(n, k, mid)) yes = mid;
		else no = mid;
	}
	printf("%lld\n", yes);

	return 0;
}
