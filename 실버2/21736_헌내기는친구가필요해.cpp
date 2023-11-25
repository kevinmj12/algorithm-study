#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 600
char map[MAX][MAX];
int visited[MAX][MAX];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solve(int y, int x, int n, int m){
    int ans = 0;
    queue<pair<int, int>> order;
    order.push({y,x});
    visited[y][x] = 1;

    while (!order.empty()){
        int yy = order.front().first;
        int xx = order.front().second;
        for (int i = 0; i < 4; i++){
            int nextY = yy + dir[i][0];
            int nextX = xx + dir[i][1];
            if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && !visited[nextY][nextX]){
                char c = map[nextY][nextX];
                if (c == 'P'){
                    ans++;
                    order.push({nextY, nextX});
                    visited[nextY][nextX] = 1;
                }
                else if (c == 'O'){
                    order.push({nextY, nextX});
                    visited[nextY][nextX] = 1;
                }
            }
        }
        order.pop();
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int doY, doX;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
            if (map[i][j] == 'I'){
                doY = i; doX = j;
            }
            visited[i][j] = 0;
        }
    }
    int answer = solve(doY, doX, N, M);
    if (answer) cout << answer;
    else cout << "TT";
}