#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char graph[50][50];
int memoization[50][50];
bool visited[50][50];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool canInfinte = false;
int answer = 0;

int dfs(int y, int x){    
    // 보드판을 벗어나거나 구멍인 경우
    if (y < 0 || y >= n || x < 0 || x >= m || graph[y][x] == 'H'){
        return 0;
    }
    // 무한히 돌 수 있는 경우
    else if (visited[y][x]){
        cout << -1;
        exit(0);
    }
    // 이미 방문한 적 있는 곳인 경우
    else if (memoization[y][x]){
        return memoization[y][x];
    }
    // 이외의 경우 재귀적으로 처리
    else{
        visited[y][x] = true;
        for (int i = 0; i < 4; i++){
            int nextY = y + (dir[i][0] * (graph[y][x]-'0'));
            int nextX = x + (dir[i][1] * (graph[y][x]-'0'));
            memoization[y][x] = max(memoization[y][x], dfs(nextY, nextX)+1);
        }
        visited[y][x] = false;
    }
    
    return memoization[y][x];
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    cout << dfs(0, 0);
}