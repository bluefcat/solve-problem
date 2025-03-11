#include <cstdio>
#include <algorithm>

constexpr int N = 1000001;
constexpr int M = 1000001;

const char symbol[] = "IO";
char str[M];
char chn[M];
int count[M];



int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", str);

	int length = 0;
	int index = 0;
	int result = 0;

	int x = 0, y = 1;
	while(y < m){
		if(str[x] == 'I' && str[y] == 'O'){
			chn[length++] = 'A';
			x += 2, y += 2;
		}	
		else{
			chn[length++] = str[x];
			x ++, y ++;
		}
	}
	while(x < m)
		chn[length++] = str[x++];

	x = 0, y = 1;
	while(y < length){
		if(chn[x] == 'A' && (chn[y] == 'A' || chn[y] == 'I')){
			count[y] = count[y-1] + 1;
		}
		x++, y++;
	}
	
	int tmp = 0;
	for(int i = 0; i < y; i ++){
		tmp = (tmp < count[i])?count[i]:tmp;
		if(count[i] == 0 || (count[i] != 0 && i == y-1)){
			result += std::max((tmp-(n-1)), 0); 
			tmp = 0;
		}
	}

	printf("%d\n", result);
	return 0;
}
