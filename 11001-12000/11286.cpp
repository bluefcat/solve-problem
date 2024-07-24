#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using std::vector;
using std::priority_queue;

struct Compare{
	bool operator()(int x, int y){
		return std::abs(x) > std::abs(y) || x > y;
	}
};

int main(){
	priority_queue<int, vector<int>, Compare> q{};
	int n = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x = 0;
		scanf("%d", &x);
		if(x != 0){
			q.push(x);
			continue;
		}
		printf("%d\n", !q.empty()?q.top():0);
		if(!q.empty())q.pop();
	}

	return 0;
}
