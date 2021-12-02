#include <stdio.h>

char string[51];
int main(){
	int n = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		char tmp[51];
		scanf("%s", tmp);
		
		int idx = 0;
		char* p = tmp;

		while(*p){
			if(i == 0){
				string[idx] = *p;
			}
			else{
				if(string[idx] != *p) string[idx] = '?';

			}

			idx ++; p ++;
		}

	}

	printf("%s\n", string);
	return 0;
}
