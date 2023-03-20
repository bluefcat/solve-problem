#include <stdio.h>

int main(){
	int code[8] = { 0, };
	for(int i = 0; i < 8; i ++) scanf("%d", code+i);
	
	int ascending = 1;
	int descending = 1;
	
	int cur = code[0];

	for(int i = 1; i < 8; i ++){
		ascending = ascending && (cur < code[i]);
		descending = descending && (cur > code[i]);
		cur = code[i];
	}

	if(ascending) printf("ascending\n");
	else if(descending) printf("descending\n");
	else printf("mixed\n");

	return 0;
}
