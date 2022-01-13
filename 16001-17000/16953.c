#include <stdio.h>

int main(){
	int x, y, cnt = 0;

	scanf("%d %d", &x, &y);

	while(1){
		if(x > y){
			printf("-1\n");
			break;
		}
		if(x == y){
			printf("%d\n", cnt+1);
			break;
		}

		if(y % 10 == 1){
			y --;
			y /= 10;
		}
		else if((y & 1) == 0){
			y >>= 1;
		}
		else{
			printf("-1\n");
			break;
		}
		cnt ++;
	}


	return 0;
}
