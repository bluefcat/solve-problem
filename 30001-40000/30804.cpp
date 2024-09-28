#include <cstdio>
#include <algorithm>

using std::max;
constexpr int S = 9;
constexpr int N = 200001;

int main(){
	int result = 0;
	int n;
	int arr[N] = { 0, };
	int count[S] = { 0, };
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d", arr+i);

	int s = 0, e = -1;
	int var = 0;
	while(s != n-1){
		if(var <= 2 && e < n-1){
			e ++;
			if(count[arr[e]] == 0) var ++;
			count[arr[e]] ++;
			if(var <= 2) result = max(result, e-s+1);
		}
		else if(var > 2){
			count[arr[s]] --;
			if(count[arr[s]] == 0) var --;
			s ++;
		}
		else{
			count[arr[s]] --;
			if(count[arr[s]] == 0) var --;
			s ++;
			if(var <= 2) result = max(result, e-s+1);
		}
	}

	printf("%d\n", result);
	return 0;
}
