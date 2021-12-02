#include <stdio.h>
#include <string.h>
#define CMAX 101

char cache[CMAX];

int main(){
	scanf("%s", cache);

	for(int i = 0; i < strlen(cache); i ++){
		printf("%c", cache[i]);
		if(i != 0 && i % 10 == 9) printf("\n");
	}

	return 0;
}
