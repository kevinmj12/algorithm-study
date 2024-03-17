#include <iostream>
using namespace std;

#define MAX 101
int dp[MAX][MAX];

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= MAX; i++){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    // 이항계수 표 작성
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = min(dp[i-1][j] + dp[i][j-1], 1000000001);
        }
    }

    if (dp[n][m] < k){
        cout << -1;
    }
    else{
        while (n > 0 && m > 0){
            int tmp = dp[n-1][m];

            if (k <= tmp){
                cout << 'a';
                n--;
            }
            else{
                cout << 'z';
                m--;
                k -= tmp;
            }
        }

        for (int i = 0; i < n; i++){
            cout << 'a';
        }
        for (int i = 0; i < m; i++){
            cout << 'z';
        }
    }
}