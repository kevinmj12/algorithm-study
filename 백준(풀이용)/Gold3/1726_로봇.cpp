#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool graph[101][101];
bool visited[101][101][4];
int n, m;
int startY, startX, startDir;
int endY, endX, endDir;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
queue<vector<int>> q;

bool judge(int y, int x, int dir){
    if (1 <= y && y <= n && 1 <= x && x <= m 
    && !visited[y][x][dir] && !graph[y][x]){
        return true;
    }
    return false;
}

void solve(){
    q.push({startY, startX, startDir});
    visited[startY][startX][startDir] = true;
    int cnt = 0;
    while (!q.empty()){
        int pqSize = q.size();
        for (int i = 0; i < pqSize; i++){
            // 현재 로봇의 정보를 저장
            int curY = q.front()[0];
            int curX = q.front()[1];
            int curDir = q.front()[2];
            if (curY == endY && curX == endX && endDir == curDir){
                cout << cnt;
                return;
            }
            q.pop();
            // Go k 조사
            for (int k = 1; k <= 3; k++){
                int nextY = curY+dir[curDir][0]*k;
                int nextX = curX+dir[curDir][1]*k;
                if (1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m 
                && !visited[nextY][nextX][curDir]){
                    if (!graph[nextY][nextX]){
                        q.push({nextY, nextX, curDir});
                        visited[nextY][nextX][curDir] = true;
                    }
                    else{
                        break;
                    }
                }
            }
            // Turn dir 조사
            for (int j = 0; j < 4; j++){
                if (j == curDir || (j+curDir)%4 == 1){
                    continue;
                }
                if (judge(curY, curX, j)){
                    q.push({curY, curX, j});
                    visited[curY][curX][j] = true;
                }
            }
        }
        cnt++;
    }
}

int main(){
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> graph[i][j];
        }
    }
    cin >> startY >> startX >> startDir;
    cin >> endY >> endX >> endDir;
    startDir--;
    endDir--;

    solve();
}   