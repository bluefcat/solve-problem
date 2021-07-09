#include <stdio.h>

int tree[170000];
int height[100000];

int lg(int n){
	int result = 0;
	while(n > 1){
		n >>= 1;
		result ++;
	}
	return result;
}

int findNodeStart(int h){
	return (2<<(h-1))-1;
}

int main(){
	int n = 0;

	while(scanf("%d", &n) && n != 0){
		for(int i = 0; i < n; i ++) scanf("%d", height+i);
		
		for(int i = 0; i < 170000; i ++){
			tree[i] = 0;
		}

		int th = lg(n)+1;

		for(int i = 0; i < n; i ++){
			tree[th+i] = height[i];
		}

		for(int i = 0; i <= th; i ++){
			for(int j = 0; j < (1 << i); j ++){
				printf("%d ", tree[j]);
			}
			printf("\n");
		}

	}
	return 0;
}
