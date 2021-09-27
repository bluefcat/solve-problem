#include <stdio.h>
#include <string.h>

int main(){
	const char* alpha[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	char content[101] = { 0, };
	int length = 0, result = 0;

	scanf("%s", content);
	length = strlen(content);

	// mode = 0 ; normal alphabet
	// mode = 1 ; croatia alphabet
	int mode = 0;

	for(int i = length-1; i >= 0; i --){
		if(strchr("=-j", content[i]) != NULL) mode = 1;
		else if(mode == 1 && strchr("cdlnsz", content[i]) != NULL){
			mode = 0;
			result ++;
		}
		else if(mode == 0){
			result ++;
		}

		printf("[%d], %c\n", mode, content[i]); 
	}
	
	
	printf("%d\n", result);

	return 0;
}
