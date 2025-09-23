#include <string>
#include <vector>
#include <iostream>
#define MOD 10007

using namespace std;


int dp[100001][2];

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    // base case
    if (tops[0] == 0){
        dp[0][0] = 2; dp[0][1] = 1;    
    }
    else{
        dp[0][0] = 3; dp[0][1] = 1;    
    }
    
    for (int i = 1; i < n; i++){
        int cases = 1;
        if (tops[i] == 1){
            cases = 2;
        }
        
        int triangle = dp[i-1][0];
        int diamond = dp[i-1][1];

        dp[i][0] = ((triangle + diamond) * cases + triangle) % MOD;
        dp[i][1] = (triangle + diamond) % MOD;        
    }
    
    answer = (dp[n-1][0] + dp[n-1][1]) % MOD;
    
    
    return answer;
}