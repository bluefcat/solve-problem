#include <cstdio>
#include <vector>

using lint = long long;
constexpr int N = 1'000'001;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		lint arr[N] = { 0, };
		std::vector<int> sell{};
		int n;
		scanf("%d", &n);
		lint max = 0, left = -1;
		for(int i = 0; i < n; i ++){ 
			scanf("%lld", arr+i);
			if(left == -1 || max < arr[i])
				max = arr[i], left = i;
		}
		sell.push_back(-1);
		sell.push_back(left);
		while(left < n-1){
			lint tmp = left+1;
			max = arr[left+1];
			for(int i = left+1; i < n; i ++){
				if(max < arr[i])
					max = arr[i], tmp = i;
			}
			if(left+1 == tmp) break;
			sell.push_back(tmp);
			left = tmp;
		}
		lint result = 0;
		for(int i = 0; i < sell.size()-1; i ++){
			int l = sell[i] + 1, r = sell[i+1];	
			for(int j = l; j < r; j ++)
				result += arr[r] - arr[j];
		}
		printf("%lld\n", result);
	}
	return 0;
}
