#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> orders;
int dp[100000][5][5];

int main(){
    while (true){
        int n;
        cin >> n;

        if (n != 0){
            orders.push_back(n);
        }
        else{
            break;
        }
    }

    
    // 입력이 2개 이하일 경우
    if (orders.size() == 0){
        cout << 0;
        return 0;
    }
    if (orders.size() == 1){
        cout << 2;
        return 0;
    }

    
    // base case
    for (int i = 0; i < orders.size(); i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    // dp[1][orders[0]][orders[1]] = 4;
    int idx = 1;
    while (idx < orders.size() && orders[idx] == orders[0]){
        idx++;
    }
    if (idx == orders.size()){
        cout << idx+1;
        return 0;
    }

    dp[idx][orders[0]][orders[idx]] = 4 + (idx-1);

    for (int i = 1; i < orders.size(); i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                if (dp[i-1][j][k] != -1){
                    if (j == orders[i] || k == orders[i]){
                        if (dp[i][j][k] == -1){
                            dp[i][j][k] = dp[i-1][j][k] + 1;
                        }
                        else{
                            dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k] + 1);
                        }
                    }
                    else{
                        int addCost = 3;
                        if (abs(orders[i]-k == 2)){
                            addCost++;
                        }
                        if (dp[i][j][orders[i]] == -1){
                            dp[i][j][orders[i]] = dp[i-1][j][k] + addCost;
                        }
                        else{
                            dp[i][j][orders[i]] = min(dp[i][j][orders[i]], dp[i-1][j][k] + addCost);
                        }

                        addCost = 3;
                        if (abs(orders[i]-j == 2)){
                            addCost++;
                        }
                        if (dp[i][orders[i]][k] == -1){
                            dp[i][orders[i]][k] = dp[i-1][j][k] + addCost;
                        }
                        else{
                            dp[i][orders[i]][k] = min(dp[i][orders[i]][k], dp[i-1][j][k] + addCost);
                        }
                    }
                }
            }
        }
    }

    int answer = INT_MAX;
    for (int j = 0; j < 5; j++){
        for (int k = 0; k < 5; k++){
            int val = dp[orders.size()-1][j][k];
            if (val != -1){
                answer = min(answer, val);
                cout << j << " " << k  << " " << val << endl;
            }
        }
    }
    cout << answer;
}