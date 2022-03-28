#include <stdio.h>

int main(){
	int n;
	int cache[2] = { 0, };
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		int idx = 0;
		scanf("%d", &idx);
		cache[idx] ++;
	}

	printf("Junhee is%scute!\n", cache[0] < cache[1]? " ": " not "); 

	return 0;
}
