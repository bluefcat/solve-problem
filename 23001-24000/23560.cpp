#include <cstdio>

using lint = long long;

int arr[15*3];

lint get_result(int l, int r, int t){
	if(l == r) return 1;
	
	lint result = 0;
	if(arr[l] == t%2) result += get_result(l+1,r,(t+1)%3);
	if(arr[r] == t%2) result += get_result(l,r-1,(t+1)%3);
	return result;
}


int main(){
	int n = 0;
	scanf("%d", &n);
	for(int i = 0; i < 3*n; i ++){
		switch(i%3){
			case 0:
				arr[i] = 0;
				break;
			case 1:
				arr[i] = 1;
				break;
			case 2:
				arr[i] = 0;
				break;
		}
	}
	
	printf("%lld\n", get_result(0, 3*n-1, 0));

	return 0;
}
