#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <algorithm>

using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::stack;

constexpr int N = 5001;

template<typename T, typename S, typename V>
int build(int& id, T& graph, int cur, int* ids, bool* finished, S& s, V& result){
	ids[cur+N] = ++id;
	s.push(cur);
	int parent = ids[cur+N];

	for(auto& nxt: graph[cur]){
		if(ids[nxt+N] == 0)
			parent = std::min(
				parent, 
				build(id, graph, nxt, ids, finished, s, result)
			);
		else if(finished[nxt+N] == false)
			parent = std::min(parent, ids[nxt+N]);
	}
	if(parent != ids[cur+N]) return ids[cur+N] = parent;
	
	vector<int> tmp{};

	while(true){
		int x = s.top(); s.pop();
		tmp.push_back(x);
		finished[x+N] = true;
		ids[x+N] = parent;
		if(x == cur) break;
	}
	std::sort(tmp.begin(), tmp.end());
	result.push_back(tmp);
	return parent;

}

int main(){
	int id = 0;
	int ids[2*N] = { 0, };
	bool finished[2*N] = { false, };
	unordered_map<int, unordered_set<int>> graph{};
	stack<int> s{};
	vector<vector<int>> scc{};
	int k, n;
	scanf("%d %d", &k, &n);
	for(int i = 0; i < n; i ++){
		int cand[3] = { 0, };
		for(int j = 0; j < 3; j ++){
			int l; char c;
			scanf("%d %c", &l, &c);
			cand[j] = (c=='R')?-l:l;
		}
		graph[-cand[0]].insert(cand[1]);
		graph[-cand[1]].insert(cand[0]);

		graph[-cand[1]].insert(cand[2]);
		graph[-cand[2]].insert(cand[1]);

		graph[-cand[2]].insert(cand[0]);
		graph[-cand[0]].insert(cand[2]);
	}

	for(int i = -k; i <= k; i ++){
		if(i == 0 || finished[i+N]) continue;
		build(id, graph, i, ids, finished, s, scc);
	}	
	for(int i = 1; i <= k; i ++){
		if(ids[i+N] == ids[-i+N]){
			printf("-1\n");
			return 0;
		}
	}
	int result[2*N+1] = { 0, }; 
	for(int i = 0; i < 2*N+1; i ++) result[i] = -1;

	std::reverse(scc.begin(), scc.end());
	for(auto& v: scc){
		for(auto& x: v){
			int k = std::abs(x)+N; 
			if(result[k] != -1) continue;
			result[k] = (x<0);
		}
	}

	for(int i = 1; i <= k; i ++){
		printf("%c", result[i+N]==0?'R':'B');
	}
	printf("\n");

	return 0;
}
