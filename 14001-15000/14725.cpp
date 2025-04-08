#include <cstdio>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

constexpr int N = 15001;
std::pair<
	std::string, std::vector<int>
> tri[N]{};

int ids = 0;

void append(int id, std::vector<std::string>& key, int idx){
	if(idx == key.size()) return;
	
	for(auto next: tri[id].second){
		if(tri[next].first == key[idx]){
			return append(next, key, idx+1);
		}
	}
	
	int next = ++ids;
	tri[id].second.emplace_back(next);
	tri[next] = {key[idx], {}};
	return append(next, key, idx+1);
}

void print(int id, int indent=-1){
	for(int i = 0; i < indent; i ++) printf("--");
	printf("%s\n", tri[id].first.c_str());

	std::sort(
		tri[id].second.begin(), 
		tri[id].second.end(), 
		[&](int x, int y){ return tri[x].first < tri[y].first; }
	);

	for(auto next: tri[id].second){
		print(next, indent+1);
	}
}


int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;	
		scanf("%d", &n);
		std::vector<std::string> str{};
		for(int i = 0; i < n; i ++){
			char tmp[N];
			scanf("%s", tmp);
			str.emplace_back(tmp);
		}
		append(0, str, 0);
	}
	print(0);
	return 0;
}
