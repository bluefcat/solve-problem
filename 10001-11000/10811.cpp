#include <cstdio>

int main(){
	int arr[101] = { 0, };
	for(int i = 0; i < 101; i ++) arr[i] = i+1;

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		
		if(x == y) continue;
		
		x --; y --;
		while(x <= y){
			int swap_value = arr[x];
			arr[x] = arr[y];
			arr[y] = swap_value;
			x ++; y --;
		}
	}

	for(int i = 0; i < n; i ++) printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
