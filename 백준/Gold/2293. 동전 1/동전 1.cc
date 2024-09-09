#include <iostream>
#include <algorithm>
using namespace std;

int coins[100];
int dp[10001];

int main(){
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }
    sort(coins, coins+n);

    // base case
    dp[0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = coins[i]; j <= k; j++){
            dp[j] += dp[j-coins[i]];
        }
    }

    cout << dp[k];
}