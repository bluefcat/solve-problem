#include <stdio.h>

void draw_rect(int n, int a, int x){
	if(n == 1){
		printf("*");
		return ;
	}
	
	for(int i = x; i < n; i ++){
		for(int j = 0; j < 3; j ++){
			if((n/3 <= i && i < 2*n/3)&&(j==1)){
			   	for(int k = 0; k < n/3; k ++) printf(" ");
			}
			else draw_rect(n/3, a, i%(n/3));
		}
		if(n != a) return ;
		printf("\n");
	}

	return ;
}

int main(){
	int n = 0;
	scanf("%d", &n);

	draw_rect(n, n, 0);

	return 0;
}
