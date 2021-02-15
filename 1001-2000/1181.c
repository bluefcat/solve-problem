#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char** create_set(int n){
	char** result = (char**)malloc(sizeof(char*)*n);
	result[0] = (char*)malloc(sizeof(char)*n*51);
	for(int i = 1; i < n; i ++) result[i] = result[i-1]+51;

	return result;
}

void copy_string(char* dest, const char* src){
	int i = 0;
	while(*src){
		dest[i] = src[0];
		src ++;
		i ++;
	}
	dest[i] = '\0';
	return ;
}

void merge(char** set, int p, int q, int r){
	int lsize = q-p, rsize = r-q;
	
	char** lset = create_set(lsize+1);
	for(int i = 0; i < lsize; i ++) copy_string(lset[i], set[i+p]);
	for(int i = 0; i < 50; i ++) lset[lsize][i] = 'z';
	lset[lsize][50] = '\0';

	char** rset = create_set(rsize+1);
	for(int i = 0; i < rsize; i ++) copy_string(rset[i], set[i+q]);
	for(int i = 0; i < 50; i ++) rset[rsize][i] = 'z';
	rset[rsize][50] = '\0';

	int i = 0, j = 0;
	for(int k = p; k < r; k ++){
		int l_len = strlen(lset[i]);
		int r_len = strlen(rset[j]);
		if(l_len < r_len){
			copy_string(set[k], lset[i]);
			i ++;	
		}
		else if(l_len == r_len){
			if(strcmp(lset[i], rset[j]) < 0){
				copy_string(set[k], lset[i]);
				i ++;
			}
			else {
				copy_string(set[k], rset[j]);
				j ++;
			}
		}
		else {
			copy_string(set[k], rset[j]);
			j ++;
		}
	}

	free(rset[0]); free(rset);
	free(lset[0]); free(lset);
	return ;
}

void merge_sort(char** set, int p, int r){
	if(p+1 >= r) return;
	int q = (p+r)/2;
	merge_sort(set, p, q);
	merge_sort(set, q, r);
	merge(set, p, q, r);
	return ;
}

int main(){
	int n;
	scanf("%d", &n);
	char** set = create_set(n);

	for(int i = 0; i < n; i ++) scanf("%s\n", set[i]);

	merge_sort(set, 0, n);

	char* tmp = (char*)malloc(sizeof(char)*51);	
	for(int i = 0; i < n; i ++){
		if(!strcmp(tmp, set[i])) continue;
		printf("%s\n", set[i]);
		copy_string(tmp, set[i]);
	}

	free(set[0]); free(set);
	return 0;
}
