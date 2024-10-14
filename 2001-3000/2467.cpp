#include <cstdio>
#include <algorithm>
#include <utility>

using lint = long long;
constexpr int N = 100001;

int main(){
	lint table[N] = { 0, };
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%lld", table+i);

	std::sort(table+0, table+n);

	int l = 0, r = n-1;
	lint result[2] = { table[l], table[r] };

	while(l < r){
		if(table[r] + table[l] < 0){
			l ++;
		}
		else{
			r --;
		}
		if(l == r) continue;
		if(std::abs(result[1] + result[0]) > std::abs(table[r] + table[l])){
			result[0] = table[l];
			result[1] = table[r];
		}
		if(result[1] + result[0] == 0) break;
	}
	
	if(result[0] > result[1]) 
		std::swap(result[0], result[1]);

	printf("%lld %lld\n", result[0], result[1]);
	return 0;
}
