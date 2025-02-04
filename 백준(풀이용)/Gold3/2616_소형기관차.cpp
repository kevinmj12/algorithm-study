#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int people[50001];
int dp[50001][4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> people[i];
    }
    cin >> m;

    for (int i = m; i <= n; i++){
        for (int j = i-m+1; j <= i; j++){
            dp[i][0] += people[j];
        }
    }
    
    // base case
    dp[m][1] = dp[m][0];
    dp[m][2] = 0;
    dp[m][2] = 0;

    for (int i = m+1; i <= n; i++){
        // 객차가 한 개일 때 max 판단
        dp[i][1] = max(dp[i-1][1], dp[i][0]);
        // 객차가 두 개일 때 max 판단
        if (2*m <= i){
            dp[i][2] = max(dp[i-1][2], dp[i-m][1]+dp[i][0]);
        }
        // 객차가 세 개일 때 max 판단
        if (3*m <= i){
            dp[i][3] = max(dp[i-1][3], dp[i-m][2]+dp[i][0]);
        }
    }

    cout << dp[n][3] << endl;
}