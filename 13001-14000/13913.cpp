#include <cstdio>
#include <stack>
#include <queue>

constexpr int N = 100001;
using std::stack;
using std::queue;



int main(){
	int cache[N] = { 0, };
	int result[N] = { 0, };
	queue<std::pair<int, int>> q{};
	int n, k;
	scanf("%d %d", &n, &k);
	
	cache[n] = 1;
	q.push({n, 1});
	
	int m = 0;

	while(!q.empty()){
		auto [x, t] = q.front(); q.pop();
		if(x == k){
			m = t;
			break;
		}
		
		int nx = x+1, px = x-1, tx = x << 1; 
		if(nx < N && !cache[nx]){
			cache[nx] = t+1;
			q.push({nx, t+1});
		} 	
		if(0 <= px && !cache[px]){
			cache[px] = t+1;
			q.push({px, t+1});
		} 
		if(tx < N && !cache[tx]){
			cache[tx] = t+1;
			q.push({tx, t+1});
		}

	}
	
	while(!q.empty()) q.pop();
	q.push({k, m});
	while(!q.empty()){
		auto [x, t] = q.front(); q.pop();
		result[t-1] = x;
		int nx = x+1, px = x-1, tx = x/2;
		if(nx < N && cache[nx] == t-1)
			q.push({nx, t-1});
		else if(0 <= px && cache[px] == t-1)
			q.push({px, t-1});
		else if(tx < N && cache[tx] == t-1)
			q.push({tx, t-1});

	}
	printf("%d\n", m-1);	
	for(int i = 0; i < m; i ++){
		printf("%d ", result[i]);
	}
	printf("\n");

	return 0;
}
