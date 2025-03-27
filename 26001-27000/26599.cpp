#include <cstdio>
#include <cstdlib>
#include <algorithm>

using lint = long long;
constexpr lint N = 1000002;

lint power[N][2] = { 0, };
lint result[N] = { 0, };

int compare(const void* x, const void* y){
	return ((int*)x)[0] > ((int*)y)[0];
}
int main(){
	lint n, m;	
	lint ls = 0, lm = 0;
	lint rs = 0, rm = 0;

	scanf("%lld %lld", &n, &m);
	for(int i = 0; i < n; i ++){
		scanf("%lld", power[i]);
		power[i][1] = i+1;
		ls += power[i][0];
	}

	qsort(power, n, sizeof(lint)*2, compare);

	lm = power[n-1][0];
	ls -= lm;

	int l = 0, r = n-1;
	int idx = 0;

	while(l != r){
		if(ls + m < lm || (rs != 0 && rs + m < rm)) break;	
		
		lint a = ls - power[r-1][0];
		lint b = ls - power[l][0];

		if(std::abs(a-power[r-1][0]) <= std::abs(b-power[r][0])){
			if(rm == 0){
				rm = power[r][0];
			}
			else{
				rs += std::min(rm, power[r][0]);
				rm = std::max(rm, power[r][0]);
			}
			ls -= power[r-1][0];
			lm = power[r-1][0];
			result[idx] = power[r][1]; 
			idx ++; r--;
		}
		else{
			if(rm == 0){
				rm = power[l][0];
			}
			else{
				rs += power[l][0];
			}
			ls -= power[l][0];
			result[idx] = power[l][1];
			l ++; idx ++;
		}
	}


	if(l != r || rs + m < rm){
		printf("NO\n");
		return 0;
	}

	result[idx] = power[l][1];

	printf("YES\n");
	for(int i = 0; i < n; i ++)
		printf("%lld ", result[i]);
	printf("\n");

	return 0;
}
