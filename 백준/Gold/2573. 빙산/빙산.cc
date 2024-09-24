#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int graph[300][300];
bool visited[300][300];
int melt[300][300];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void reset(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            visited[i][j] = 0;
            melt[i][j] = 0;
        }
    }
}

int checkSeperated(){
    bool flag = false;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (graph[i][j] > 0 && !visited[i][j]){
                // 첫 번째 덩어리인 경우
                if (!flag){
                    flag = true;
                    queue<pair<int, int>> que;
                    que.push({i, j});
                    visited[i][j] = true;

                    while (!que.empty()){
                        int curY = que.front().first;
                        int curX = que.front().second;
                        que.pop();

                        for (int d = 0; d < 4; d++){
                            int nextY = curY + dir[d][0];
                            int nextX = curX + dir[d][1];

                            if (graph[nextY][nextX] > 0 && !visited[nextY][nextX]){
                                que.push({nextY, nextX});
                                visited[nextY][nextX] = true;
                            }
                        }
                    }
                }
                // 두 번째 덩어리인 경우
                else{
                    return 1;
                }
            }
        }
    }
    // 한 덩어리인 경우
    if (flag){
        return 0;
    }
    // 덩어리가 없는 경우 (전부 다 녹아버림)
    else{
        return -1;
    }
}

void solve(){
    reset();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (graph[i][j] > 0){
                for (int d = 0; d < 4; d++){
                    int nextY = i + dir[d][0];
                    int nextX = j + dir[d][1];

                    if (graph[nextY][nextX] == 0){
                        melt[i][j]++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            graph[i][j] = max(0, graph[i][j] - melt[i][j]);
        }
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    int time = 0;

    while (true){
        solve();
        time++;
        int answer = checkSeperated();
        if (answer == 1){
            cout << time;

            break;
        }
        else if (answer == -1){
            cout << 0;
            break;
        }
    }
}