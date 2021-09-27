#include <stdio.h>
#include <string.h>

#define MAX(X, Y) ((X)>(Y)? (X): (Y))
#define M 10001

void revstr(char *str1)  
{  
    int i, len, temp;  
    len = strlen(str1); 

    for (i = 0; i < len/2; i++)  
    {  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  

int main(){
	
	char a[M];
	char b[M];

	char result[M+1] = { 0, };
	scanf("%s %s", a, b);

	revstr(a);
	revstr(b);

	for(int i = 0; i < M; i ++){
		result[i] += '0';

		if(a[i] == 0 && b[i] == 0) break;

		int am = MAX(a[i] -'0', 0);
		int bm = MAX(b[i] -'0', 0);

		int one_sum = am + bm;
		
		result[i] += (one_sum % 10);
		result[i+1] += (one_sum / 10);

	}

	revstr(result);

	if(result[0] == '0') printf("%s\n", result+1);
	else printf("%s\n", result);


	return 0;
}
