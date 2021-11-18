#include <stdio.h>
#include <string.h>

int main(){
	char result[1000001] = { 0, };
	char binary[1000001] = { 0, };
	int result_length = 0;
	int length = 0;
	char c = 0;

	while(scanf("%1c", &c) && c != '\n'){
		binary[length++] = c;
	}
	
	for(int i = 0; i < length >> 1; i ++){
		char tmp = binary[i];
		binary[i] = binary[length - (i+1)];
		binary[length - (i+1)] = tmp;
	}

	for(int i = 0; 3*i+2 < length; i ++){

		int a = 3*i;
		int b = 3*i+1;
		int c = 3*i+2;
	
		int p = (binary[a]-'0')+(binary[b]-'0')*2+(binary[c]-'0')*4;
		result[result_length ++] = p + '0';
	}

	int p = 0;
	for(int i = 0; i < length % 3; i ++){
		int t = (length/3)*3;
		
		p += (binary[t]-'0') * (1 << i);
	}
	if(p) result[result_length++] = p +'0';
	
	for(int i =0; i < result_length >> 1; i ++){
		char tmp = result[i];
		result[i] = result[result_length-(i+1)];
		result[result_length-(i+1)] = tmp;
	}

	printf("%s\n", result);
	return 0;
}
