#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>

using std::vector;
using std::array;
constexpr int N = 100001;

bool compare(
	const std::pair<int, int>& x,
	const std::pair<int, int>& y
){
	return x.first < y.first;
}

int main(){
	int n = 0;
	vector<
		std::pair<int, int>
	> pole;
	
	array<std::pair<int, int>, N> arr{};
	array<int, N> count{};

	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		pole.push_back({x, y});
	}

	std::sort(
		pole.begin(), pole.end(), compare
	);
	
	int length = 0;
	for(int cur = 0; cur < n; cur ++){
		auto&[x, y] = pole[cur];
		if(
			length == 0 || 
			arr[length-1].second < y
		){
			arr[length] = {x, y};
			count[cur] = length+1;
			length ++;
			continue;
		}	
		auto iter = std::lower_bound(
			arr.begin(), 
			arr.begin()+length, 
			y,
			[](std::pair<int, int>& t, int target){
				return target > t.second;
			}
		);	
		std::size_t idx = std::distance(arr.begin(), iter);
		arr[idx] = {x, y};
		count[cur] = idx+1;
	}

	vector<int> result{};
	printf("%d\n", n - length);
	for(int i = n-1; i >= 0; i --){
		if(length == count[i]){
			length --;
			continue;
		}
		result.push_back(pole[i].first);
	}

	std::reverse(result.begin(), result.end());

	for(auto x: result){
		printf("%d\n", x);
	}


	return 0;
}
