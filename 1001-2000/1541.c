#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_dec(char* p){
	return '0' <= *p && *p <= '9'; 
}

int main(){
	char expr[51] = { 0, };
	int length = 0, result = 0;
	int status = 0;

	scanf("%s", expr);
	length = strlen(expr);
	
	char number[7] = { 0, };
	int nidx = 0;
	for(int i = 0; i < length; i ++){
		char tmp = expr[i];
		
		if(is_dec(&tmp)){
			number[nidx++] = tmp;
		}

		else{	
			if(status) result -= atoi(number);
			else result += atoi(number);

			if(tmp == '-') status = 1;	
			
			for(int i = 0; i < 7; i ++) number[i] = 0;
			nidx = 0;
		}
	}
	if(status) result -= atoi(number);
	else result += atoi(number);

	printf("%d\n", result);

	return 0;
}
