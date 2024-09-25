#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using pair = std::pair<int, int>;
using std::min, std::max;

constexpr int N = 501;

struct block{
	pair origin[4];
	pair p[4];
	int rotate, flip;
};

void rotate(pair& p){
	//rotate pi/2
	auto [x, y] = p;
	p = {-y, x};
}

void flip(pair& p){
	auto [x, y] = p;
	p = {x, -y};
}

void calc_p(block& b){
	int mx = 0, my = 0;
	for(auto [x, y]: b.origin){
		mx = min(x, mx);
		my = min(y, my);
	}
	for(int i = 0; i < 4; i ++){
		auto [x, y] = b.origin[i];
		b.p[i] = {x-mx, y-my};
	}
}

bool isin(int n, int m, int x, int y){
	return (0 <= x && x < n) && (0 <= y && y < m);
}

int main(){
	block J{{{0, 0}, {1, 0}, {1, 1}, {1, 2}}, {}, 4, 1};
	block S{{{0, 0}, {1, 0}, {1, 1}, {2, 1}}, {}, 4, 1};
	block O{{{0, 0}, {1, 0}, {0, 1}, {1, 1}}, {}, 1, 0};
	block I{{{0, 0}, {1, 0}, {2, 0}, {3, 0}}, {}, 2, 0};
	block T{{{0, 0}, {1, 0}, {2, 0}, {1, 1}}, {}, 4, 0};

	vector<block> v{J, S, O, I, T};

	int n, m, result = 0;
	int field[N][N] = { 0, };
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			scanf("%d", field[i]+j);
	
	for(auto& b: v){
		for(int fc = 0; fc <= b.flip; fc ++){
			for(int rc = 0; rc < b.rotate; rc ++){
				calc_p(b);

				for(int i = 0; i < n; i ++){
					for(int j = 0; j < m; j ++){
						int tmp = 0;
						for(auto [x, y]: b.p){
							if(isin(n, m, i+x, j+y) == false){ 
								tmp = 0;
								break;
							}
							tmp += field[i+x][j+y];
						}
						result = max(result, tmp);
					}
				}
				
				for(auto& p: b.origin) rotate(p);
			}
			for(auto& p: b.origin) flip(p);
		}
	}
	


	printf("%d\n", result);
	return 0;
}
