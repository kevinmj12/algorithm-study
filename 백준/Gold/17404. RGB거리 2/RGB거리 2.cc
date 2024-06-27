#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 1000000

int costs[1001][3];
int dp[1001][3][3];

void init(int n){
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                dp[i][j][k] = MAX;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    init(n);

    // costs[a][b]는 a번 집을 b색으로 칠하는 비용
    // b가 0이면 빨강, 1이면 초록, 2면 파랑
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 3; j++){
            cin >> costs[i][j];
        }
    }

    // base case
    // dp[a][b][c]는 1번 집의 색이 c일 때 a번 집을 b색으로 칠하는 비용
    dp[1][0][0] = costs[1][0];
    dp[1][1][1] = costs[1][1];    
    dp[1][2][2] = costs[1][2];
    
    // 2~n-1번 집까지 칠하는 비용 계산
    for (int i = 2; i <= n-1; i++){
        // i번 집을 빨강으로 칠할 때
        // 1번 집이 빨강인 경우
        dp[i][0][0] = min(dp[i-1][1][0], dp[i-1][2][0]) + costs[i][0];
        // 1번 집이 초록인 경우
        dp[i][0][1] = min(dp[i-1][1][1], dp[i-1][2][1]) + costs[i][0];
        // 1번 집이 파랑인 경우
        dp[i][0][2] = min(dp[i-1][1][2], dp[i-1][2][2]) + costs[i][0];
        
        // i번 집을 초록으로 칠할 때
        dp[i][1][0] = min(dp[i-1][0][0], dp[i-1][2][0]) + costs[i][1];
        dp[i][1][1] = min(dp[i-1][0][1], dp[i-1][2][1]) + costs[i][1];
        dp[i][1][2] = min(dp[i-1][0][2], dp[i-1][2][2]) + costs[i][1];

        // i번 집을 파랑으로 칠할 때
        dp[i][2][0] = min(dp[i-1][0][0], dp[i-1][1][0]) + costs[i][2];
        dp[i][2][1] = min(dp[i-1][0][1], dp[i-1][1][1]) + costs[i][2];
        dp[i][2][2] = min(dp[i-1][0][2], dp[i-1][1][2]) + costs[i][2];
    }
    // n번 집 칠하는 비용 계산
    int answer = MAX;
    for (int i = 0; i < n; i++){
        // n번 집을 빨강으로 칠하는 경우
        answer = min(answer, dp[n-1][1][1]+costs[n][0]);
        answer = min(answer, dp[n-1][1][2]+costs[n][0]);
        answer = min(answer, dp[n-1][2][1]+costs[n][0]);
        answer = min(answer, dp[n-1][2][2]+costs[n][0]);
        // n번 집을 초록으로 칠하는 경우
        answer = min(answer, dp[n-1][0][0]+costs[n][1]);
        answer = min(answer, dp[n-1][0][2]+costs[n][1]);
        answer = min(answer, dp[n-1][2][0]+costs[n][1]);
        answer = min(answer, dp[n-1][2][2]+costs[n][1]);
        // n번 집을 파랑으로 칠하는 경우
        answer = min(answer, dp[n-1][0][0]+costs[n][2]);
        answer = min(answer, dp[n-1][0][1]+costs[n][2]);
        answer = min(answer, dp[n-1][1][0]+costs[n][2]);
        answer = min(answer, dp[n-1][1][1]+costs[n][2]);
    }
    cout << answer;
}