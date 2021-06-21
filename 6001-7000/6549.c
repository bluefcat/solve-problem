#include <stdio.h>

int main(){
	int height[100000] = { 0, };
	int n = 0;
		
	while(scanf("%d", &n) && n != 0){
		for(int i = 0; i < n; i ++) scanf("%d", height+i);
		
		int result = 0;
		find_area(&result, height, n);		
		printf("%d\n", result);
	}

	return 0;
}
