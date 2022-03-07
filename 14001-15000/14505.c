#include <stdio.h>
#include <string.h>

int cache[32][32];

int main(){
	int length = 0, result = 0;
	char string[31] = { 0, };

	scanf("%s", string);
	length = strlen(string);
	
	for(int i = 0; i < length; i ++){
		cache[i][i] = 1;	
		if(i != 0){
			if(string[i-1] == string[i]) cache[i-1][i] = 3;
			else cache[i-1][i] = 2;
		}
	}
	
	for(int i = 2; i < length; i ++){
		for(int j = 0; i+j < length; j ++){
			if(string[j] == string[i+j]){
				cache[j][i+j] = cache[j+1][i+j] + cache[j][i+j-1] + 1;
			}
			else{
				cache[j][i+j] = cache[j+1][i+j] + cache[j][i+j-1] - cache[j+1][i+j-1];
			}
		}
	}
	
	printf("%d\n", cache[0][length-1]);

	return 0;
}
