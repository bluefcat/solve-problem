#include <stdio.h>

int main(){
	int result = 0, l = 0;
	char str[1000001] = { 0, };
	
	scanf("%[^\n]s", str);
	
	if(*str != ' ') result ++;
	for(char* p = str; *p; p ++){
		if(*p == ' ') result ++;
		l ++;
	}
	if(*(str+l-1) == ' ') result --;


	printf("%d\n", result);
	return 0;
}
