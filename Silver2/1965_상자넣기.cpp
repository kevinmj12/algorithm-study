#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001
int boxes[MAX];
int dp[MAX];

void resetDp(int n){
    for (int i = 1; i <= n; i++){
        dp[i] = 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> boxes[i];
    }

    resetDp(n);

    int answer = 1;

    // base case
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j < i; j++){
            if (boxes[j] < boxes[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
                answer = max(dp[i], answer);
            }
        }
    }

    cout << answer;
}