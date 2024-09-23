#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int graph[501][501];
int memo[501][501];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};


int solve(int y, int x, int depth){
    int rtn = depth;
    for (int i = 0; i < 4; i++){
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];

        if (nextY < 1 || nextY > n || nextX < 1 || nextX > n){
            continue;
        }
        if (graph[nextY][nextX] > graph[y][x]){
            if (memo[nextY][nextX] == 0){
                memo[nextY][nextX] = solve(nextY, nextX, depth);
            }
            rtn = max(rtn, depth + memo[nextY][nextX]);
        }
    }
    return rtn;
}


int main(){
    cin >> n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }

    int answer = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (memo[i][j] == 0){
                memo[i][j] = solve(i, j, 1);
            }
            answer = max(answer, memo[i][j]);
        }
    }

    cout << answer;
}