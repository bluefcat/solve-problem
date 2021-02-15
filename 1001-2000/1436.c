#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int count = 0;
	int num = 0;
	
	while(count < n){
		int s_count = 0;
		int temp = ++num;
		while(temp != 0 && s_count != 3){
			if(s_count != 0 && temp%10 != 6) s_count = 0;
			if(temp%10 == 6) s_count ++;
			temp /= 10;
		}

		if(s_count == 3) count ++;
	}

	printf("%d\n", num);

	return 0;
}
