#include <iostream>
#include <algorithm>
using namespace std;

int nums[1001];
int dp[1001];

int main(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> nums[i];
    }

    // base case
    dp[1] = nums[1];
    int answer = nums[1];

    for (int i = 2; i <= n; i++){
        dp[i] = nums[i];
        for (int j = 1; j < i; j++){
            if (nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j]+nums[i]);
            }
        }
        answer = max(answer, dp[i]);
    }

    cout << answer;
}