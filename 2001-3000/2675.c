#include <stdio.h>
#include <stdlib.h>

int main(){
	int T;
	scanf("%d", &T);

	for(int i = 0; i < T; i ++){
		int n;
		char str[22];
		scanf("%d %s", &n, str);
	
		char* tmp = str;	
		while(*tmp){
			for(int i = 0; i < n; i ++){
				printf("%c", tmp[0]);
			}
			tmp ++;
		}
		printf("\n");
	}

	return 0;
}
