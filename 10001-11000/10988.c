#include <stdio.h>

int main(){
	char string[101] = { 0, };
	int length = 0, result = 1;

	scanf("%s", string);

	char* p = string;
	while(*(p++)){
		length ++;
	}

	for(int i = 0 ; i < length >> 1; i ++){
		if(string[i] != string[length-1-i]){
			result = 0;
			break;
		}
	}

	printf("%d\n", result);
	return 0;

}
