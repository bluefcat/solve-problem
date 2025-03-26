#include <cstdio>

constexpr int N = 202;

int main(){

    int T;
    int n1, n2;
    int s1, s2;

    int remain[N][N] = { 0, };
    int count[N][N] = { 0, };

    scanf(
        "%d %d %d %d %d", 
        &T, &n1, &n2, &s1, &s2
    );

	if(s1 > s2){
		int tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

    for(int i = 1; i <= n1; i ++){
        int flag = remain[i-1][0] < s1;
        count[i][0] = count[i-1][0] + flag;
        if(flag) remain[i][0] = T * flag - s1;
        else remain[i][0] = remain[i-1][0] - s1;
    }

    for(int j = 1; j <= n2; j ++){
        int flag = remain[0][j-1] < s2;
        count[0][j] = count[0][j-1] + flag;
        if(flag) remain[0][j] = T * flag - s2;
        else remain[0][j] = remain[0][j-1] - s2;
    }

    for(int i = 1; i <= n1; i ++){
        for(int j = 1; j <= n2; j ++){
            if(remain[i][j-1] >= s2){
                count[i][j] = count[i][j-1];
                remain[i][j] = remain[i][j-1] - s2;
            }
            else if(remain[i-1][j] >= s1){
                count[i][j] = count[i-1][j];
                remain[i][j] = remain[i-1][j] - s1;
            }
            else if(count[i-1][j] < count[i][j-1]){
                count[i][j] = count[i-1][j] + 1;
                remain[i][j] = T - s1;
            }
            else if(count[i-1][j] > count[i][j-1]){
                count[i][j] = count[i][j-1] + 1;
                remain[i][j] = T - s2;
            }
            else{
                int idx = i-1, jdx = j, t = s1;
                
                if(s1 > s2){
                    idx = i, jdx = j-1, t = s2;
                }
                count[i][j] = count[idx][jdx] + 1;
                remain[i][j] = T - t;
            }
        }
    }

    printf("%d\n", count[n1][n2]);

    return 0;
}
