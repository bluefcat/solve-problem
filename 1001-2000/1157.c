#include <stdio.h>

int main(){
	char str[1000001];
	int count[26], maxi = -1, maxr = 0;
	char result = 0;
	scanf("%s", str);

	char* p = str;
	while(*p){
		//upper letter
		if(97 <= *p && *p <= 122){
			(*p) -= 32;
		}	

		count[(int)(*p-'A')] ++;
		p ++;
	}
	
	for(int i = 0; i < 26; i ++){
		if(maxr < count[i]){
			maxi = i;
			maxr = count[i];
			result = i + 'A';
		}
	}
	
	for(int i = 0; i < 26; i ++){
		if(i == maxi) continue;
		if(maxr == count[i]) result = '?';
	}

	printf("%c\n", result);
	return 0;
}
