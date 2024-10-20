#include <cstdio>

int main(){
	int n = 30;
	for(int i = 0; i < n; i ++){
		int t = 1;
		for(int j = 0; j < n; j ++){
			printf("%d ", t);
			if(i == j){
				t = 100;
			}
		}
			printf("\n");
	}
	return 0;
}
