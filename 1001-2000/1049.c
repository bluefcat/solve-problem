#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y){
	return (int*)x (int*)y;
}

int main(){
	int n, m;
	int cache[51][2];
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i ++){
		scanf("%d %d", cache[i], cache[i]+1);
	}

	

	return 0;
}
