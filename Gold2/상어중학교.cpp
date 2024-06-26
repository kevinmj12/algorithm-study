#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int graph[21][21];
bool visited[21][21];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int score = 0;

void resetVisited(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            visited[i][j] = false;
        }
    }
}

void resetRainbow(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (!graph[i][j]){
                visited[i][j] = false;
            }
        }
    }
}

bool judge(int y, int x, int color){
    if (1 <= y && y <= n && 1 <= x && x <= n && !visited[y][x]
    && (graph[y][x] == 0 || graph[y][x] == color)){
        return true;
    }
    return false;
}

bool findAndRemoveMaxBlocks(){
    int maxGroupSize = -1;
    int maxGroupRainbow;
    int maxGroupBaseY, maxGroupBaseX;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (graph[i][j] == 0 || graph[i][j] == -1 || graph[i][j] == -2 || visited[i][j]){
                continue;
            }
            // 그룹을 찾기 전 무지개 블록 초기화
            resetRainbow();
            // BFS로 그룹의 사이즈 조사
            int color = graph[i][j];
            queue<pair<int, int>> group;
            int groupSize = 1;
            int groupRainbow = 0;
            int baseY = i;
            int baseX = j;
            group.push({i, j});
            visited[i][j] = true;

            while (!group.empty()){
                int curY = group.front().first;
                int curX = group.front().second;
                group.pop();
                for (int k = 0; k < 4; k++){
                    int nextY = curY+dir[k][0];
                    int nextX = curX+dir[k][1];
                    if (judge(nextY, nextX, color)){
                        if (graph[nextY][nextX] == 0){
                            groupRainbow++;
                        }
                        group.push({nextY, nextX});
                        visited[nextY][nextX] = true;
                        groupSize++;
                    }
                }
            }
            if (groupSize >= 2){
                if (groupSize > maxGroupSize ||
                (groupSize == maxGroupSize && groupRainbow >= maxGroupRainbow)){
                    maxGroupSize = groupSize;
                    maxGroupRainbow = groupRainbow;
                    maxGroupBaseY = baseY;
                    maxGroupBaseX = baseX;
                }
            }
        }
    }
    
    // 만약 그래프 내에 그룹이 한 개도 없다면
    if (maxGroupSize == -1){
        cout << score;
        return false;
    }

    // Visited 초기화, 점수 추가
    resetVisited();
    score += maxGroupSize * maxGroupSize;
    // 제일 큰 그룹을 제거
    int color = graph[maxGroupBaseY][maxGroupBaseX];
    queue<pair<int, int>> group;
    group.push({maxGroupBaseY, maxGroupBaseX});
    graph[maxGroupBaseY][maxGroupBaseX] = -2;
    while (!group.empty()){
        int curY = group.front().first;
        int curX = group.front().second;
        group.pop();
        for (int k = 0; k < 4; k++){
            int nextY = curY+dir[k][0];
            int nextX = curX+dir[k][1];
            if (judge(nextY, nextX, color)){
                group.push({nextY, nextX});
                graph[nextY][nextX] = -2;
            }
        }
    }
    return true;
}

void gravity(){
    for (int x = 1; x <= n; x++){
        int distance = 0;
        for (int y = n; y >= 1; y--){
            // 비어있는 경우
            if (graph[y][x] == -2){
                distance++;
            }
            // 검은 블록인 경우
            else if (graph[y][x] == -1){
                distance = 0;
            }
            // 그 이외의 블록인 경우
            else{
                if (distance){
                    graph[y+distance][x] = graph[y][x];
                    graph[y][x] = -2;
                }
            }
        }
    }
}

void rotate(){
    int copyGraph[n+1][n+1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            copyGraph[i][j] = graph[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            graph[i][j] = copyGraph[j][n+1-i];
        }
    }
}


int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }

    while (true){
        // 가장 큰 그룹을 찾고 제거
        if (!findAndRemoveMaxBlocks()){
            return 0;
        }

        // 중력 적용
        gravity();
        
        // 90도 반시계방향으로 회전
        rotate();

        // 중력 적용
        gravity();
    }
}