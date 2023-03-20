#include <cstdio>
#include <algorithm>
#include <map>

int main(){
	std::map<int, std::pair<int, int>> m;

	int v;
	scanf("%d", &v);

	for(int i = 0; i < v; i ++){
		int s, d, dist, _;
		scanf("%d %d %d %d", &s, &d, &dist, &_);
		
		m.insert({s, {d, dist}});
	
	}



	return 0;
}
