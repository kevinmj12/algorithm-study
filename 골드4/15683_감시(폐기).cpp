#include <iostream>
#include <vector>
using namespace std;

int n, m;
int graph[9][9];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<pair<int, int>> cctv[6];

int main(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> graph[i][j];
            if (0 < graph[i][j] && graph[i][j] < 6){
                cctv[graph[i][j]].push_back({i,j});
            }
        }
    }

    // 감시가 된 구역은 -1로 처리.

    // 5번 CCTV 처리
    // 5번 CCTV는 회전할 필요 없이 4방향을 모두 감시 가능
    for (int i = 0; i < cctv[5].size(); i++){
        int cctvY = cctv[5][i].first;
        int cctvX = cctv[5][i].second;
        graph[cctvY][cctvX] = -1;


        for (int j = 0; j < 4; j++){
            int nextY = cctvY;
            int nextX = cctvX;
            while (true){
                nextY += dir[j][0];
                nextX += dir[j][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == 6){
                    break;
                }
                graph[nextY][nextX] = -1;
            }    
        }
    }

    // 4~1번 CCTV 처리
    // 각 방향을 비교하여 가장 감시가 안되는 방향을 제외하고 감시
    for (int ctv = 4; ctv >= 1; ctv--){
        for (int i = 0; i < cctv[ctv].size(); i++){
            int cctvY = cctv[ctv][i].first;
            int cctvX = cctv[ctv][i].second;
            graph[cctvY][cctvX] = -1;


            int dirWatchedAreas[4];
            // 방향별 감시 가능한 구역 개수를 저장
            for (int j = 0; j < 4; j++){
                int nextY = cctvY;
                int nextX = cctvX;
                int tmpWatchedAreas = 0;
                while (true){
                    nextY += dir[j][0];
                    nextX += dir[j][1];
                    if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                    || graph[nextY][nextX] == 6){
                        break;
                    }
                    if (graph[nextY][nextX] != -1){
                        tmpWatchedAreas++;
                    }
                }
                dirWatchedAreas[j] = tmpWatchedAreas;
            }

            // 4번 CCTV
            if (ctv == 4){
                int minDir;
                int minAreas = 100;
                for (int j = 0; j < 4; j++){
                    if (dirWatchedAreas[j] < minAreas){
                        minDir = j;
                        minAreas = dirWatchedAreas[j];
                    }
                }
                // minDir인 방향을 제외하고 전부 추가
                for (int j = 0; j < 4; j++){
                    if (j == minDir){
                        continue;
                    }
                    int nextY = cctvY;
                    int nextX = cctvX;
                    while (true){
                        nextY += dir[j][0];
                        nextX += dir[j][1];
                        if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                        || graph[nextY][nextX] == 6){
                            break;
                        }
                        graph[nextY][nextX] = -1;
                    }
                }
            }
            // 3번 CCTV
            else if (ctv == 3){
                int maxDir;
                int maxAreas = -1;
                for (int j = 0; j < 4; j++){
                    if (dirWatchedAreas[j]+dirWatchedAreas[(j+1)%4] > maxAreas){
                        maxDir = j;
                        maxAreas = dirWatchedAreas[j];
                    }
                }
                // maxDir인 방향 추가
                int nextY = cctvY;
                int nextX = cctvX;
                while (true){
                    nextY += dir[maxDir][0];
                    nextX += dir[maxDir][1];
                    if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                    || graph[nextY][nextX] == 6){
                        break;
                    }
                    graph[nextY][nextX] = -1;

                }
                while (true){
                    nextY += dir[(maxDir+1)%4][0];
                    nextX += dir[(maxDir+1)%4][1];
                    if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                    || graph[nextY][nextX] == 6){
                        break;
                    }
                    graph[nextY][nextX] = -1;

                }
            }
            // 2번 CCTV
            else if (ctv == 2){
                int maxDir;
                int maxAreas = -1;
                for (int j = 0; j < 2; j++){
                    if (dirWatchedAreas[j]+dirWatchedAreas[j+2] > maxAreas){
                        maxDir = j;
                        maxAreas = dirWatchedAreas[j];
                    }
                }
                // maxDir인 방향 추가
                int nextY = cctvY;
                int nextX = cctvX;
                while (true){
                    nextY += dir[maxDir][0];
                    nextX += dir[maxDir][1];
                    if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                    || graph[nextY][nextX] == 6){
                        break;
                    }
                    graph[nextY][nextX] = -1;

                }
                while (true){
                    nextY += dir[maxDir+2][0];
                    nextX += dir[maxDir+2][1];
                    if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                    || graph[nextY][nextX] == 6){
                        break;
                    }
                    graph[nextY][nextX] = -1;

                }
            }
            // 1번 CCTV
            else{
                int maxDir;
                int maxAreas = -1;
                for (int j = 0; j < 4; j++){
                    if (dirWatchedAreas[j] > maxAreas){
                        maxDir = j;
                        maxAreas = dirWatchedAreas[j];
                    }
                }
                // maxDir인 방향 추가
                int nextY = cctvY;
                int nextX = cctvX;
                while (true){
                    nextY += dir[maxDir][0];
                    nextX += dir[maxDir][1];
                    if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                    || graph[nextY][nextX] == 6){
                        break;
                    }
                    graph[nextY][nextX] = -1;

                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (graph[i][j] == 0){
                answer++;
            }
        }
    }

    cout << answer;
}