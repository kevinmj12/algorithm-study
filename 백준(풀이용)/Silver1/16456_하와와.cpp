#include <iostream>
using namespace std;

#define MOD 1000000009
#define MAX 50001
int dp[MAX];

int main(){
    int n;
    cin >> n;

    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    for (int i = 4; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-3]) % MOD;
    }

    cout << dp[n];
    
}