#include <cstdio>
#include <vector>

constexpr int N = 500'001;
constexpr int M = 11;
int prime[N];
std::vector<int> p{};
bool used[2*N+3];

int board[M*M][M*M];

void build_sieve(){
	for(int i = 0; i < N; i ++) prime[i] = -1;
	int idx = 3;
	int k = 3;
	for(int i = 0; idx < N; i ++){
		if(prime[i] == -1){ //2*i+3
			prime[idx] = i;
			for(int j = idx; N - j > k; j += k){
				prime[j] = i;
			}
		}
		idx += k;
		k += 2;
		idx += k;
	}
}

int main(){
	build_sieve();
	p.emplace_back(2);
	for(int pi = 0; pi < N; pi ++)
		if(prime[pi] == -1) p.emplace_back(2*pi+3);

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n*n; i ++){
		for(int j = 0; j < n*n; j ++){
			int tmp;
			scanf("%d", &tmp);
			board[i][j] = tmp;
			if(tmp == 0) continue;
			while(tmp != 1){
				if((tmp & 1) == 0){
					tmp /= 2;
					used[2] = true;
					continue;
				}
				int pi = prime[tmp];
				if(pi == -1){
					used[tmp] = true;
					break;
				}
				used[2*pi+3] = true;
				tmp /= (2*pi+3);
			}
		}
	}
	
	int last = 0;
	for(; last < p.size(); last ++) 
		if(!used[p[last]]) break;

	for(int i = 0; i < n*n; i ++){
		for(int j = 0; j < n*n; j ++){
			if(board[i][j] != 0 ) continue;
			board[i][j] = p[last];
			used[p[last]] = true;
			for(; last < p.size(); last ++){
				if(!used[p[last]]) break;
			}
		}
	}	
	
	for(int i = 0; i < n*n; i ++){
		for(int j = 0; j < n*n; j ++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}


	return 0;
}
