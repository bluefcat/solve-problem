#include <stdio.h>
#define MAXLEN 101

int main(){
	char buffer[MAXLEN] = { 0, };

	while(scanf("%[^\n]\n", buffer) == 1){
		printf("%s\n", buffer);
	}

	return 0;
}
