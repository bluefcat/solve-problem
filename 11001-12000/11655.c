#include <stdio.h>
#include <string.h>

#define ISB(X) (('A' <= (X) && (X) <= 'Z'))
#define ISS(X) (('a' <= (X) && (X) <= 'z'))
#define SMAX 101

int main(){
	char string[SMAX] = { 0, };
	
	scanf("%[^\n]s", string);

	int length = strlen(string);

	for(int i = 0; i < length; i ++){
		char target = string[i];

		if(ISB(target)){
			target = ((target - 'A' + 13) % 26) + 'A';
		}

		else if(ISS(target)){
			target = ((target - 'a' + 13) % 26 ) + 'a';
		}

		string[i] = target;
	}

	printf("%s\n", string);

	return 0;
}
