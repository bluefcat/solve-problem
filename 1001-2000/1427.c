#include <stdio.h>
#include <stdlib.h>

int count(const char* str){
	int result = 0;
	while(*(str++)){
		result ++;
	}
	return result;
}

void merge(char* str, int p, int q, int r){
	int lsize = q-p, rsize = r-q;
	char* lstr = (char*)malloc(sizeof(char)*lsize);
	for(int i = 0; i < lsize; i ++) lstr[i] = str[i+p];

	char* rstr = (char*)malloc(sizeof(char)*rsize);
	for(int i = 0; i < rsize; i ++) rstr[i] = str[i+q];

	int i = 0, j = 0;
	for(int k = p; k < r; k ++){
		if(lstr[i] >= rstr[j] && i < lsize){
			str[k] = lstr[i];
			i ++;
		}
		else{
			str[k] = rstr[j];
			j ++;
		}
	}

	return ;
}

void merge_sort(char* str, int p, int r){
	if(p+1 >= r) return;
	int q = (p+r)/2;
	merge_sort(str, p, q);
	merge_sort(str, q, r);
	merge(str, p, q, r);
	return ;
}

int main(){
	char* n = (char*)malloc(sizeof(char)*11);
	scanf("%s", n);
	
	merge_sort(n, 0, count(n));
	printf("%s\n", n);
	
	free(n);
	return 0;
}
