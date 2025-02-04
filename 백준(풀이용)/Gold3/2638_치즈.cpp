#include <iostream>
#include <queue>
using namespace std;

int n, m;
int graph[101][101];
bool visited[101][101];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int cheeseCnt = 0;

void resetVisited(int n, int m){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            visited[i][j] = false;
        }
    }
}

void bfs(){
    resetVisited(n, m);
    queue<pair<int, int>> que;
    que.push({1, 1});
    que.push({1, n});
    que.push({n, 1});
    que.push({n, n});
    visited[1][1] = true;
    visited[1][n] = true;
    visited[n][1] = true;
    visited[n][n] = true;

    while (!que.empty()){
        int curY = que.front().first;
        int curX = que.front().second;

        que.pop();

        for (int i = 0; i < 4; i++){
            int nextY = curY+dir[i][0];
            int nextX = curX+dir[i][1];

            if (1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m){
                int trg = graph[nextY][nextX];
                // 치즈가 없는 공간일 경우
                if (trg == 0){
                    if (!visited[nextY][nextX]){
                        que.push({nextY, nextX});
                        visited[nextY][nextX] = true;
                    }
                }
                // 치즈가 있을 경우
                else{
                    graph[nextY][nextX]++;
                }
            }
        }
    }

    // 치즈의 값이 3 이상일 경우 두 면 이상이 접촉, 제거
    // 치즈의 값이 2인 경우 한 면이 접촉, 원래인 1로 되돌림
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (graph[i][j] >= 3){
                graph[i][j] = 0;
                cheeseCnt--;
            }
            else if (graph[i][j] == 2){
                graph[i][j] = 1;
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 1){
                cheeseCnt++;
            }
        }
    }
    int answer = 0;    
    while (cheeseCnt){
        bfs();
        answer++;
    }
    cout << answer;
}