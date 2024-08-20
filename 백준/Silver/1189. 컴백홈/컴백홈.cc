#include <iostream>
using namespace std;

char graph[5][5];
bool visited[5][5];
int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int r, c, k;
int answer = 0;

void dfs(int y, int x, int depth){
    if (y == 1 && x == c){
        if (depth == k){
            answer++;
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        int nextY = y+direction[i][0];
        int nextX = x+direction[i][1];
        if (nextY < 1 || nextY > r || nextX < 1 || nextX > c 
        || visited[nextY][nextX] || graph[nextY][nextX] == 'T'){
            continue;
        }
        else{
            visited[nextY][nextX] = true;
            dfs(nextY, nextX, depth+1);
            visited[nextY][nextX] = false;
        }
    }
}

int main(){
    cin >> r >> c >> k;

    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> graph[i][j];
        }    
    }

    visited[r][1] = true;
    dfs(r, 1, 1);
    cout << answer;
}