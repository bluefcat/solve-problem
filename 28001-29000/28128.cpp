#include <cstdio>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::string;

constexpr int N = 1001;
constexpr int S = 22;
unordered_map<string, int> mapper{};
unordered_map<int, string> recover{};

unordered_set<int> result{};

int field[N][N] = { 0, };

int main(){
	int n, m;		
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			char tmp[S] = { 0, };
			scanf("%s", tmp);

			string key{tmp};
			if(mapper[key] == 0) {
				recover[mapper.size()] = key;
				mapper[key] = mapper.size();
			}
			field[i][j] = mapper[key];
		}
	}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			bool flag = false;
			//(1, 2)
			if(j < m-1){
				flag |= field[i][j] == field[i][j+1];
			}
			//(1, 3)
			if(j < m-2){
				flag |= field[i][j] == field[i][j+2];
			}
			//(2, 1)
			if(i < n-1){
				flag |= field[i][j] == field[i+1][j];
			}
			//(3, 1)
			if(i < n-2){
				flag |= field[i][j] == field[i+2][j];
			}

			if(flag)
				result.insert(field[i][j]);
		}
	}

	if(result.size() == 0){
		printf("MANIPULATED\n");
		return 0;
	}

	vector<string> a{};

	for(auto& x: result) a.push_back(recover[x]);

	std::sort(a.begin(), a.end());

	for(auto& x: a){
		printf("%s\n", x.c_str());
	}

	return 0;
}
