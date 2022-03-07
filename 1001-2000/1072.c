#include <stdio.h>
#define PER(X, Y) (((X)*100)/(Y))
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int main(){
	long long x, y, result = -1;
	scanf("%lld %lld", &x, &y);
	
	long long rate = PER(y, x);
	

	int start = 0;
	int end = 1000000000;

	while(start <= end){

		int mid = (start + end) >> 1;
		long long tmp = PER((y+mid), (x+mid));

		if(rate < tmp){
			end = mid - 1;
		}
		else{
			result = mid + 1;
			start = mid + 1;
		}
	}
	
	if(PER((y+result), (x+result)) == rate) result = -1;
	printf("%lld\n", result);

	return 0;
}
