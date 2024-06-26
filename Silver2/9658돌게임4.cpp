#include <iostream>
#include <string>
using namespace std;
#define MAX 1001
int dp[MAX];

int main(){
    int N;
    cin >> N;

    // 상근이가 이기면 0, 창영이가 이기면 1
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 0;
    
    for (int i = 5; i <= N; i++){
        if (dp[i-4]+dp[i-3]+dp[i-1]){
            dp[i] = 0;
        }
        else{
            dp[i] = 1;
        }
    }

    if (dp[N]){
        cout << "CY";
    }
    else{
        cout << "SK";
    }
}