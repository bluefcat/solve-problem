#include <stdio.h>

int main(){
	int v[31] = { 0, };

	for(int i = 0; i < 28; i ++){
		int n;
		scanf("%d", &n);
		v[n] = 1;
	}

	for(int i = 1; i < 31; i ++){
		if(v[i] == 0){
			printf("%d\n", i);
		}
	}


	return 0;
}
