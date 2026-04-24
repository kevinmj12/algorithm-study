#include <iostream>
#include <algorithm>

using namespace std;

int info[16][2];
int dp[17];

int main(){
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++){
        cin >> info[i][0] >> info[i][1];
    }

    for (int i = 1; i <= N; i++){
        dp[i] = max(dp[i], dp[i-1]);
        
        int t = info[i][0];
        int p = info[i][1];
        if (i+t > N+1){
            continue;
        }
        dp[i+t] = max(dp[i+t], dp[i]+p);
    }

    cout << max(dp[N], dp[N+1]);
}