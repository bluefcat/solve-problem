#include <stdio.h>

void swap(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}

int partition(int* arr, int l, int r){
	int p_idx = r-1;
	int pivot = arr[p_idx];
	
	int c = l;
	for(int i = l; i < p_idx; i ++){
		if(arr[i] < pivot) {
			swap(arr + c, arr + i);
			c ++;
		}

	}
	
	swap(arr + c, arr + p_idx);

	return c;
}


void quick_sort(int* arr, int l, int r){
	if(l+1 >= r) return;

	int p_idx = partition(arr, l, r);
	

	quick_sort(arr, l, p_idx);
	quick_sort(arr, p_idx+1, r);

	return;
}

int binary_search(int* arr, int key, int l, int r){
	int result = -1;

	while(l < r){
		int m = (l+r) >> 1;
		if(arr[m] == key){
			result = m;
			goto END;
		}
		else if(arr[m] < key){
			l = m+1;
		}
		else{
			r = m;
		}
	
	}
	END:
	return result;
}

int main(){
	
	int card[500001] = { 0, };
	int check[500001] = { 0, };

	int n, m;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		scanf("%d", card+i);
	}

	scanf("%d", &m);

	for(int i = 0; i < m; i ++){
		scanf("%d", check+i);
	}


	quick_sort(card, 0, n);

	for(int i = 0; i < m; i ++){
		int r = binary_search(card, check[i], 0, n);
		printf("%d ", (r!=-1)?1:0);
	}

	return 0;
}
