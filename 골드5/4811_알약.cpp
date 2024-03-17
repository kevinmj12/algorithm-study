#include <iostream>
using namespace std;

#define MAX 31
long long dp[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // base case
    for (int i = 0; i <= 30; i++){
        dp[i][0] = 1;
    }
        
    for (int i = 1; i <= 30; i++){
        for (int j = 1; j <= i; j++){
            if (i != j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }


    while (true){
        int n;
        cin >> n;

        if (n == 0){
            break;
        }
        else{
            cout << dp[n][n] << "\n";
        }
    }
}