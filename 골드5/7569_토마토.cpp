#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100
int tomatoes[MAX][MAX][MAX];

// BFS로 며칠이 걸릴 지 검사
void solve(int h, int n, int m, int numTomatoes){
    int ripedTomatoes = 0;
    queue<vector<int>> order;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                // 익은 토마토가 있으면 큐에 추가
                if (tomatoes[i][j][k] == 1){
                    order.push({i, j, k});
                    ripedTomatoes++;
                }
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
            int tomatoH = order.front()[0];
            int tomatoN = order.front()[1];
            int tomatoM = order.front()[2];

            int direction[6][3] = {{tomatoH-1, tomatoN, tomatoM}, {tomatoH+1, tomatoN, tomatoM}, {tomatoH, tomatoN-1, tomatoM},
             {tomatoH, tomatoN+1, tomatoM}, {tomatoH, tomatoN, tomatoM-1}, {tomatoH, tomatoN, tomatoM+1}};
            for (int d = 0; d < 6; d++){
                int tmpH = direction[d][0];
                int tmpN = direction[d][1];
                int tmpM = direction[d][2];
                // 좌표상으로 만족하고 토마토가 익지 않았다면 order에 추가
                if (tmpH >= 0 && tmpH < h && tmpN >= 0 && tmpN < n && tmpM >= 0 && tmpM < m){
                    if (tomatoes[tmpH][tmpN][tmpM] == 0){
                        order.push({tmpH, tmpN, tmpM});
                        tomatoes[tmpH][tmpN][tmpM] = 1;
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
    int M, N, H, numTomatoes = 0;
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < M; k++){
                cin >> tomatoes[i][j][k];
                if (tomatoes[i][j][k] != -1){
                    numTomatoes++;
                }
            }
        }
    }

    solve(H, N, M, numTomatoes);
}