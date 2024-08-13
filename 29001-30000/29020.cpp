#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::vector;
using std::string;

int main(){
	vector<string> dict{};
	unordered_map<string, int> cnt{};
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++){
		char tmp[11] = { 0, };
		scanf("%s", tmp);
		string str{tmp};
		if(str.size() < m) continue;
		if(cnt[tmp] != 0){
			cnt[tmp] ++; continue;
		}
		dict.push_back(tmp);
		cnt[tmp] ++;
	}

	std::sort(
		dict.begin(), dict.end(),
		[&](const auto& x, const auto& y){
			if(cnt[x] == cnt[y] && x.size() == y.size()) return x < y;
			if(cnt[x] == cnt[y]) return x.size() > y.size();
			return cnt[x] > cnt[y];
		}
	);	


	printf("--\n");
	for(auto& str: dict){
		printf("%s\n", str.c_str());
	}

	return 0;
}
