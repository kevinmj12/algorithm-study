#include <iostream>
using namespace std;
#define MAX 101
#define DIV 1000000000
// 마지막 수가 같은 계단 수들의 개수를 세어 저장
int dp[MAX][10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    // 길이가 1인 계단 수 저장
    dp[1][0] = 0;
    for (int i = 1; i < 10; i++){
        dp[1][i] = 1;
    }
    
    int m = 2;
    while (m <= n){
        for (int i = 0; i < 10; i++){
            int tmp = 0;
            // 0과 9는 이어지는 수가 아님에 유의
            if (i != 0){
                tmp += dp[m-1][i-1];
            }
            if (i != 9){
                tmp += dp[m-1][i+1];
            }
            // 1,000,000,000으로 나눈 나머지를 저장
            tmp %= DIV;
            dp[m][i] = tmp;
        }
        m++;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++){
        ans = (ans + dp[n][i]) % DIV;
    }
    cout << ans;
}

