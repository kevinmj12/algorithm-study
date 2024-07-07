#include <iostream>
#include <vector>
using namespace std;

char map[1001][1001];
bool visited[1001][1001];
int answer = 0;

void dfs(int y, int x, vector<pair<int, int>> vec){
    // 이미 방문한 적 있는 칸이라면
    if (visited[y][x]){
        // 이동해온 경로 중 하나로 다시 이동했다면 SAFE ZONE 추가
        for (int i = 0; i < vec.size(); i++){
            if (y == vec[i].first && x == vec[i].second){
                answer++;
                break;
            }
        }
        return;
    }
    visited[y][x] = true;
    vec.push_back({y, x});
    // 지도에 써있는 정보에 따라 이동
    if (map[y][x] == 'U'){
        dfs(y-1, x, vec);
    }
    else if (map[y][x] == 'D'){
        dfs(y+1, x, vec);
    }
    else if (map[y][x] == 'R'){
        dfs(y, x+1, vec);
    }
    else if (map[y][x] == 'L'){
        dfs(y, x-1, vec);
    }
}   

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){            
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (!visited[i][j]){
                dfs(i, j, {});
            }
        }
    }

    cout << answer;
}