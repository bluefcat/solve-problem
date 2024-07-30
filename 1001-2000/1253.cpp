#include <cstdio>
#include <array>
#include <algorithm>
#include <utility>

using ll = long long;
using std::array;
constexpr int N = 2001;

int main(){
	int result = 0, n = 0;
	array<ll, N> arr{};

	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%lld", arr.begin()+i);
	
	std::sort(arr.begin(), arr.begin() + n);
	
	for(int i = 0; i < n; i ++){
		int l = 0;
		int r = n-1;
		
		while(l < r){
			int s = arr[l] + arr[r];
			if(l == r)
				r --;
			else if(l == i)
				l ++;
			else if(r == i)
				r --;
			else if(s > arr[i])
				r --;
			else if(s < arr[i])
				l ++;
			else {
				result ++;
				break;
			}
		}
	}


	printf("%d\n", result);

	return 0;
}
