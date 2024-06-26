#include <iostream>
#include <algorithm>
using namespace std;

// bool ladders[d][a][b]
// d번 가로선에 a와 b 세로선 사이에 가로선이 있는지 여부를 저장

bool ladders[31][11][11];
int n, m, h;

int answer = 4;

bool isComplete();
bool moveLadder(int start);

void solve(int depth, int ladder, int addLadder){
    // 가로선이 3보다 큰 값이면 리턴
    if (addLadder > 3){
        return;
    }
    
    // 현재 사다리 상황으로 조건을 만족하는지 파악
    if (isComplete()){
        answer = min(answer, addLadder);
    }

    // 현재 깊이에서 오른쪽 끝까지 이동
    for (int j = ladder; j < n; j++){ // 사다리
        // 이미 왼쪽 또는 오른쪽으로 가는 가로선이 있는 경우
        if (ladders[depth][j][j-1] || ladders[depth][j][j+1]){
            continue;
        }
        // 오른쪽으로 가로선 추가
        ladders[depth][j][j+1] = true;
        ladders[depth][j+1][j] = true;
        addLadder++;     
        // 재귀
        solve(depth, j+2, addLadder);
        // 가로선 제거
        ladders[depth][j][j+1] = false;
        ladders[depth][j+1][j] = false;
        addLadder--;
    }
    depth++;
    while (depth <= h){ // 깊이
        for (int j = 1; j < n; j++){ // 사다리
            // 이미 왼쪽 또는 오른쪽으로 가는 가로선이 있는 경우
            if (ladders[depth][j][j-1] || ladders[depth][j][j+1]){
                continue;
            }
            // 오른쪽으로 가로선 추가
            ladders[depth][j][j+1] = true;
            ladders[depth][j+1][j] = true;
            addLadder++;
            // 재귀
            solve(depth, j+2, addLadder);
            // 가로선 제거
            ladders[depth][j][j+1] = false;
            ladders[depth][j+1][j] = false;
            addLadder--;
        }
        depth++;
    }
}


bool isComplete(){
    for (int i = 1; i <= n; i++){
        if (!moveLadder(i)){
            return false;
        }
    }
    return true;
}

bool moveLadder(int start){
    int pos = start;
    int depth = 1;
    while (depth <= h){
        // 왼쪽으로 가로선이 있는 경우
        if (pos > 1 && ladders[depth][pos][pos-1]){
            pos--;
            depth++;
        }
        // 오른쪽으로 가로선이 있는 경우
        else if (pos < n && ladders[depth][pos][pos+1]){
            pos++;
            depth++;
        }
        else{
            depth++;
        }
    }
    // 도착한 지점이 시작 지점과 같은 사다리인 경우 true
    if (pos == start){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cin >> n >> m >> h;

    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        ladders[a][b][b+1] = true;
        ladders[a][b+1][b] = true;
    }

    solve(1, 1, 0);
    
    if (answer == 4){
        cout << -1;
    }
    else{
        cout << answer;
    }
}