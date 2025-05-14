#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <utility>
constexpr int N = 1'002;

int arr[N];

std::vector<int> count(int l, int r){
	printf("count %d %d\n", l, r);
	std::cout << std::flush;
	int x, y, z, w;
	scanf("%d %d %d %d", &x, &y, &z, &w);
	std::vector count{x, y, z, w};
	return count;
}

int diff(int l, int r){
	printf("diff %d %d\n", l, r);
	std::cout << std::flush;

	int result = 0;
	scanf("%d", &result);
	return result;
}

bool check(int s, int e){
	int ndif = diff(s+1, e+1);
	return ndif <= 0;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i ++){
		int n;
		scanf("%d", &n);
		if(n == -1) return 0;

		std::vector<std::pair<int, int>> p{};
		
		int init = 0;
		
		while(init < n){
			int yes = init, no = n-1;
			while(yes + 1 < no){
				int mid = (yes + no) >> 1;
				if(check(init, mid)) yes = mid;
				else no = mid;
			}
			int cnt = 0;
			for(auto x: count(init+1, no+1)) cnt += (x == 0);
			p.push_back({init, std::min(n-1, yes + (cnt == 3))});
			init = yes+1+(cnt==3);
		}

		int result[4] = { 0, };
		int idx = 0;
		for(auto [l, r]: p){
			result[idx] += r-l+1;
			idx = (idx + 1) % 4;
		}
		printf("! %d %d %d %d\n", result[0], result[1], result[2], result[3]);
		std::cout << std::flush;
	}
	return 0;
}
