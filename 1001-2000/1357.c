#include <stdio.h>

int rev(int x){
	int result = 0, idx = 0;
	int tmp[9] = { 0, };

	while(x){
		tmp[idx ++] = x % 10;
		x /= 10;
	}

	int t = 1;
	for(int i = 0; i < idx; i ++){
		result += tmp[idx-(i+1)] * t;
		t *= 10;
	}

	return result;
}

int main(){
	int x, y;
	scanf("%d %d", &x, &y);

	printf("%d\n", rev(rev(x) + rev(y)));
	return 0;
}
