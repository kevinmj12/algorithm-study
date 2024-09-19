#include <iostream>
#include <algorithm>
using namespace std;

#define MIN -1000000

int w[1001];
int l[1001];
int dp[1001][1001];

int main(){
    int n, m, k;

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }

    cin >> m;
    for (int j = 1; j <= m; j++){
        cin >> l[j];
    }

    cin >> k;

    // base case
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j] = MIN;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        dp[i][0] = dp[i-1][0] + w[i];
    }
    for (int j = 1; j <= m; j++){
        if (dp[0][j-1] % k == 0){
            dp[0][j] = dp[0][j-1] - l[j];
        }
        else{
            int tmp = dp[0][j-1];
            if (tmp < 0){
                tmp *= -1;
                dp[0][j] = dp[0][j-1] - min(l[j], k - (tmp % k));
            }
            else{
                dp[0][j] = dp[0][j-1] - min(l[j], tmp % k);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j] + w[i]);

            if (dp[i][j-1] % k == 0){
                dp[i][j] = max(dp[i][j], dp[i][j-1]-l[j]);
            }
            else{
                int tmp = dp[i][j-1];
                if (tmp < 0){
                    tmp *= -1;
                    dp[i][j] = max(dp[i][j], dp[i][j-1] - min(l[j], k - (tmp % k)));
                }
                else{
                    dp[i][j] = max(dp[i][j], dp[i][j-1] - min(l[j], tmp % k));
                }
            }
        }
    }

    cout << dp[n][m];
}