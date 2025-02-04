#include <iostream>
#include <vector>
using namespace std;

int r, c, t;
int graph[50][50];
pair<int, int> cleanerPos;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

// 미세먼지가 이동 가능한지 판단하는 함수
bool canSpread(int y, int x){
    if (0 <= y && y < r && 0 <= x && x < c && graph[y][x] != -1){
        return true;
    }
    return false;
}

// 미세먼지의 확산
void spread(){
    int spreadGraph[r][c];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            spreadGraph[i][j] = 0;
        }
    }

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            // 미세먼지가 확산 가능한 만큼 존재한다면
            int amount = graph[i][j] / 5;
            if (amount > 0){
                // 네 방향을 모두 조사하여 확산
                int spreadDirs = 0;
                for (int d = 0; d < 4; d++){
                    int nextY = i+dir[d][0];
                    int nextX = j+dir[d][1];
                    if (canSpread(nextY, nextX)){
                        spreadDirs++;
                        spreadGraph[nextY][nextX] += amount;
                    }
                }
                spreadGraph[i][j] -= amount * spreadDirs;
            }
        }
    }
    // 확산 진행
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            graph[i][j] += spreadGraph[i][j];
        }
    }
}

// 공기청정기의 작동
void operateCleaner(){
    // 위쪽 공기청정기 바람 진행
    pair<int, int> top = {cleanerPos.first-1, cleanerPos.second};
    while (top.first-1 >= 0){
       graph[top.first][top.second] = graph[top.first-1][top.second];
       top.first--;
    }
    while (top.second+1 < c){
        graph[top.first][top.second] = graph[top.first][top.second+1];
        top.second++;
    }
    while (top.first+1 <= cleanerPos.first){
        graph[top.first][top.second] = graph[top.first+1][top.second];
        top.first++;
    }
    while (top.second-1 >= 1){
        graph[top.first][top.second] = graph[top.first][top.second-1];
        top.second--;
    }
    graph[top.first][top.second] = 0;
    // 아래쪽 공기청정기 바람 진행
    pair<int, int> bot = {cleanerPos.first+2, cleanerPos.second};
    while (bot.first+1 < r){
        graph[bot.first][bot.second] = graph[bot.first+1][bot.second];
        bot.first++;
    }
    while (bot.second+1 < c){
        graph[bot.first][bot.second] = graph[bot.first][bot.second+1];
        bot.second++;
    }
    while (bot.first-1 >= cleanerPos.first+1){
        graph[bot.first][bot.second] = graph[bot.first-1][bot.second];
        bot.first--;
    }
    while (bot.second-1 >= 1){
        graph[bot.first][bot.second] = graph[bot.first][bot.second-1];
        bot.second--;
    }
    graph[bot.first][bot.second] = 0;
}

// 미세먼지의 총 합을 구하는 함수
int solve(){
    int answer = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (graph[i][j] > 0){
                answer += graph[i][j];
            }
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> t;
    bool findCleaner = false;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> graph[i][j];
            if (!findCleaner && graph[i][j] == -1){
                cleanerPos = {i,j};
                findCleaner = true;
            }
        }
    }

    while (t--){
        spread();
        operateCleaner();
    }
    cout << solve();
}