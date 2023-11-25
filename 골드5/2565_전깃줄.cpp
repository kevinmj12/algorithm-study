#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 501

int line[MAX];
int dp[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int numLines;
    cin >> numLines;

    // line, dp 초기화
    for (int i = 1; i < MAX; i++){
        line[i] = 0;
        dp[i] = 1;
    }

    // 전깃줄 입력 받음
    for (int i = 0; i < numLines; i++){
        int a, b;
        cin >> a >> b;
        line[a] = b;
    }

    // 제일 긴 증가구간을 찾음
    int answer = 1;
    for (int i = 1; i < MAX; i++){
        // 전깃줄이 연결되어있는 경우
        if (line[i]){
            // 이전 전깃줄들을 조회하여 최댓값 저장
            for (int j = 1; j < i; j++){
                if (line[j] && line[j] < line[i]){
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
            answer = max(dp[i], answer);
        }
    }
    
    cout << numLines - answer;
}