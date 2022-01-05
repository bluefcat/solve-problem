#include <stdio.h>
#include <string.h>

#define IS_NCASE(X) ('0' <= (X) && (X) <= '9')
#define IS_BCASE(X) ('A' <= (X) && (X) <= 'Z')
#define IS_SCASE(X) ('a' <= (X) && (X) <= 'z')
#define IS_WCASE(X) (' ' == (X))

int main(){
	char string[102] = { 0, };
	
	while(fgets(string, sizeof(string), stdin) != NULL){
		int n = 0, b = 0, s = 0, w = 0;

		char* p = string;

		while(*p){
			if(IS_NCASE(*p)) n ++;
			if(IS_BCASE(*p)) b ++;
			if(IS_SCASE(*p)) s ++;
			if(IS_WCASE(*p)) w ++;
			p ++;
		}
		
		printf("%d %d %d %d\n", s, b, n, w);
	}
	return 0;
}
