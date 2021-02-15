#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);

	for(int i = 0; i < T; i ++){
		int mem[2] = { 1, 0 };
		int n;
		scanf("%d", &n);

		for(int j = 0; j < n; j ++){
			int tmp = mem[0];
			mem[0] = mem[1];
			mem[1] += tmp;
		}
	
		printf("%d %d\n", mem[0], mem[1]);

	}
	return 0;
}
