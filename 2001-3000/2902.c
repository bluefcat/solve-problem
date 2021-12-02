#include <stdio.h>

char string[101];
char initial[101];

int main(){
	scanf("%s", string);

	int length = 0;
	int mode = 1;
	char* p = string;

	while(*p){
		if(mode == 1){
			initial[length++] = *p;
			mode = 0;
		}
		else{
			if(*p == '-') mode = 1;
		}
		p ++;
	}

	printf("%s\n", initial);


	return 0;
}
