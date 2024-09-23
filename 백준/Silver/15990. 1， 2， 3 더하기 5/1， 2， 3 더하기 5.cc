#include <iostream>
using namespace std;

#define MAX 100000
#define MOD 1000000009

int dp[MAX+1][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // base case
    dp[1][1] = 1; // 1
    dp[2][2] = 1; // 2
    dp[3][1] = 1; // 2+1
    dp[3][2] = 1; // 1+2
    dp[3][3] = 1; // 3

    for (int i = 4; i <= MAX; i++){
        dp[i][1] += (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] += (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] += (dp[i-3][1] + dp[i-3][2]) % MOD;
    }


    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        int answer = (dp[n][1] + dp[n][2])%MOD;
        answer = (answer + dp[n][3]) % MOD;
        cout << answer << "\n";
    }
}