#include <iostream>
using namespace std;

int n, m;
int graph[501][501];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int answer = 0;

// DFS로 가능한 테트로미노
void solveOne(int y, int x, int preY, int preX, int size, int sum){
    sum += graph[y][x];
    if (size == 4){
        answer = max(answer, sum);
        return;
    }
    for (int i = 0; i < 4; i++){
        int nextY = y+dir[i][0];
        int nextX = x+dir[i][1];

        if (nextY < 1 || n < nextY || nextX < 1 || m < nextX){
            continue;
        }
        if (preY == nextY && preX == nextX){
            continue;
        }
        solveOne(nextY, nextX, y, x, size+1, sum);
    }
}

// ㅗ, ㅜ, ㅓ, ㅏ 테트로미노
void solveTwo(int y, int x, int direction, int size, int sum){
    sum += graph[y][x];
    if (size == 4){
        answer = max(answer, sum);
        return;
    }
    if (size == 3){
        if (direction == 0){
            int nextY = y-1;
            int nextX = x-1;
            if (1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m){
                solveTwo(nextY, nextX, direction, size+1, sum);
            }
            nextX = x+1;
            if (1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m){
                solveTwo(nextY, nextX, direction, size+1, sum);
            }
        }
        else{
            int nextY = y-1;
            int nextX = x-1;
            if (1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m){
                solveTwo(nextY, nextX, direction, size+1, sum);
            }
            nextY = y+1;
            if (1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m){
                solveTwo(nextY, nextX, direction, size+1, sum);
            }
        }
    }
    else{
        int nextY = y+dir[direction][0];
        int nextX = x+dir[direction][1];
        if (1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m){
            solveTwo(nextY, nextX, direction, size+1, sum);
        }
    }
    
}

int main(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            solveOne(i, j, -1, -1, 1, 0);
            solveTwo(i, j, 0, 1, 0);
            solveTwo(i, j, 2, 1, 0);
        }
    }

    cout << answer;
}