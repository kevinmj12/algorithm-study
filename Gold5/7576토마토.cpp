#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1001
int tomatoes[MAX][MAX];

// BFS로 며칠이 걸릴 지 검사
void solve(int n, int m, int numTomatoes){
    int ripedTomatoes = 0;
    queue<pair<int, int>> order;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // 익은 토마토가 있으면 큐에 추가
            if (tomatoes[i][j] == 1){
                order.push({i, j});
                ripedTomatoes++;
            }
        }
    }

    int answer = 0;
    // 처음부터 모든 토마토가 전부 익었다면 0 출력
    if (ripedTomatoes == numTomatoes){
        cout << answer;
        return;
    }

    // BFS 탐색
    while (!order.empty()){
        answer++;
        int size = order.size();
        for (int s = 0; s < size; s++){
            int tomatoY = order.front().first;
            int tomatoX = order.front().second;
            int direction[4][2] = {{tomatoY-1, tomatoX}, {tomatoY+1, tomatoX}, {tomatoY, tomatoX-1}, {tomatoY, tomatoX+1}};
            for (int d = 0; d < 4; d++){
                int tmpY = direction[d][0];
                int tmpX = direction[d][1];
                // 좌표상으로 만족하고 토마토가 익지 않았다면 order에 추가
                if (tmpY >= 0 && tmpY < n && tmpX >= 0 && tmpX < m){
                    if (tomatoes[tmpY][tmpX] == 0){
                        order.push({tmpY, tmpX});
                        tomatoes[tmpY][tmpX] = 1;
                        ripedTomatoes++;
                    }
                }
            }
            order.pop();
        }

        if (ripedTomatoes == numTomatoes){
            cout << answer;
            return;
        }
    }
    // while문을 탈출하면 모든 토마토가 익을 수 없음
    cout << -1;
    return;
    
}

int main(){
    int M, N, numTomatoes = 0;
    cin >> M >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> tomatoes[i][j];
            if (tomatoes[i][j] != -1){
                numTomatoes++;
            }
        }
    }

    solve(N, M, numTomatoes);
}