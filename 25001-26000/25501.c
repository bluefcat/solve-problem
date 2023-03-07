#include <stdio.h>
#include <string.h>

int recursion(const char *s, int l, int r, int* count){
	(*count)++;

	if(l >= r) return 1;
	else if(s[l] != s[r]) return 0;
	return recursion(s, l+1, r-1, count);
}

int isPalindrome(const char* s, int* count){
	return recursion(s, 0, strlen(s) - 1, count);
}

int main(){
	int n = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		int count = 0;
		char s[1001] = { 0, };
		scanf("%s", s);
		
		int result = isPalindrome(s, &count);

		printf("%d %d\n", result, count);
		
	}

	return 0;
}
