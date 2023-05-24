#include <stdio.h>
#include <string.h>

int main(){
	int t = 0;

	int set[21] = { 0, };
	scanf("%d", &t);
	while(t--){
		char oper[10] = { 0, };
		int n = 0;
		scanf(" %s", oper);
		if(strcmp(oper, "all") != 0 || strcmp(oper, "empty") != 0) scanf(" %d", &n);
		switch(oper[0]){
			case 'a':
				if(strcmp(oper, "add") == 0){
					set[n] = 1;
				}
				else{
					for(int i = 1; i < 21; i ++) set[i] = 1;
				}
				break;
			case 'r':
				set[n] = 0;
				break;
			case 'c':
				printf("%d\n", set[n]);
				break;
			case 't':
				set[n] ^= 1;
				break;
			case 'e':
				for(int i = 1; i < 21; i ++) set[i] = 0;
				break;
		}
	}
	return 0;
}
