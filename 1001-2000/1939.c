#include <stdio.h>

typedef struct _bridge{
	int a;
	int b;
	int c;
} bridge;

int parent[10001];
bridge cache[100001];

int main(){
	int n, m, to, from;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++) parent[i] = i; 

	for(int i = 0; i < m; i ++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		cache[i] = (bridge){a, b, c};
	}

	scanf("%d %d", &to, &from);

	return 0;
}
