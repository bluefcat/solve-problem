#include <stdio.h>

#define INF -1
#define MIN(X, Y) (((X) > (Y))? (Y): (X))
//0, from
//1, to
//2, weight
int edge[300001][3];
int cache[300001];
int route[20001];
int route_count;

int main(){
	int v, e, s;
	scanf("%d %d", &v, &e);
	scanf("%d", &s);
	
	for(int i = 0; i < e; i ++) 
		scanf("%d %d %d", edge[i]+0, edge[i]+1, edge[i]+2);
	
	//init
	for(int i = 0; i < e; i ++) cache[i] = i == s? 0: INF;

	int cur = s; route_count ++;


	for(int i = 0; i < e; i ++){
		if(edge[i][0] != s) continue;
		
		int to = edge[i][1];
		int weight = edge[i][2];

		cache[to] = weight;
	}

	


	return 0;
}
