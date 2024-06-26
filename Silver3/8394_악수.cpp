#include <iostream>
using namespace std;

#define MAX 10000001
int dp[MAX];

int main(){
    int n;
    cin >> n;

    // base case
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10;
    }

    cout << dp[n];
}