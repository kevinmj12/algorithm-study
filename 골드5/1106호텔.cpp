#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX 1001
int dp[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int c, n;
    cin >> c >> n;

    int moneyAndPeople[n][2];
    int minMoney = INT_MAX;
    int minPeople;

    // 입력을 받으면서 가장 적은 금액과 그때의 사람을 저장
    for (int i = 0; i < n; i++){
        cin >> moneyAndPeople[i][0] >> moneyAndPeople[i][1];
        if (moneyAndPeople[i][0] < minMoney){
            minMoney = moneyAndPeople[i][0];
            minPeople = moneyAndPeople[i][1];
        }
    }

    // 만약 가장 적은 금액으로도 충분하면 끝
    if (minPeople >= c){
        cout << minMoney;
        return 0;
    }

    // 기본값 설정
    dp[0] = 0;
    for (int i = 1; i <= minPeople; i++){
        dp[i] = minMoney;
    }
    for (int i = minPeople+1; i <= c; i++){
        dp[i] = INT_MAX;
    }
    
    // 
    for (int i = minPeople+1; i <= c; i++){
        for (int j = 0; j < n; j++){
            int tmp = i - moneyAndPeople[j][1];
            if (tmp < 0){
                dp[i] = min(dp[i], moneyAndPeople[j][0]);
            }
            else{
                dp[i] = min(dp[i], moneyAndPeople[j][0]+dp[tmp]);
            }
        }
    }
    
    cout << dp[c];
}