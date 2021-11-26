#include <stdio.h>

int n;
int cache[13];
int choice[6];

void generate(int current, int remain){
	if(remain == 0){
		for(int i = 0; i < 6; i ++){
			printf("%d ", choice[i]);
		}
		printf("\n");
		return;
	}
	
	for(int idx = current+1; idx < n; idx++){
		choice[6-remain] = cache[idx];
		generate(idx, remain-1);

	}
	return ;
}

int main(){
	
	while(scanf("%d", &n) && n != 0){
		for(int i = 0; i < n; i ++){
			scanf("%d", cache+i);
		}

		generate(-1, 6);
		printf("\n");
	}

}
