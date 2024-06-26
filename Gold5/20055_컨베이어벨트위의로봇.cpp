#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int belt[201];
queue<int> robots;
bool visited[201];
int zeroAreas = 0; // 내구도가 0인 칸의 개수

// 벨트를 한 칸 회전시켜주는 함수
void updateIndex(int& start, int& end){ 
    if (start == 1){
        start = 2*n;
        end--;
    }
    else if (end == 1){
        start--;
        end = 2*n;
    }
    else{
        start--;
        end--;
    }

    if (!robots.empty() && robots.front() == end){
        robots.pop();
        visited[end] = false;
    }
}

// 로봇을 이동시키는 함수
void moveRobot(int end){
    int robotsSize = robots.size();
    for (int i = 0; i < robotsSize; i++){
        int robotPos = robots.front();
        int nextPos = robotPos == 2*n ? 1 : robotPos+1;
        if (!visited[nextPos] && belt[nextPos]){
            visited[robotPos] = false;
            visited[nextPos] = true;
            robots.pop();
            robots.push(nextPos);
            belt[nextPos]--;
            if (!belt[nextPos]){
                zeroAreas++;
            }
        }
        else{
            robots.pop();
            robots.push(robotPos);
        }
    }
    if (!robots.empty() && robots.front() == end){
        robots.pop();
        visited[end] = false;
    }
}

// 로봇을 추가하는 함수
void insertRobot(int start){
    if (belt[start]){
        robots.push(start);
        visited[start] = true;
        belt[start]--;
        if (!belt[start]){
            zeroAreas++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= 2*n; i++){
        cin >> belt[i];
    }

    int start = 1; // 로봇을 올리는 위치
    int end = n; // 로봇을 내리는 위치
    int answer = 1;
    while (true){
        updateIndex(start, end); // 1. 벨트가 한 칸 회전
        moveRobot(end); // 2. 로봇 이동
        insertRobot(start); // 3. 로봇 추가
        if (zeroAreas >= k){
            cout << answer;
            return 0;
        }

        answer++;
    }
}