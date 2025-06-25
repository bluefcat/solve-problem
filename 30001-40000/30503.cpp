#include <cstdio>
#include <cmath>
#include <unordered_map>

using lint = long long;
constexpr int N = 1'000'000;

struct Bucket{
	lint l = N+1, r = 0;
	bool f = false;
	std::unordered_map<lint, lint> cnt{};
};

lint arr[N] = { 0, };
Bucket bucket[N] = {};

int main(){
	lint n;
	scanf("%lld", &n);
	for(lint i = 0; i < n; i ++) scanf("%lld", arr+i);
	
	lint sn = std::sqrt(n);
	for(lint i = 0; i < n; i ++){
		bucket[i/sn].l = std::min(bucket[i/sn].l, i);
		bucket[i/sn].r = std::max(bucket[i/sn].r, i);
		bucket[i/sn].cnt[arr[i]] ++;
	}
	
	lint q;
	scanf("%lld", &q);
	
	while(q--){
		lint oper, l, r, k, result = 0;
		scanf("%lld", &oper);
		switch(oper){
			case 1:
				{
					scanf("%lld %lld %lld", &l, &r, &k);
					l--; r--;
					while(l % sn != 0 && l <= r){
						if(bucket[l/sn].f){ 
							l++;
							continue;
						}
						result += (arr[l++] == k);
					}
					while((r+1) % sn != 0 && l <= r){
						if(bucket[r/sn].f){
							r --;
							continue;
						}
						result += (arr[r--] == k);
					}

					while(l <= r){
						result += bucket[l/sn].cnt[k];
						l += sn;
					}

					printf("%lld\n", result);
					break;
				}
			case 2:
				{
					scanf("%lld %lld", &l, &r);
					l--; r--;
					while(l % sn != 0 && l <= r){
						bucket[l/sn].cnt[arr[l]] --;
						arr[l++] = 0;
					}
					while((r+1) % sn != 0 && l <= r){
						bucket[r/sn].cnt[arr[r]] --;
						arr[r--] = 0;

					}
					while(l <= r){
						bucket[l/sn].cnt.clear();
						bucket[l/sn].f = true;
						l += sn;
					}
				break;
			}
		}
	}

	return 0;
}

