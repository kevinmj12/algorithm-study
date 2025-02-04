#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int r, c;
int jY, jX;
queue<pair<int, int>> fire;
char graph[1001][1001];
int visited[1001][1001];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void solve(){
    queue<pair<int, int>> jihun;
    jihun.push({jY, jX});
    visited[jY][jX] = true;
    int answer = 0;

    while (!jihun.empty()){
        // 큐의 사이즈를 저장하고 for문을 통해 탈출시간을 관리.
        answer++;
        // 불이 번질 곳으로 이동하면 안되므로 불 먼저 확산
        int fSize = fire.size();
        for (int i = 0; i < fSize; i++){
            int y = fire.front().first;
            int x = fire.front().second;
            fire.pop();
            for (int j = 0; j < 4; j++){
                int nextY = y + dir[j][0];
                int nextX = x + dir[j][1];
                if (0 < nextY && nextY <= r && 0 < nextX && nextX <= c && 
                graph[nextY][nextX] == '.'){
                    graph[nextY][nextX] = 'F';
                    fire.push({nextY, nextX});    
                }
            }
        }
        // 지훈의 다음 경로 처리
        int jSize = jihun.size();
        for (int i = 0; i < jSize; i++){
            int y = jihun.front().first;
            int x = jihun.front().second;
            jihun.pop();
            for (int j = 0; j < 4; j++){
                int nextY = y + dir[j][0];
                int nextX = x + dir[j][1];
                if (nextY <= 0 || r < nextY || nextX <= 0 || c < nextX){
                    cout << answer;
                    return;
                }
                if (!visited[nextY][nextX] && graph[nextY][nextX] == '.'){
                    jihun.push({nextY, nextX});
                    visited[nextY][nextX] = true;
                }
            }

        }
    }
    // while문을 탈출한다면 탈출 실패
    cout << "IMPOSSIBLE";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 'J'){
                graph[i][j] = '.';
                jY= i; jX = j;
            }
            else if (graph[i][j] == 'F'){
                fire.push({i, j});
            }
        }

    }

    solve();
}