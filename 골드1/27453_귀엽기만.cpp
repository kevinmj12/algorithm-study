#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
#define MAX 1001
char town[MAX][MAX];
bool visited[MAX][MAX][4];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int homeY, int homeX){
    queue<vector<int>> q; // {y좌표, x좌표, 불상사1, 불상사2, 불상사3, 온 방향, 거리}
    int answer = -1;

    q.push({homeY, homeX, 0, 0, 0, 100, 0});
    visited[homeY][homeX][0] = true;
    visited[homeY][homeX][1] = true;
    visited[homeY][homeX][2] = true;
    visited[homeY][homeX][3] = true;

    while (!q.empty()){
        int preY = q.front()[0];
        int preX = q.front()[1];
        int preK1 = q.front()[2];
        int preK2 = q.front()[3];
        int preK3 = q.front()[4];
        int preD = q.front()[5];
        int preA = q.front()[6];
        q.pop();
 
        for (int i = 0; i < 4; i++){
            if (abs(preD-i) != 2){
                int nextY = preY + dir[i][0];
                int nextX = preX + dir[i][1];
                
                if (!visited[nextY][nextX][i] && 0 < nextY && nextY <= n && 0 < nextX && nextX <= m){
                    if (town[nextY][nextX] == 'S'){
                        if (answer == -1){
                            answer = preA+1;
                        }
                        else{
                            answer = min(answer, preA+1);
                        }
                    }
                    else if (town[nextY][nextX] != 'X' && preK2+preK3+(town[nextY][nextX]-'0') <= k){
                        q.push({nextY, nextX, preK2, preK3, (town[nextY][nextX]-'0'), i, preA+1});
                        visited[nextY][nextX][i] = true;
                    }
                }

                
            }
        }
        

    }

    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    int a, b, c, d;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> town[i][j];

            if (town[i][j] == 'H'){
                a = i; b = j;
            }
        }
    }

    int ans = bfs(a, b);

    cout << ans;
}