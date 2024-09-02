#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point{
    int y;
    int x;
};

int n, m;
char graph[11][11];
bool visited[11][11][11][11];
point redPos;
point bluePos;
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


bool solve(){
    queue<pair<point, point>> que;
    que.push({redPos, bluePos});
    visited[redPos.y][redPos.x][bluePos.y][bluePos.x] = true;

    int cnt = 1;
    while (!que.empty()){
        if (cnt > 10){
            return false;
        }
        int size = que.size();
        while (size--){           
            for (int i = 0; i < 4; i++){
                point red = que.front().first;
                point blue = que.front().second;

                bool redInHole = false;
                bool blueInHole = false;

                int dirY = direction[i][0];
                int dirX = direction[i][1];

                // 빨간 공을 먼저 굴림
                while (true){
                    if (red.y + dirY < 1 || red.y + dirY > n
                    || red.x + dirX < 1 || red.x + dirX > m
                    || graph[red.y + dirY][red.x + dirX] == '#'
                    || (red.y + dirY == blue.y && red.x + dirX == blue.x)){
                        break;
                    }
                    if (graph[red.y + dirY][red.x + dirX] == 'O'){
                        redInHole = true;
                    }
                    red.y += dirY; red.x += dirX;
                }
                // 파란 공을 굴림
                while (true){
                    if (blue.y + dirY < 1 || blue.y + dirY > n
                    || blue.x + dirX < 1 || blue.x + dirX > m
                    || graph[blue.y + dirY][blue.x + dirX] == '#'
                    || (!redInHole && blue.y + dirY == red.y && blue.x + dirX == red.x)){
                        break;
                    }
                    if (graph[blue.y + dirY][blue.x + dirX] == 'O'){
                        blueInHole = true;
                        break;
                    }
                    blue.y += dirY; blue.x += dirX;
                }
                if (redInHole && !blueInHole){
                    return true;
                }
                else if (blueInHole){
                    continue;
                }
                // 빨간 공을 다시 굴림
                while (true){
                    if (red.y + dirY < 1 || red.y + dirY > n
                    || red.x + dirX < 1 || red.x + dirX > m
                    || graph[red.y + dirY][red.x + dirX] == '#'
                    || (red.y + dirY == blue.y && red.x + dirX == blue.x)){
                        break;
                    }
                    red.y += dirY; red.x += dirX;
                }
                if (!visited[red.y][red.x][blue.y][blue.x]){
                    // 큐에 추가
                    que.push({red, blue});
                    visited[red.y][red.x][blue.y][blue.x] = true;
                }
            }
            que.pop();
        }
        cnt++;
    }
    return false;
}

int main(){    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 'R'){
                redPos = {i, j};
                graph[i][j] = '.';
            }
            else if (graph[i][j] == 'B'){
                bluePos = {i, j};
                graph[i][j] = '.';
            }
        }
    }

    if (solve()){
        cout << 1;
    }
    else{
        cout << 0;
    }
}