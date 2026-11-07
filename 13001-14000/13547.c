#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMAX 100001
int n;
void add(int* count, int num, int* result){
    count[num] ++;
    if(count[num] == 1) (*result) ++;
}

void earse(int* count, int num, int* result){
    count[num] --;
    if(count[num] == 0) (*result) --;
}

int query(int* arr, int q[][3], int size, int* answer){
    int result = 0;

    int low = 0;
    int high = 0;

    int count[1000001] = { 0, };

    add(count, arr[0], &result);

    for(int i = 0; i < size; i ++){
        int next_low = q[i][0];
        int next_high = q[i][1];

        for(int i = low; i < next_low; i ++) earse(count, arr[i], &result);
        for(int i = low-1; i >= next_low; i --) add(count, arr[i], &result);
        
        for(int i = high+1; i <= next_high; i ++) add(count, arr[i], &result);
        for(int i = high; i > next_high; i--) earse(count, arr[i], &result);

        low = next_low;
        high = next_high;

        answer[q[i][2]] = result;
    }
    
}

int compare(const void* x, const void* y){
    int size = sqrt(n);
    int* left = (int*)x;
    int* right = (int*)y;
    int left_index = left[1] / size;
    int right_index = right[1] / size;

    return left_index == right_index ? left[0] < right[0] : left_index < right_index;
}

int main(){
    int arr[NMAX] = { 0, };
    int m;

    int q[NMAX][3];
    int answer[NMAX] = { 0, };


    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", arr+i);

    scanf("%d", &m);
    for(int i = 0; i < m; i ++){
        scanf("%d %d", q[i], q[i] + 1); 
        q[i][2] = i;
        q[i][0] --; q[i][1] --;
    } 

    qsort(q, m, sizeof(int) * 3, compare);
    query(arr, q, m, answer);

    for(int i = 0; i < m; i ++){
        printf("%d\n", answer[i]);
    }
    
    return 0;
}