#include <stdio.h>
#include <string.h>

int main(){
	char string[6] = { 0, };

	while(scanf("%s", string) && string[0] != '0'){
		int l = strlen(string), result = 1;
		for(int i = 0; i < (l >> 1); i ++) result &= (int)(string[i] == string[l-1-i]);
		printf("%s\n", result == 1? "yes": "no");

		for(int i = 0; i < 6; i ++) string[i] = 0;
	}
	

	return 0;
}
