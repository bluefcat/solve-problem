#include <stdio.h>

char alphabet[8][4] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int mstrlen(char* p){
	int result = 0;
	while(*p){
		p ++;
		result ++;
	}
	return result;
}

int is_croatia(char* p){
	int idx = -1;
	
	for(int i = 0; i < 8; i ++){
		
		char* tmp = p;
		char* alp = alphabet[i];

		while(*tmp && *alp){
			if(*tmp != *alp) goto NO_MATCH;
			tmp ++; alp ++;
		}	
		
		if(!(*alp)) idx = i;

		NO_MATCH:
			continue;
	}

	return idx;
}

int main(){
	int result = 0;
	char string[101] = { 0, };

	scanf("%s", string);
	
	char* p = string;

	while(*p){
		int next = 1;
		
		int idx = is_croatia(p);
		if(idx != -1){
			next = mstrlen(alphabet[idx]);
		}
		result ++;
		p += next;
	}
	
	printf("%d\n", result);

	return 0;
}
