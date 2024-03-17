#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001];
int highway[13][3]; // 시작위치, 도착위치, 길이

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, d;
    cin >> n >> d;

    for (int i = 1; i <= n; i++){
        cin >> highway[i][0] >> highway[i][1] >> highway[i][2];
    }

    for (int i = 0; i <= d; i++){
        dp[i] = i;
    }

    for (int i = 1; i <= d; i++){
        for (int j = 1; j <= n; j++){
            if (highway[j][1] == i){ // 도착지점이 일치한다면
                if (dp[i] > dp[highway[j][0]]+highway[j][2]){
                    dp[i] = dp[highway[j][0]]+highway[j][2];
                    for (int k = i+1; k <= d; k++){
                        dp[k] = dp[i]+(k-i);
                    }
                }
            }
        }
    }

    cout << dp[d];
}