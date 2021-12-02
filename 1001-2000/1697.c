#include <stdio.h>
#define QMAX 100001

int queue[QMAX];
int head, tail;

int visited[100001];
int n, p;

int dx[] = { 1, -1, 2 };

int dfs(int s){
	queue[tail] = s;
	tail = (tail + 1)%QMAX;
	visited[s] = 1;

	while(head != tail){
		s = queue[head];
		head = (head + 1)%QMAX;
		
		if(s == p) return visited[s] - 1;

		for(int i = 0; i < 3; i ++){
			int ns;
			ns = s + dx[i];
			if(i == 2) ns = s << 1;
			
			if(ns < 0 || 100001 <= ns) continue;
			if(visited[ns]) continue;

			visited[ns] = visited[s] + 1;

			queue[tail] = ns;
			tail = (tail + 1)%QMAX;
		}
	}

	return 0;

};

int main(){
	scanf("%d %d", &n, &p);
		
	int result = dfs(n);

	printf("%d\n", result);

	return 0;
}
