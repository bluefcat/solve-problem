#include <cstdio>
#include <climits>
#include <algorithm>

using lint = unsigned long long;
constexpr lint N = 123456+1;

lint arr[N][3]; // type, ai, hi

bool check(lint n, lint mhp, lint atk){
	lint chp = mhp;
	for(int i = 0; i < n; i ++){
		if(chp <= 0) return false;
		
		switch(arr[i][0]){
			case 1:
			{
				lint et = (chp / arr[i][1]) + (chp % arr[i][1] != 0);
				lint pt = (arr[i][2] / atk) + (arr[i][2] % atk != 0);
				if(pt <= et){
					lint dmg = arr[i][1] * (pt - 1);
					if(dmg >= chp) chp = 0;
					else chp -= dmg;
				}
				else
					chp = 0;
			}
			break;
			case 2:
				atk += arr[i][1];
				chp = std::min(mhp, chp + arr[i][2]);
			break;
		}
	}
	return chp > 0;
}

int main(){
	lint n, atk;
	scanf("%lld %lld", &n, &atk);

	for(int i = 0; i < n; i ++)
		scanf("%lld %lld %lld", arr[i] + 0, arr[i] + 1, arr[i] + 2);
	
	lint no = 0, yes = ULONG_LONG_MAX;
	while(no + 1 < yes){
		lint mid = (no + yes) >> 1;
		if(check(n, mid, atk)) yes = mid;
		else no = mid;
	}
	printf("%lld\n", yes);

	return 0;
}
