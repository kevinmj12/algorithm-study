#include <string>
#include <vector>
#include <iostream>
#define MOD 10007

using namespace std;


int dp[100001][2];

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    // base case
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++){
        int cases = 1;
        if (tops[i-1] == 1){
            cases = 2;
        }
        
        int triangle = dp[i-1][0];
        int diamond = dp[i-1][1];

        dp[i][0] = ((triangle + diamond) * cases + triangle) % MOD;
        dp[i][1] = (triangle + diamond) % MOD;        
    }
    
    answer = (dp[n][0] + dp[n][1]) % MOD;
    
    
    return answer;
}