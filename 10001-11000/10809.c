#include <stdio.h>

char string[102];

int main(){
    int result[26] = { 0, };
    for(int i = 0; i < 26; i ++) result[i] = -1;
    scanf("%s", string);
    
    int idx = 0;
    char* tmp = string;
    while(*tmp){
        int i = (int)(*tmp-'a');
        if(result[i] == -1) result[i] = idx;
        idx ++;
        tmp ++;
    }
    
    for(int i = 0; i < 26; i ++){
        printf("%d ", result[i]);
    }
    printf("\n");
    
    return 0;
}