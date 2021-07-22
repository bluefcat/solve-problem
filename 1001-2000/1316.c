#include <stdio.h>

int main(){
	int N = 0, result = 0;
	scanf("%d", &N);

	for(int i = 0; i < N; i ++){
		char string[101] = { 0, };
		int check[26] = { 0, };
		scanf("%s", string);

		char* word = string;
		while(*word){
			if(check[(*word)-'a'] != 0){
				if(*(word-1) != *word) break;
			}
			check[(*word)-'a'] ++;
			word ++;
		}
		
		if(!(*word)) result ++;
		
	}

	printf("%d\n", result);

	return 0;
}
