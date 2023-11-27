#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 1000
int arr[MAX][MAX];
int dp[MAX][MAX];

int min3(int a, int b, int c){
    int ret;
    if (a < b) ret = a < c ? a : c;
    else ret = b < c ? b : c;
    return ret;
}

int main(){
    int n, m;
    cin >> n >> m;

    // string으로 입력받아 저장
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        for (int j = 0; j < m; j++){
            arr[i][j] = str[j]-'0';
        }
    }
    int answer = 0;

    // base case
    for (int i = 0; i < n; i++){
        dp[i][0] = arr[i][0];
        answer = max(answer, dp[i][0]);
    }
    for (int j = 0; j < m; j++){
        dp[0][j] = arr[0][j];
        answer= max(answer, dp[0][j]);
    }

    // dp
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            // arr[i][j] 가 1이라면
            if (arr[i][j]){
                dp[i][j] = min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;    
            }
            // arr[i][j] 가 0이라면
            else{
                dp[i][j] = 0;
            }
            answer = max(answer, dp[i][j]);
        }
    }
    
    cout << answer * answer;
}