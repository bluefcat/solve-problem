#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using ll = long long;
constexpr int N = 31;

void find(int* arr, int l, int r, ll c, ll sum, vector<ll>& result){
	if(sum > c) return;
	if(l == r){
		result.push_back(sum);
		return;
	}
	find(arr, l+1, r, c, sum, result);
	find(arr, l+1, r, c, sum + arr[l], result);
}


int main(){
	int arr[N] = { 0, };
	vector<ll> lv{};
	vector<ll> rv{};
	int n, c;
	long long result = 0;
	scanf("%d %d", &n, &c);

	for(int i = 0; i < n; i ++) scanf("%d", arr+i);
	find(arr, 0, n>>1, c, 0, lv);
	find(arr, n>>1, n, c, 0, rv);

	std::sort(rv.begin(), rv.end());

	for(auto x: lv){
		result += std::upper_bound(
			rv.begin(), 
			rv.end(), 
			c-x
		) - rv.begin();
	}

	printf("%lld\n", result);

	return 0;
}
