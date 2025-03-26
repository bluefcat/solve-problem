#include <cstdio>
#include <vector>
#include <algorithm>
constexpr int N = 200001;
int curn[N] = { 0, };
int goal[N] = { 0, };

bool compare_a(int& x, int& y){
	return x > y;
}

bool compare_b(int& x, int& y){
	return x < y;
}

int main(){
	std::vector<int> r{};
	std::vector<int> p{};

	int n, m, z = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++) scanf("%d", curn + i);
	for(int i = 0; i < n ; i ++){
		scanf("%d", goal+i);
	}
	std::vector<int> giver{};
	for(int i = 0; i < n; i ++){
		if(goal[i] == 0) giver.push_back(i);	
	}

	if(giver.size() == 0){
		int t = 0;
		for(int i = 1; i < n; i ++)
			if(goal[i] < goal[t]) t = i;
		giver.push_back(t);
	}

	for(int i = 0; i < n; i ++){
		bool flag = false;
		for(auto& x: giver) flag |= (x == i);
		if(flag) continue;
		r.push_back(curn[i]);
		p.push_back(goal[i]);
	}

	std::sort(r.begin(), r.end(), compare_a);
	std::sort(p.begin(), p.end(), compare_b);
	printf("%d\n", 2*n-2);
	
	int idx = 0;
	for(auto& x: r){
		printf("+ %d %d\n", giver[idx], x);
	}	

	for(int i = 1; i < n; i ++){
		printf("- 1 %d\n", goal[i]);
	}


	return 0;
}
