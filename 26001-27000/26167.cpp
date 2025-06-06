#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using pair = std::pair<int, int>;
using std::min, std::max;

constexpr int N = 501;
constexpr int B = 6;

struct block{
	pair origin[B];
	pair p[B];
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
	for(int i = 0; i < B; i ++){
		auto [x, y] = b.origin[i];
		b.p[i] = {x-mx, y-my};
	}
}

bool isin(int n, int m, int x, int y){
	return (0 <= x && x < n) && (0 <= y && y < m);
}

int main(){
	block I0{{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}}, {}, 2, 0};
	block I1{{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {4, 1}}, {}, 4, 1};
	block I2{{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {3, 1}}, {}, 4, 1};
	block I3{{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {2, 1}}, {}, 4, 0};
	block S0{{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {3, 1}, {4, 1}}, {}, 4, 1};
	block S1{{{0, 0}, {1, 0}, {2, 0}, {2, 1}, {3, 1}, {4, 1}}, {}, 2, 1};
	block P0{{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {2, 1}, {3, 1}}, {}, 4, 1};

	block F0{{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {1, 1}, {3, 1}}, {}, 4, 1};
	block C0{{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {0, 1}, {3, 1}}, {}, 4, 0};
	block D0{{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {1, 1}, {2, 1}}, {}, 4, 0};
	block L0{{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {3, 1}, {3, 2}}, {}, 4, 1};
	block L1{{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {2, 1}, {2, 2}}, {}, 4, 1};
	block T0{{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {3, 0}, {3, 2}}, {}, 4, 0};
	block T1{{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {2, 0}, {3, 2}}, {}, 4, 1};

	block T2{{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {1, 0}, {3, 2}}, {}, 4, 1};
	block T3{{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {0, 0}, {3, 2}}, {}, 2, 1};
	block T4{{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {1, 0}, {2, 2}}, {}, 2, 1};
	block T5{{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {2, 0}, {2, 2}}, {}, 4, 0};
	block T6{{{0, 2}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {3, 1}}, {}, 4, 1};
	block T7{{{0, 1}, {1, 1}, {2, 1}, {0, 0}, {2, 0}, {3, 0}}, {}, 4, 1};
	block S2{{{0, 1}, {1, 1}, {2, 1}, {1, 0}, {2, 0}, {3, 0}}, {}, 4, 1};


	block T8{{{0, 1}, {1, 1}, {2, 1}, {2, 0}, {3, 0}, {2, 2}}, {}, 4, 1};
	block T9{{{0, 1}, {1, 1}, {2, 1}, {2, 0}, {3, 0}, {1, 2}}, {}, 4, 1};
	block W0{{{0, 2}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {3, 0}}, {}, 4, 1};
	block W1{{{0, 2}, {1, 2}, {2, 2}, {2, 1}, {3, 1}, {3, 0}}, {}, 4, 1};
	block W2{{{0, 2}, {1, 2}, {1, 1}, {2, 1}, {3, 1}, {3, 0}}, {}, 4, 1};
	block W3{{{0, 2}, {1, 2}, {1, 1}, {2, 1}, {2, 0}, {3, 0}}, {}, 4, 1};
	block O0{{{0, 1}, {1, 1}, {2, 1}, {0, 0}, {1, 0}, {2, 0}}, {}, 2, 0};

	block Y0{{{0, 1}, {1, 1}, {2, 1}, {2, 0}, {1, 2}, {2, 2}}, {}, 4, 1};
	block Y1{{{0, 2}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {1, 0}}, {}, 4, 1};
	block Y2{{{0, 2}, {1, 2}, {2, 2}, {1, 1}, {2, 0}, {1, 0}}, {}, 4, 1};
	block Y3{{{0, 1}, {1, 2}, {2, 2}, {1, 1}, {2, 0}, {1, 0}}, {}, 4, 0};
	block ST{{{0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 1}, {0, 2}}, {}, 4, 1};
	block FI{{{0, 0}, {1, 0}, {0, 1}, {1, 1}, {2, 1}, {1, 2}}, {}, 4, 1};
	block Q0{{{0, 0}, {1, 0}, {0, 1}, {1, 1}, {2, 1}, {2, 2}}, {}, 4, 1};

	vector<block> v{
		I0, I1, I2, I3, S0, S1, P0, 
		F0, C0, D0, L0, L1, T0, T1,
		T2, T3, T4, T5, T6, T7, S2,
		T8, T9, W0, W1, W2, W3, O0,
		Y0, Y1, Y2, Y3, ST, FI, Q0
	};
	/*
	int idx = 0;
	for(auto& b: v){
		char field[6][6] = { 0, };
		for(auto [x, y]: b.origin){
			field[x][y] = 1;
		}
		printf("--[%d]--\n", idx);
		for(int i = 0; i < 6; i ++){
			for (int j = 0; j < 6; j ++){
				printf("%c", field[i][j]?'#':' ');
			}
			printf("\n");
		}
	}
	return 0;
*/

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
