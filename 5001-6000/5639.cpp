#include <cstdio>

constexpr int N = 10001;
constexpr int get_left(int idx){
	return (idx << 1) + 1;
}
constexpr int get_right(int idx){
	return (idx << 1) + 2;
}

int insert(int x, int* graph, int idx){
	if(graph[idx] == 0) return graph[idx] = x;
	if(graph[idx] > x){
		return insert(x, graph, get_left(idx));
	}
	return insert(x, graph, get_right(idx));
}

void post_order(int* graph, int idx){
	if(graph[idx] == 0) return;

	post_order(graph, get_left(idx));
	post_order(graph, get_right(idx));
	printf("%d\n", graph[idx]);
}

int main(){
	int graph[5*N] = { 0, };
	int arr[N] = { 0, };
	int x, n = 0;

	while(scanf("%d", &x) != EOF)
		arr[n++] = x;
	for(int i = 0; i < n; i ++)
		insert(arr[i], graph, 0);
	
	post_order(graph, 0);

	return 0;
}
