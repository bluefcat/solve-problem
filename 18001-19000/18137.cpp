#include <cstdio>
#include <vector>
#include <tuple>

using lint = long long;

constexpr lint get_n(lint x, lint y){
	return ((x+y+1) * (x+y) >> 1) + y + 1;
}

constexpr lint f(lint i, lint x){
	return i - x;
}

bool check[100][100];	
int main(){
	int k;
	lint result = 0;
	scanf("%d", &k);
	std::vector<std::tuple<lint, lint>> m{
		{-1, -3}, {-2, -3}, {1, -1}, {-2, -1},
		{2, 1}, {-1, 1}, {2 ,3}, {1, 3}
	};
	lint i = 0, x = 0, y = 0;
	check[0][0] = true;
	while(k --){
		bool flag = false;
		result ++;
		for(auto& [dx, di]: m){
			lint ni = i +di, nx = x+dx;
			if(ni < 0 || nx < 0) continue;
			if(check[ni][nx]) continue;
			lint ny = f(ni, nx);
			if(ny < 0) continue;
			i = ni, x = nx, y = ny;
			check[i][x] = true; flag = true;
			break;
		}	
		if(!flag) break;
	}
	printf("%lld\n", get_n(x, y));


	return 0;
}
