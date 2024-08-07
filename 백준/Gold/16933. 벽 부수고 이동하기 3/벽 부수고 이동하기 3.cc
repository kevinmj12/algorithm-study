#include <iostream>
#include <queue>
using namespace std;

char graph[1001][1001];
bool visited[1001][1001][11];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int n, int m, int k){
    queue<vector<int>> que;
    // 일수, 벽, y, x 순으로 저장
    que.push({1, 0, 1, 1});

    while (!que.empty()){
        int date = que.front()[0];
        int walls = que.front()[1];
        int curY = que.front()[2];
        int curX = que.front()[3];

        if (curY == n && curX == m){
            return date;
        }
        que.pop();

        for (int i = 0; i < 4; i++){
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];
            if (nextY < 1 || nextY > n || nextX < 1 || nextX > m){
                continue;
            }
            // 이동할 수 있는 경우
            if (graph[nextY][nextX] == '0' && !visited[nextY][nextX][walls]){
                que.push({date+1, walls, nextY, nextX});
                visited[nextY][nextX][walls] = true;
            }
            // 벽인 경우(부숴야 하는 경우)
            else{
                if (walls < k && !visited[nextY][nextX][walls+1]){
                    // 낮이면 그냥 추가
                    if (date % 2){
                        que.push({date+1, walls+1, nextY, nextX});
                        visited[nextY][nextX][walls+1] = true;
                    }
                    // 밤이면 하루 더 기다림
                    else{
                        que.push({date+1, walls, curY, curX});
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> graph[i][j];
        }
    }

    cout << bfs(n, m, k);
}