// M의 범위가 10^9이어서 에러가 발생함.
// 규칙을 찾아서 해야할 수도?
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int M, K;

    cin >> M;
    vector<int> dp;

    cin >> K;
    int ways[K];

    for (int i = 0; i < K; i++){
        cin >> ways[i];
    }


    int answer = 0;
    // 상근이가 이기면 0, 창영이가 이기면 1
    for (int i = 1; i <= M; i++){
        // 돌을 가져가는 가장 작은 단위가 돌의 개수보다 많으면 창영이의 승리
        if (ways[0] > i){
            dp.push_back(1);
            answer++;
        }
        else{
            bool flagCYWin = true;
            for (int j = 0; j < K; j++){
                if (ways[j] == i){
                    flagCYWin = false;
                    break;
                }
                else if (ways[j] < i){
                    if (dp[i-ways[j]] == 1){
                        flagCYWin = false;
                        break;
                    }
                }
            }
            if (flagCYWin){
                dp.push_back(1);
                answer++;
            }
            else{
                dp.push_back(0);
            }
        }
    }

    cout << answer;
}