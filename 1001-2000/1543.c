#include <stdio.h>

int get_length(const char* string){
	int result = 0;
	while(*string++) result ++;

	return result;
}

void get_pi(const char* word, int* pi){
	int j = 0;
	for(int i = 1; i < get_length(word); i ++){
		while(j > 0 && word[i] != word[j]) j = pi[j-1];
		if(word[i] == word[j]) pi[i] = ++j;
	}
	return;
}

int search(const char* content, const char* word, const int* pi, int start){
	int m = get_length(content);
	int n = get_length(word);

	int j = 0;
	for(int i = start; i < m; i ++){
		while(j > 0 && content[i] != word[j]) j = pi[j-1];

		if(content[i] == word[j]){
			if(j == n-1) return i-n+1;
			else j ++;
		}
	}
	
	return -1;
}

int main(){
	char content[2501] = { 0, };
	char word[51] = { 0, };
	int pi[51] = { 0, };

	scanf("%[^\n]s", content);
	scanf(" %[^\n]s", word);
	
	get_pi(word, pi);
	
	int idx = 0;
	int result = 0;
	
	do{
		idx = search(content, word, pi, idx);
		
		if(idx != -1){
			result ++;
			idx += get_length(word);
		}
	}
	while(idx != -1);

	printf("%d\n", result);

	return 0;
}
