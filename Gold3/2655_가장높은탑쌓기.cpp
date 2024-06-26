#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> bricks;
int dp[101];
int root[101];

int main(){
    int n;
    cin >> n;
    
    // 벡터의 인덱스 편의를 위해 더미값을 집어넣음
    bricks.push_back({0,0,0,0});
    for (int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;

        // 넓이, 무게, 높이, 번호 순으로 저장
        bricks.push_back({a, c, b, i});
    }

    sort(bricks.begin(), bricks.end());

    // 배낭 문제와 비슷하게 풀기
    for (int i = 1; i <= n; i++){
        // 벽돌 하나를 놓는게 높이가 가장 높은 경우
        dp[i] = bricks[i][2];
        root[i] = i;
        for (int j = 1; j < i; j++){
            // 무게, 넓이가 모두 크고 합친 게 기존보다 높은 경우
            if (bricks[j][1] < bricks[i][1]){
                if (dp[j]+bricks[i][2] > dp[i]){
                    dp[i] = dp[j]+bricks[i][2];
                    root[i] = j;
                }
            }
        }
    }
    
    // 역추적을 위해 마지막으로 추가한 벽돌을 찾음
    int lastBrick;
    int height = 0;
    for (int i = 1; i <= n; i++){
        if (dp[i] > height){
            height = dp[i];
            lastBrick = i;
        }
    }

    // 정답을 스택에 넣고 출력
    stack<int> answer;

    while (lastBrick != root[lastBrick]){
        answer.push(lastBrick);
        lastBrick = root[lastBrick];
    }
    answer.push(lastBrick);

    cout << answer.size() << "\n";
    while (!answer.empty()){
        cout << bricks[answer.top()][3] << "\n";
        answer.pop();
    }
    for (int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }
}