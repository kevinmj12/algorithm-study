#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool plums[1001];
int dp[1001][32][3];

int main(){
    int t, w;
    cin >> t >> w;

    for (int i = 1; i <= t; i++){
        int tree;
        cin >> tree;
        if (tree == 2){
            plums[i] = true;
        }
    }

    // dp[i][j][k] 는 i번째 자두가 떨어질 때 j-1번 이동했고 자두가 k번 나무에 있을 때 최대 자두 수
    for (int i = 1; i <= t; i++){
        for (int j = 1; j <= w+1; j++){
            // 1번 나무에 위치한 경우
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2]);
            // 2번 나무에 위치한 경우
            dp[i][j][2] = max(dp[i-1][j][2], dp[i-1][j-1][1]);

            // 자두가 떨어지는 나무에 +1
            if (!plums[i]){
                dp[i][j][1]++;
            }
            else{
                // 맨 처음에 i=1일 때 2번 나무에 자두가 떨어진다면 카운트 X
                if (i == 1 && j == 1){
                    continue;
                }
                dp[i][j][2]++;
            }
        }
    }

    int answer = 0;
    for (int j = 1; j <= w+1; j++){
        answer = max(answer, max(dp[t][j][1], dp[t][j][2]));
    }
    cout << answer;
}