#include <cstdio>
#include <vector>
#include <algorithm>

int mgcd(int x, int y){
	if(y == 0) return x;
	return mgcd(y, x%y);
}

int main(){
	std::vector<int> v{};
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	int answer = 0;
	std::sort(v.begin(), v.end());

	for(int i = 0; i < n-1; i ++){
		answer += (mgcd(v[i+1], v[i]) != 1);
	}
	printf("%d\n", answer);

	return 0;
}
