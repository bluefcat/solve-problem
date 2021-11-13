#include <stdio.h>

int is_vowel(char x){
	int result = 0;
	char vowels[] = { 'a', 'e', 'i', 'o', 'u' };

	for(int i = 0; i < 5; i ++){
		if(vowels[i] == x){
			result = 1;
			break;
		}
	}
	return result;
}

void swap(char* x, char* y){
	char tmp = *x;
	*x = *y;
	*y = tmp;
}

int partition(char* arr, int l, int r){
	int pidx = r-1;
	char pivot = arr[pidx];

	int c = l;

	for(int i = l; i < pidx; i ++){
		if(arr[i] < pivot){
			swap(arr + c, arr + i);
			c ++;
		}
	}

	swap(arr+c, arr+pidx);
	return c;
}

void quicksort(char* arr, int l, int r){
	if(l+1 >= r) return;

	int pidx = partition(arr, l, r);
	quicksort(arr, l, pidx);
	quicksort(arr, pidx+1, r);
}

int main(){
	char words[15] = { 0, };
	int L, C;
	scanf("%d %d", &L, &C);

	for(int i = 0; i < C; i ++) scanf(" %c", words+i);
	quicksort(words, 0, C);

	
	return 0;
}

