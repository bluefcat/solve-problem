#include <stdio.h>
#include <stdlib.h>

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

int is_vowel(char x){
	for(int i = 0; i < sizeof(vowel)/sizeof(char); i ++){
		if(vowel[i] == x) return 1;
	}

	return 0;
}

int compare(const void* x, const void* y){
	return *(char*)x - *(char*)y;
}

int main(){
	int L, C;
	char alpha[15] = { 0, };
	
	scanf("%d %d", &L, &C);
	
	for(int i = 0; i < C; i ++) scanf(" %c", alpha+i);
	qsort(alpha, C, sizeof(char), compare);


	for(int i = 0; i < C; i ++){
		printf("%c = %d\n", alpha[i], is_vowel(alpha[i])); 

	}


	return 0;
}
