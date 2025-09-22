#include <iostream>
using namespace std;

#define MOD 1000000000
#define MAX_MASK 1023

// dp[자릿수][끝자리 수][비트마스킹]
int dp[101][10][MAX_MASK+1];


int solve(int n){
    // base case: 자릿수가 1인 경우 채워주기 (0은 불가능)
    for (int j = 1; j <= 9; j++){
        dp[1][j][1 << j] = 1;
    }

    // dp 테이블 채워나가기
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= 9; j++){
            for (int k = 1; k <= MAX_MASK; k++){
                if (j == 0){
                    dp[i+1][1][k | 1] += dp[i][j][k];
                    dp[i+1][1][k | 1] %= MOD;
                }
                else if (j == 9){
                    dp[i+1][8][k | (1 << 8)] += dp[i][j][k];
                    dp[i+1][8][k | (1 << 8)] %= MOD;
                }
                else{
                    dp[i+1][j+1][k | (1 << (j+1))] += dp[i][j][k];
                    dp[i+1][j+1][k | (1 << (j+1))] %= MOD;

                    dp[i+1][j-1][k | (1 << (j-1))] += dp[i][j][k];
                    dp[i+1][j-1][k | (1 << (j-1))] %= MOD;
                }
            }
        }
    }

    int rtn = 0;
    for (int j = 0; j <= 9; j++){
        rtn += dp[n][j][MAX_MASK];
        rtn %= MOD;
    }
    
    return rtn;
}

int main(){
    int N;
    cin >> N;

    cout << solve(N);
}