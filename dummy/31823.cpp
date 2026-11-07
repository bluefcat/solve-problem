#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;

int main(){
    unordered_map<int, bool> c;
    std::vector<std::pair<string, int>> a;
    int n, m, kind = 0;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i ++){
        bool flag = false;
        int result = 0;
        int stric = 0;
        for(int j = 0; j < m; j ++){
            char tmp;
            scanf(" %c", &tmp);
            if(tmp == '.'){
                stric ++;
                flag = true; 
            }
            else{
                result = std::max(result, stric);
                stric = 0;
                flag = false;
            }
        }
        result = std::max(result, stric);
        char name[21] = { 0, };
        if(c[result] == false){
            kind ++;
            c[result] = true;
        }

        scanf("%s", name);
        a.push_back({name ,result});
    }

    printf("%d\n", kind);
    for(auto& [n, st]: a){
        printf("%d %s\n", st, n.c_str());
    }


    return 0;
}