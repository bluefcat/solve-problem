#include <stdio.h>

char string[101];
char vowel[] = { 'a', 'e', 'i', 'o', 'u' };

int main(){
	int result = 0;
	scanf("%s", string);
	
	char* p = string;

	while(*p){
		for(int i = 0; i < 5; i ++) result += (int)(vowel[i] == *p);
		p ++;
	}

	printf("%d\n", result);

	return 0;
}
