#include <cstdio>
#include <cstring>

constexpr int N = 200002;

int main(){
	int cache[N]['z'-'a'+1] = { 0, };
	char str[N];
	int n = 0;
	scanf("%s %d", str, &n);

	for(int i = 1; i < strlen(str)+1; i ++){
		for(char x = 'a'; x < 'z'+1; x ++){
			cache[i][x-'a'] += int(str[i-1] == x) + cache[i-1][x-'a'];
		}
	}
	
	for(int i = 0; i < n; i ++){
		char x; 
		int l, r;
		scanf("\n%c %d %d", &x, &l, &r);
		printf("%d\n", cache[r+1][x-'a'] - cache[l][x-'a']);
	}

	return 0;
}
