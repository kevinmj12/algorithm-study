#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char board[10][10];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool visited[100][100]; // Red * 10 + Blue 로 visted 판정
pair<int, int> posR, posB;

// 빨간 구슬이 파란 구슬에 걸려 이동하지 못할 수도 있으므로
// 빨 -> 파 -> 빨 순으로 3번 이동을 진행함
vector<int> move(int rY, int rX, int bY, int bX, int dirY, int dirX){
    // 빨간 구슬 이동
    while (true){
        int nextY = rY+dirY, nextX = rX+dirX;
        if (board[nextY][nextX] == 'O'){
            rY = nextY;
            rX = nextX;
            break;
        }
        if ((nextY == bY && nextX == bX) || board[nextY][nextX] == '#'){
            break;
        }
        rY = nextY;
        rX = nextX; 
    }
    // 파란 구슬 이동
    while (true){
        int nextY = bY+dirY, nextX = bX+dirX;
        if (board[nextY][nextX] == 'O'){
            bY = nextY;
            bX = nextX;
            break;
        }
        if ((nextY == rY && nextX == rX) || board[nextY][nextX] == '#'){
            break;
        }
        bY = nextY;
        bX = nextX;
    }
    // 빨간 구슬 이동
    while (true){
        if (board[rY][rX] == 'O'){
            break;
        }
        int nextY = rY+dirY, nextX = rX+dirX;
        if (board[nextY][nextX] == 'O'){
            rY = nextY;
            rX = nextX;
            break;
        }
        if ((nextY == bY && nextX == bX) || board[nextY][nextX] == '#'){
            break;
        }
        rY = nextY;
        rX = nextX;
    }
    return {rY, rX, bY, bX};
}

void bfs(){
    queue<vector<int>> q;
    q.push({posR.first, posR.second, posB.first, posB.second, 0});
    visited[posR.first*10+posB.first][posR.second*10+posB.second] = true;

    while (!q.empty()){
        int rY = q.front()[0], rX = q.front()[1];
        int bY = q.front()[2], bX = q.front()[3];
        int dis = q.front()[4];

        q.pop();
        // 10번 이하여야 함
        if (dis < 10){
            for (int i = 0; i < 4; i++){
                int dirY = dir[i][0], dirX = dir[i][1];            
                vector<int> next = move(rY, rX, bY, bX, dirY, dirX);

                // 파란 구슬이 들어가는 경우(구슬 두 개가 모두 들어가는 경우 포함)
                if (board[next[2]][next[3]] == 'O'){
                    continue;
                }
                // 빨간 구슬이 들어가는 경우
                if (board[next[0]][next[1]] == 'O'){
                    cout << dis+1;
                    return;
                }
                int visitY = next[0]*10+next[2];
                int visitX = next[1]*10+next[3];
                if (!visited[visitY][visitX]){
                    q.push({next[0], next[1], next[2], next[3], dis+1});
                    visited[visitY][visitX] = true;
                }
            }
        }  
    }
    // queue를 빠져나왔다면 답이 없음.
    cout << -1;
    return;
}

int main(){
    int n, m;
    cin >> n >> m;

    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            if (board[i][j] == 'R'){
                posR = {i,j};
                board[i][j] = '.';
            }
            if (board[i][j] == 'B'){
                posB = {i,j};
                board[i][j] = '.';
            }
        }
    }

    bfs();
}