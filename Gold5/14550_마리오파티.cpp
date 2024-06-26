#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 202
int board[MAX];
int dp[MAX][MAX+1];

void reset(int n, int t){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= t; j++){
            dp[i][j] = -1000000000;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true){
        int N;
        cin >> N;

        if (N == 0){
            return 0;
        }

        int S, T;
        cin >> S >> T;


        reset(N, T);

        for (int i = 1; i <= N; i++){
            cin >> board[i];
        }

        // base case
        for (int i = 1; i <= S; i++){
            dp[i][1] = board[i];
        }
        
        // 도착점 전까지의 최댓값 탐색
        for (int i = 2; i <= N; i++){
            for (int j = max(1, i-S); j < i; j++){
                for (int k = 1; k < T-1; k++){
                    dp[i][k+1] = max(dp[i][k+1], dp[j][k]+board[i]);
                }
            }
        }

        // 도착점에서의 최댓값 탐색
        int answer = INT_MIN;
        for (int j = max(1, N-S+1); j <= N; j++){
            for (int k = 1; k < T; k++){
                answer = max(answer, dp[j][k]);
            }
        }

        cout << answer << "\n";
    }
}
