#include <stdio.h>
#include <string.h>

#define N 1001
#define MAX_LENGTH 21

int idx = 1;
char dance[N][MAX_LENGTH];

int find_name(const char* name){
    for(int i = 0; i < idx; i ++){
        if(strcmp(name, dance[i]) == 0) return i;
    }
    return -1;
}

int main(){
    strcpy(dance[0], "ChongChong");

    int n = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i ++){
        char dest[MAX_LENGTH] = { 0, };
        char src[MAX_LENGTH] = { 0, };
        scanf("%s %s", dest, src);

        int src_idx = find_name(src);
        int dest_idx = find_name(dest);

        if((src_idx != -1) && (dest_idx == -1))
            strcpy(dance[idx++], dest);

        if((dest_idx != -1) && (src_idx == -1))
            strcpy(dance[idx++], src);
    }


    printf("%d\n", idx);
}