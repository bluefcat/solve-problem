#include <stdio.h>
#include <string.h>
	
int main(){
	char string[101] = { 0, };

	scanf("%s", string);
	printf("%ld\n", strlen(string));

	return 0;
}
