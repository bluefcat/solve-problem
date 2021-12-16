#include <stdio.h>
#include <string.h>

int main(){
	char string[1000001] = { 0, };
	scanf("%s", string);
	
	int len = strlen(string);
	int padding = len % 3;
	
	int result = 0;
	for(int i = 0; i < padding; i ++){
		int tmp = padding - (i+1);
		
		result += (string[i]-'0') * (1 << tmp);
		
	}
	
	if(result) printf("%d", result);

	for(int i = padding; i < len; i += 3){
		int a = string[i+0]-'0';
		int b = string[i+1]-'0';
		int c = string[i+2]-'0';

		printf("%d", a*4+b*2+c);
	}

	if(len == 1 && string[0] == '0') printf("0");

	printf("\n");

	return 0;
}
