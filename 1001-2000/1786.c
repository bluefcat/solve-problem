#include <stdio.h>
#include <string.h>

#define MAXLEN 1000002

char T[MAXLEN];
char P[MAXLEN];
int pi[MAXLEN];

int idx[MAXLEN];
int count;

void get_pi(const char* p){
	int n = strlen(p);
	
	int j = 0;

	for(int i = 1; i < n; i ++){
		while(j > 0 && p[i] != p[j]) j = pi[j-1];
		if(p[i] == p[j]) pi[i] = ++j;
	}

	return;
}

int find(const char* s, const char* p){
	int n = strlen(s);
	int m = strlen(p);
	
	get_pi(p);

	int j = 0;
	for(int i = 0; i < n; i ++){
		while(j > 0 && s[i] != p[j]) j = pi[j-1];
		if(s[i] == p[j]){
			if(j == m-1){
				idx[count ++] = i-m+2;				
				j = pi[j];
			}
			else{
				j ++;
			}
		}
	}
}

int main(){
	gets(T);
	gets(P);

	find(T, P);

	printf("%d\n", count);

	for(int i = 0; i < count; i ++){
		printf("%d ", idx[i]);
	}
	printf("\n");

	return 0;
}
