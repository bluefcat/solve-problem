#include <stdio.h>
#include <string.h>
#define SMAX 1001

char string[SMAX] = { 0, };
int cache[SMAX+1][SMAX+1];

int main(){
	scanf("%s", string);

	int length = strlen(string);

	for(int i = 0; i < length; i ++){
		int cnt = 1;
		for(int j = 0; j < length; j ++){
			if(i == j) continue;

			int n = ((string[j] == '(')? 1: -1);
			
			cache[i][cnt] = n + cache[i][cnt-1];
			cnt ++;
		}
	}
	
	for(int i = 0; i < length; i ++){
		for(int j = 0; j <= length; j ++){
			printf("%d\t", cache[i][j]);
		}
		printf("\n");
	}


	return 0;
}
