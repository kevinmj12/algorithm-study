#include <iostream>
#include <queue>
using namespace std;

int board[20][20];
bool visited[20][20];
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void resetVisited(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
}

int bfs(int n, int sharkY, int sharkX){
    queue<pair<int, int>> que;
    int fishY = n, fishX = n;

    int sharkWeight = 2;
    int fishCnt = 0;
    int time = 0;

    que.push({sharkY, sharkX});
    visited[sharkY][sharkX] = true;
    int tmpTime = 0;
    bool findFish = false;
    while (!que.empty()){
        tmpTime++;
        int queSize = que.size();
        for (int i = 0; i < queSize; i++){
            int curY = que.front().first;
            int curX = que.front().second;
            que.pop();
            for (int j = 0; j < 4; j++){
                int nextY = curY+dir[j][0];
                int nextX = curX+dir[j][1];
                // 범위를 벗어나거나 조건에 맞지 않은 경우
                if (nextY < 0 || n <= nextY || nextX < 0 || n <= nextX 
                || visited[nextY][nextX] || board[nextY][nextX] > sharkWeight){
                    continue;
                }
                // 물고기가 없거나 물고기와 무게가 같은 경우
                else if (!board[nextY][nextX] || board[nextY][nextX] == sharkWeight){
                    que.push({nextY, nextX});
                    visited[nextY][nextX] = true;
                }
                // 잡아먹을 수 있는 물고기를 찾은 경우
                else{
                    if (nextY < fishY || (nextY == fishY && nextX < fishX)){
                        fishY = nextY; fishX = nextX;
                    }
                    findFish = true;
                }
            }
        }
        if (findFish){
            findFish = false;
            while(!que.empty()){
                que.pop();
            }
            que.push({fishY, fishX});
            board[fishY][fishX] = 0;
            resetVisited(n);
            visited[fishY][fishX] = true;
            fishY = n, fishX = n;

            time += tmpTime;
            tmpTime = 0;

            fishCnt++;
            if (fishCnt == sharkWeight){
                sharkWeight++;
                fishCnt = 0;
            }
        }
    }
    return time;
}

int main(){
    int n;
    cin >> n;

    int sharkY, sharkX;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
            if (board[i][j] == 9){
                sharkY = i;
                sharkX = j;
                board[i][j] = 0;
            }
        }
    }

    cout << bfs(n, sharkY, sharkX);
}