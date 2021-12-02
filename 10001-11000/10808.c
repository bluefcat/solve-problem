#include <stdio.h>
#include <string.h>

char string[101];
int cache[26];

int main(){
	scanf("%s", string);

	for(int i = 0; i < strlen(string); i ++){
		cache[string[i]-'a'] ++;
	}

	for(int i = 0; i < 26; i ++){
		printf("%d ", cache[i]);
	}
	printf("\n");

	return 0;
}
