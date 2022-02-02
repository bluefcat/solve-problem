#include <stdio.h>
#include <stdlib.h>

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

int compare(const void* x, const void* y){
	return *(char*)x - *(char*)y;
}

int mstrlen(const char* x){
	int result = 0;
	while(*x){
		result ++;
		x ++;
	}

	return result;
}

int is_vowel(char x){
	for(int i = 0; i < sizeof(vowel)/sizeof(char); i ++){
		if(vowel[i] == x) return 1;
	}

	return 0;
}

int in_consonant(const char* x){
	int result = 0;

	while(*x){
		result += (int)(is_vowel(*x) == 0);

		x ++;
	}
	return result;
}

int in_vowel(const char* x){
	return mstrlen(x) - in_consonant(x);
}

int mpow(int x, int y){
	int result = 1;
	
	while(y != 0){
		if(y & 1) result *= x;

		y >>= 1;
		x *= x;
	}
	
	return result;
}

int main(){
	int L, C;
	char alpha[16] = { 0, };
	
	scanf("%d %d", &L, &C);
	
	for(int i = 0; i < C; i ++) scanf(" %c", alpha+i);
	qsort(alpha, C, sizeof(char), compare);

	int chk = mpow(2, C);

	while(chk){
		if(__builtin_popcount(chk) == L){
			int idx = C-1;
			
			char result[16] = { 0, };
			int ridx = 0;
			int aidx = 0;
			while(idx >= 0){
				if( chk&(1 << idx) ) result[ridx++] = alpha[aidx];
				aidx ++;
				idx --;
			}
			if(in_consonant(result) >= 2 && in_vowel(result) >= 1) printf("%s\n", result);
		}
		chk --;
	}
	return 0;
}
