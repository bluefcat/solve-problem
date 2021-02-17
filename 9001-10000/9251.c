#include <stdio.h>

int cache[1002][1002];

int count_string(const char* str){
	int result = 0;
	while(*(str++)){
		result ++;
	}
	return result;
}

int main(){
	int result = 0;
	char str1[1001];
	char str2[1001];

	scanf("%s", str1);
	scanf("%s", str2);

	int length1 = count_string(str1);
	int length2 = count_string(str2);

	for(int i = 1; i < length1+1; i ++){
		for(int j = 1; j < length2+1; j ++){
			if(str1[i-1] == str2[j-1]){
				cache[i][j] = cache[i-1][j-1]+1;
			}
			else if(cache[i-1][j] >= cache[i][j-1]){
				cache[i][j] = cache[i-1][j];
			}
			else cache[i][j] = cache[i][j-1];
		}
	}	

	result = cache[length1][length2];

	printf("%d\n", result);
	return 0;
}
