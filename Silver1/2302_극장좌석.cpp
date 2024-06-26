#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> vipSeats;
int dp[41];

int main(){
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        vipSeats.push_back(a);
    }

    // 미리 DP 테이블을 작성해둠
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    // vip 좌석이 하나도 없는 경우
    if (m == 0){
        cout << dp[n];
        return 0;
    }
    // vip 자리에 따라 연속된 일반 좌석의 수를 계산
    int answer = 1;

    int left = 0;
    int right = vipSeats[0];
    answer *= max(1, dp[right-left-1]);

    for (int i = 1; i < m; i++){
        left = vipSeats[i-1];
        right = vipSeats[i];
        answer *= max(1, dp[right-left-1]);
    }

    left = vipSeats[m-1];
    right = n;
    answer *= max(1, dp[right-left]);

    cout << answer;
    return 0;
}