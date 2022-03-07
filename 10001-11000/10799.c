#include <stdio.h>
#include <string.h>

int stack[100001];
int head;

int main(){
	int result = 0;
	char string[100001] = { 0, };

	scanf("%s", string);
	
	int lazer = 0;

	for(int i = 0; i < strlen(string); i ++){
		if(string[i] == '('){
			stack[head++] = '(';
		}
		else if(string[i] == ')'){
			head --;
			if(string[i-1] == '(') result += head;
			else result ++;

		}

	}

	printf("%d\n", result);	

	return 0;
}
