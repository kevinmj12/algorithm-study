#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n;
int graph[501][501];
int dp[501][501];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void init(){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = -1;
        }
    }
}

// dfs
int solve(int y, int x){
    // 목적지에 도착한 경우
    if (y == 1 && x == 1){
        return 1;
    }
    // 메모이제이션
    if (dp[y][x] != -1){
        return dp[y][x];
    }

    dp[y][x] = 0;
    for (int i = 0; i < 4; i++){
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];

        if (nextY < 1 || nextY > m || nextX < 1 || nextX > n
        || graph[y][x] >= graph[nextY][nextX]){
            continue;
        }
        else {
            dp[y][x] += solve(nextY, nextX);
        }
    }
    return dp[y][x];
}

int main(){
    cin >> m >> n;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }
    
    init();
    solve(m, n);

    cout << dp[m][n];
}