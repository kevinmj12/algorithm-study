#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

deque<bool> gears[4];
bool visited[4];
int k;

void resetVisited(){
    for (int i = 0; i < 4; i++){
        visited[i] = false;
    }
}

void moveGear(int n, int d){
    // 방문 처리
    visited[n] = true;
    // 다음 회전할 기어들을 추가
    if (n >= 1 && gears[n][6] != gears[n-1][2] && !visited[n-1]){
        moveGear(n-1, -d);
    }
    if (n <= 2 && gears[n][2] != gears[n+1][6] && !visited[n+1]){
        moveGear(n+1, -d);
    }

    // 선택한 기어를 회전시킴
    if (d == 1){ // 시계 방향
        gears[n].push_front(gears[n].back());
        gears[n].pop_back();
    }
    else{ // 반시계 방향
        gears[n].push_back(gears[n].front());
        gears[n].pop_front();
    }
}

int getScore(){
    int answer = 0;
    for (int i = 0; i < 4; i++){
        if (gears[i].front() == true){
            answer += pow(2, i);
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 8; j++){
            char c;
            cin >> c;
            gears[i].push_back(c-'0');
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++){
        int gearNum, dir;
        cin >> gearNum >> dir;

        resetVisited();
        moveGear(gearNum-1, dir);
    }

    cout << getScore();
}