#include <iostream>
#include <algorithm>
using namespace std;
int num[1001];
int dp[1001];

int main(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> num[i];
        dp[i] = 1;
    }

    int answer = 1;

    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= i-1; j++){
            if (num[i] > num[j]){
                dp[i] = max(dp[i], dp[j]+1);
                answer = max(answer, dp[i]);
            }
        }
    }

    cout << answer;
}