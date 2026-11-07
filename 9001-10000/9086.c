#include <stdio.h>
#include <string.h>

int main(){
	int T;
	char string[1001] = { 0, };

	scanf("%d", &T);
	while(T--){
		scanf("%s", string);

		int start = 0, end = strlen(string) - 1;
		printf("%c%c\n", string[start], string[end]);
	}
}
