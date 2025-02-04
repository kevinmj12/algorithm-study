#include <iostream>
#include <climits>
using namespace std;

#define MAX 1001
int cost[MAX][3];
int dp[MAX][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++){
        for (int j = 0; j < 3; j++){
            cin >> cost[i][j];
            dp[i][j] = INT_MAX;
        }
    }

    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];

    for (int i = 2; i <= N; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                if (j != k){
                    dp[i][j] = min(dp[i][j], dp[i-1][k]+cost[i][j]);
                }
            }
        }
    }

    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);
}