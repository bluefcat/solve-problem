#include <stdio.h>

int mstrlen(char* p){
	int result = 0;
	
	char* q = p;
	while(*q){
		q ++;
		result ++;
	}

	return result;
}

int main(){
	char str[1000000] = { 0, };	
	scanf("%s", str);

	printf("%d\n", mstrlen(str));
	printf("%s\n", str);

	return 0;
}
