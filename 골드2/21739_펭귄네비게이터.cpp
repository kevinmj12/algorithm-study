#include <iostream>
using namespace std;

#define MAX 10001
#define DIV 1000000007
long long dp[MAX][MAX];

int main(){
    int N;
    cin >> N;

    // base case
    for (int i = 0; i <= N; i++){
        dp[i][0] = 1;
    }
        
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= i; j++){
            if (i != j){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % DIV;
            }
            else{
                dp[i][j] = dp[i][j-1] ;
            }
        }
    }

    cout << dp[N][N];
}