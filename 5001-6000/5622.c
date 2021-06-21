#include <stdio.h>

int main(){
	int table[26] = {2, 2, 2,
					 3, 3, 3,
					 4, 4, 4,
					 5, 5, 5,
					 6, 6, 6,
					 7, 7, 7, 7,
					 8, 8, 8,
					 9, 9, 9, 9};

	int result = 0;
	char word[16];

	scanf("%s", word);
	char* p = word;

	while(*p){
		result += table[(*p)-'A']+1;
		p ++;
	}

	printf("%d\n", result);
	return 0;
}
