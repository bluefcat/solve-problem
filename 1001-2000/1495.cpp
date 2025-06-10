#include <cstdio>
#include <queue>

constexpr int M = 1001;
int cache[M];

int main(){
	int n, s, m;
	scanf("%d %d %d", &n, &s, &m);

	std::queue<int> p{};
	p.push(s);
	cache[s] = 0;
	
	
	for(int i = 0; i < n; i ++){
		int v;
		scanf("%d", &v);

		std::queue<int> q{};
		while(!p.empty()){
			q.push(p.front()); p.pop();
		}

		while(!q.empty()){
			int x = q.front(); q.pop();

			if(x+v <= m){ 
				p.push(x+v);
				cache[x+v] = cache[x]+1;
			}

			if(x-v >= 0){
				p.push(x-v);
				cache[x-v] = cache[x]+1;
			}
		}
	}
	int result = -1;
	for(int i = 0; i <= m; i ++){ 
		if(result < i && cache[i] == n)
			result = i;
	}

	printf("%d\n", result);


	return 0;
}
