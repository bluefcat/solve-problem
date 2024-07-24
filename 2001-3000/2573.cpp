#include <cstdio>
#include <queue>
#define N 301

void print(int* field, int n, int m){
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++)
			printf("%d ", field[i*m+j]); printf("\n");
	}
}

int move_arr[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

int reduce(char* field, int n, int m){
	int result = 0;
	char next_field[N*N] = { 0, };
	for(int i = 0; i < n*m; i++) 
		next_field[i] = field[i];
	bool check[N*N] = { 0, };
	
	std::queue<
		std::pair<int, int>
	> q{};

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(check[i*m+j]) continue;
			if(field[i*m+j] == 0){
				check[i*m+j] = true;
				continue;
			}	
		
			q.push({i, j});
			check[j*m+i] = true;
			while(!q.empty()){
				auto p = q.front();
				int x = p.second; int y = p.first;
				int r = 0;
				for(int k = 0; k < 4; k ++){
					int nx = x + move_arr[k][0];
					int ny = y + move_arr[k][1];

					if(!(0 <= nx && nx < m)) continue;
					if(!(0 <= ny && ny < n)) continue;
					if(field[ny*m+nx] == 0){
						r ++; continue;
					} 
					if(check[ny*m+nx]) continue;
					check[ny*m+nx] = true;
					q.push({ny, nx});
				}
				next_field[y*m+x] = std::max(0, field[y*m+x] - r);
				q.pop();
			}
			result ++;
		}
	}

	for(int i = 0; i < n*m; i ++) 
		field[i] = next_field[i];

	return result;
}

int main(){
	int n, m, result = 0;
	char field[N*N] = { 0, };
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++)
			scanf("%d", field + (i*m+j));
	}
	printf("start\n");
	int piece = 0;
	do{
		piece = reduce(field, n, m);
		if(piece != 1) break;	
		result ++;
	} while(piece != 0);
	printf("%d\n", piece != 0? result: 0);

	return 0;
}
