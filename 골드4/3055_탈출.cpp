#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int r, c;
int dochiY, dochiX;
queue<pair<int, int>> water;
char graph[51][51];
int visited[51][51];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void solve(){
    queue<pair<int, int>> dochi;
    dochi.push({dochiY, dochiX});
    visited[dochiY][dochiX] = true;
    int answer = 0;

    while (!dochi.empty()){
        // 큐의 사이즈를 저장하고 for문을 통해 탈출시간을 관리.
        answer++;
        // 물이 차오를 곳으로 이동하면 안되므로 물 먼저 진행
        int waterSize = water.size();
        for (int i = 0; i < waterSize; i++){
            int y = water.front().first;
            int x = water.front().second;
            water.pop();
            for (int j = 0; j < 4; j++){
                int nextY = y + dir[j][0];
                int nextX = x + dir[j][1];
                if (0 < nextY && nextY <= r && 0 < nextX && nextX <= c && 
                graph[nextY][nextX] == '.'){
                    graph[nextY][nextX] = 'F';
                    water.push({nextY, nextX});    
                }
            }
        }
        // 고슴도치의 다음 경로 처리
        int dochiSize = dochi.size();
        for (int i = 0; i < dochiSize; i++){
            int y = dochi.front().first;
            int x = dochi.front().second;
            dochi.pop();
            for (int j = 0; j < 4; j++){
                int nextY = y + dir[j][0];
                int nextX = x + dir[j][1];

                if (1 <= nextY && nextY <= r && 1 <= nextX && nextX <= c){
                    if (graph[nextY][nextX] == 'D'){
                        cout << answer;
                        return;
                    }
                    if (!visited[nextY][nextX] && graph[nextY][nextX] == '.'){
                        dochi.push({nextY, nextX});
                        visited[nextY][nextX] = true;
                    }
                }

            }

        }
    }
    // while문을 탈출한다면 물에 빠짐
    cout << "KAKTUS";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 'S'){
                graph[i][j] = '.';
                dochiY= i; dochiX = j;
            }
            else if (graph[i][j] == '*'){
                water.push({i, j});
            }
        }

    }

    solve();
}