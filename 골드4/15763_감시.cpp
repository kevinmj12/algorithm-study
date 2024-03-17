#include <iostream>
#include <vector>
using namespace std;

int n, m;
int graph[9][9];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<pair<int, int>> cctv5;
vector<pair<int, pair<int, int>>> cctvs;
int answer = 64;

void checkAnswer(){
    int tmp = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (graph[i][j] == 0){
                tmp++;
            }
        }
    }
    answer = min(answer , tmp);
}

void dfs(int cctv){
    // 모든 CCTV를 다 확인한 경우
    if (cctv == cctvs.size()+1){
        checkAnswer();
        return;
    }    
    int cctvStyle = cctvs[cctv-1].first;
    int cctvY = cctvs[cctv-1].second.first;
    int cctvX = cctvs[cctv-1].second.second;
    if (graph[cctvY][cctvX] == 0){
        graph[cctvY][cctvX] = cctv;
    }

    // 1번 CCTV인 경우
    if (cctvStyle == 1){
        for (int i = 0; i < 4; i++){
            int nextY = cctvY;
            int nextX = cctvX;
            while (true){
                nextY += dir[i][0];
                nextX += dir[i][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == 0){
                    graph[nextY][nextX] = cctv;
                }
            }
            
            dfs(cctv+1);
            // 다시 원상태로 돌려놓기
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[i][0];
                nextX += dir[i][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == cctv){
                    graph[nextY][nextX] = 0;
                }
            }
        }
    }
    // 2번 CCTV인 경우
    else if (cctvStyle == 2){
        for (int i = 0; i < 2; i++){
            int nextY = cctvY;
            int nextX = cctvX;
            while (true){
                nextY += dir[i][0];
                nextX += dir[i][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == 0){
                    graph[nextY][nextX] = cctv;
                }
            }
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[i+2][0];
                nextX += dir[i+2][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == 0){
                    graph[nextY][nextX] = cctv;
                }
            }

            dfs(cctv+1);

            // 다시 원상태로 돌려놓기
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[i][0];
                nextX += dir[i][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == cctv){
                    graph[nextY][nextX] = 0;
                }
            }
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[i+2][0];
                nextX += dir[i+2][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == cctv){
                    graph[nextY][nextX] = 0;
                }
            }
        }
    }
    // 3번 CCTV인 경우
    else if (cctvStyle == 3){
        for (int i = 0; i < 4; i++){
            int nextY = cctvY;
            int nextX = cctvX;
            while (true){
                nextY += dir[i][0];
                nextX += dir[i][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == 0){
                    graph[nextY][nextX] = cctv;
                }
            }
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[(i+1)%4][0];
                nextX += dir[(i+1)%4][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == 0){
                    graph[nextY][nextX] = cctv;
                }
            }

            dfs(cctv+1);

            // 다시 원상태로 돌려놓기
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[i][0];
                nextX += dir[i][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == cctv){
                    graph[nextY][nextX] = 0;
                }
            }
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[(i+1)%4][0];
                nextX += dir[(i+1)%4][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == cctv){
                    graph[nextY][nextX] = 0;
                }
            }
        }
    }

    // 4번 CCTV인 경우
    else{
        for (int i = 0; i < 4; i++){
            int nextY = cctvY;
            int nextX = cctvX;
            while (true){
                nextY += dir[i][0];
                nextX += dir[i][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == 0){
                    graph[nextY][nextX] = cctv;
                }
            }
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[(i+1)%4][0];
                nextX += dir[(i+1)%4][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == 0){
                    graph[nextY][nextX] = cctv;
                }
            }
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[(i+3)%4][0];
                nextX += dir[(i+3)%4][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == 0){
                    graph[nextY][nextX] = cctv;
                }
            }
            
            dfs(cctv+1);

            // 다시 원상태로 돌려놓기
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[i][0];
                nextX += dir[i][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == cctv){
                    graph[nextY][nextX] = 0;
                }
            }
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[(i+1)%4][0];
                nextX += dir[(i+1)%4][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == cctv){
                    graph[nextY][nextX] = 0;
                }
            }
            nextY = cctvY;
            nextX = cctvX;
            while (true){
                nextY += dir[(i+3)%4][0];
                nextX += dir[(i+3)%4][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                if (graph[nextY][nextX] == cctv){
                    graph[nextY][nextX] = 0;
                }
            }
        }
    }
    if (graph[cctvY][cctvX] == cctv){
        graph[cctvY][cctvX] = 0;
    }
}

int main(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int a;
            cin >> a;
    
            if (0 < a && a < 5){
                cctvs.push_back({a, {i,j}});
                graph[i][j] = 0;
            }
            else if (a == 5){
                cctv5.push_back({i,j});
                graph[i][j] = 0;
            }
            else if (a == 6){
                graph[i][j] = -2;
            }
            else{
                graph[i][j] = 0;
            }
        }
    }

    // 감시가 된 구역은 -1로 처리.

    // 5번 CCTV 처리
    // 5번 CCTV는 회전할 필요 없이 4방향을 모두 감시 가능
    for (int i = 0; i < cctv5.size(); i++){
        int cctvY = cctv5[i].first;
        int cctvX = cctv5[i].second;
        graph[cctvY][cctvX] = -1;

        for (int j = 0; j < 4; j++){
            int nextY = cctvY;
            int nextX = cctvX;
            while (true){
                nextY += dir[j][0];
                nextX += dir[j][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > m
                || graph[nextY][nextX] == -2){
                    break;
                }
                graph[nextY][nextX] = -1;
            }    
        }
    }

    // 나머지는 모든 경우를 DFS로 순회하며 판단
    dfs(1);
    cout << answer;
}