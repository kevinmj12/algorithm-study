#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
int stickers[MAX][2];
int dp[MAX][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tCase;
    cin >> tCase;
    while (tCase--){
        int n;
        cin >> n;
        
        for (int i = 0; i <= 1; i++){
            for (int j = 1; j <= n; j++){
                cin >> stickers[j][i];
            }
        }

        // dp에는 각 스티커를 떼어냈을 때 최댓값을 저장함.
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = stickers[1][0];
        dp[1][1] = stickers[1][1];

        for (int i = 2; i <= n; i++){
            dp[i][0] = stickers[i][0] + max(dp[i-1][1], dp[i-2][1]);
            dp[i][1] = stickers[i][1] + max(dp[i-1][0], dp[i-2][0]);
        }
        
        cout << max(dp[n][0], dp[n][1]) << "\n";
    }
}