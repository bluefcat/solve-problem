#include <cstdio>
#include <deque>
#include <algorithm>

using std::deque;
using ll = long long;

constexpr int N = 500001;

int main(){
	ll arr[N] = { 0, };
	ll cache[N] = { 0, };
	deque<ll> cont{};
	deque<ll> tmp{};
	int n;
	scanf("%d\n", &n);
	for(int i = 0; i < n; i ++)
		scanf("%lld", arr+i);

	cont.push_front(arr[0]);
	cache[0] = 0;

	for(int i = 1; i < n; i ++){
		if(cont.front() > arr[i]){
			cont.push_front(arr[i]);
			cache[i] = 1;
		}
		else{
			ll cnt = 0;
			ll idx = std::upper_bound(
				cont.begin(), 
				cont.end(), 
				arr[i]
			) - cont.begin();
			cache[i] = (idx < cont.size()) + idx;
			while(!cont.empty() && cont.front() < arr[i]){
				cont.pop_front();
			}
			cont.push_front(arr[i]);
			//printf("[%d] %lld, %d + %d\n", i, arr[i], !cont.empty(), cnt);
		}
	}
	
	//for(int i = 0; i < n; i ++) printf("%lld ", cache[i]);
	//printf("\n");

	ll result = 0;
	for(int i = 0; i < n; i ++)
		result += cache[i];

	printf("%lld\n", result);

	return 0;
}
