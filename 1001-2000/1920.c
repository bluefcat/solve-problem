#include <stdio.h>
#include <stdlib.h>

int arr[100001];

int compare(const void* a, const void* b){
	return *(long*)a - *(long*)b;
}

void Solution(int n, int key){
    int start = 0;
    int end = n-1;
    int mid;
 
    while(end - start >= 0){
        mid = (start + end)/2;
 
        if(arr[mid] == key){
            printf("1\n");
            return ;
 
        }else if(arr[mid] > key) {
            end = mid - 1;
 
        }else{ 
            start = mid + 1;
        }
    }
 
    printf("0\n");
    return ;
}

int main(){
	int N = 0, M = 0;
	
	scanf("%d", &N);
	for(int i = 0; i < N; i ++){
		scanf("%d", arr+i);
	}
	
	qsort(arr, N, sizeof(int), compare);

	scanf("%d", &M);
	for(int i = 0; i < M; i ++){
		int k = 0;
		scanf("%d", &k);
		Solution(N, k);
	}

	return 0;
}
