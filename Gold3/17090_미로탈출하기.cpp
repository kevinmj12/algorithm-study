#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 502
char maze[MAX][MAX];
int visited[MAX][MAX];

void resetVisited(int n, int m){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            visited[i][j] = 0;
        }
    }
}

void setEscape(int n, int m){
    for (int i = 0; i <= n+1; i++){
        visited[i][0] = 3;
        visited[i][m+1] = 3;
    }
    for (int j = 0; j <= m+1; j++){
        visited[0][j] = 3;
        visited[n+1][j] = 3;
    }
}

pair<int, int> move(int y, int x){
    char target = maze[y][x];
    if (target == 'U'){
        return {y-1, x};
    }
    else if (target == 'R'){
        return {y, x+1};
    }
    else if (target == 'D'){
        return {y+1, x};
    }
    else{
        return {y, x-1};
    }
}

// visited가 0이면 방문 안함, 1이면 방문함, 2면 탈출 불가능, 3이면 탈출 가능.
int dfs(int n, int m, int y, int x){
    // 미로를 탈출한 경우
    if (visited[y][x] == 3){
        return true;
    }
    // 이미 방문했던 곳을 방문하거나 탈출하지 못하는 경우
    else if (visited[y][x] == 1 || visited[y][x] == 2){
        visited[y][x] = 2;
        return false;
    }

    // 방문 처리
    visited[y][x] = 1;
    // 다음 이동 경로
    pair<int, int> next = move(y, x);
    int nextY = next.first;
    int nextX = next.second;

    if (dfs(n, m, nextY, nextX)){
        visited[y][x] = 3;
        return true;
    }
    else{
        visited[y][x] = 2;
        return false;
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        string input;
        cin >> input;

        for (int j = 1; j <= M; j++){
            maze[i][j] = input[j-1];
        }
    }

    resetVisited(N, M);
    setEscape(N, M);
    int answer = 0;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if (dfs(N, M, i, j)){
                answer++;
            }           
        }
    }

    cout << answer;
}