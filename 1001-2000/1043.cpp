#include <cstdio>
#include <unordered_map>
#include <vector>
#include <queue>

int main(){
	int n, m;
	std::vector<int> knower;
	std::unordered_map<int, bool> check;
	std::vector<
		std::vector<int>
	> party;

	std::unordered_map<
		int,
		std::vector<int>
	> network;

	scanf("%d %d", &n, &m);
	int x;
	scanf("%d", &x);
	for(int i = 0; i < x; i ++){
		int a;
		scanf("%d", &a);
		knower.push_back(a);
	}

	for(int i = 0; i < m; i ++){
		int a, b, c;
		scanf("%d", &a);
		scanf("%d", &b);
		party.push_back({});
		party[i].push_back(b);
		for(int j = 1; j < a; j ++){
			scanf("%d", &c);
			party[i].push_back(c);
			network[b].push_back(c);
			network[c].push_back(b);
			b = c;
		}
	}
	std::queue<int> next;	
	for(const auto& k: knower){
		next.push(k);	
		check[k] = true;
	}
	
	while(!next.empty()){
		int i = next.front(); next.pop();
		for(const auto& nk: network[i]){
			if(check[nk]) continue;
			
			next.push(nk);
			check[nk] = true;
		}
	}
	
	int result = 0;
	for(const auto& vec: party){
		bool know_lie = false;
		for(const auto& p: vec)
			know_lie |= check[p];
		
		result += !know_lie;
	}
	printf("%d\n", result);
	return 0;
}
