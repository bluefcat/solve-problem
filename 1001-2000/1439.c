#include <stdio.h>

#define MIN(X, Y) (((X) > (Y))? (Y): (X))
#define MAXSTRING 1000001

char string[MAXSTRING];
int count[2];

int main(){
	scanf("%s", string);

	if(*string == '\0'){
		printf("0\n");
		return 0;
	}

	char* p = string;
	int mode = (*p) - '0';
	count[mode] ++;

	while(*p){
		int tmp = (*p) - '0';
		
		if(mode != tmp){
			mode = tmp;
			count[mode] ++;
		}

		++p;
	}

	printf("%d\n", MIN(count[0], count[1]));

	return 0;
}
