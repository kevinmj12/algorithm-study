#include <iostream>
using namespace std;

int graph[17][17];
int dp[17][17][3];

int main(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }

    // dp[i][j][0]은 가로 방향 파이프
    // dp[i][j][1]은 세로 방향 파이프
    // dp[i][j][2]은 대각선 방향 파이프

    // base case
    dp[1][2][0] = 1;

    for (int i = 1; i <= n; i++){
        for (int j = 2; j <= n; j++){
            // 벽이 아니라면
            if (!graph[i][j]){
                // 가로 방향 추가
                dp[i][j][0] += dp[i][j-1][0] + dp[i][j-1][2];
                // 세로 방향 추가
                dp[i][j][1] += dp[i-1][j][1] + dp[i-1][j][2];
                // 대각선 방향 추가
                if (!graph[i-1][j] && !graph[i][j-1]){
                    dp[i][j][2] = dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
                }
            }
        }
    }

    cout << dp[n][n][0]+dp[n][n][1]+dp[n][n][2];

}