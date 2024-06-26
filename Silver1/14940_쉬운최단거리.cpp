#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000
int map[MAX][MAX];
int answer[MAX][MAX];
int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n, m;

void solve(int y, int x){
    queue<pair<int, int>> land;
    land.push({y,x});
    
    int distance = 1;
    // land가 비어 있다면 모든 거리 계산 종료
    while (!land.empty()){
        int size = land.size();
        for (int i = 0; i < size; i++){
            pair<int, int> presentLand = land.front();
            for (int j = 0; j < 4; j++){
                int nextY = presentLand.first + direction[j][0];
                int nextX = presentLand.second + direction[j][1];
                // 범위를 벗어나거나 중복된 경우
                if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || answer[nextY][nextX] != -1){
                    continue;
                }
                // 이동할 수 없는 땅(0)인 경우
                else if (map[nextY][nextX] == 0){
                    answer[nextY][nextX] = 0;
                }
                // 이동할 수 있는 땅(1)인 경우
                else{
                    answer[nextY][nextX] = distance;
                    land.push({nextY, nextX});
                }
            }
            land.pop();
        }
        distance++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    cin >> n >> m;

    int destinationY; int destinationX;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // 입력을 받으면서 목표지점을 저장
            cin >> map[i][j];
            if (map[i][j] == 2){
                destinationY = i;
                destinationX = j;
                answer[i][j] = 0;
            }
            // answer 배열 초기화
            else if (map[i][j] == 1){
                answer[i][j] = -1;
            }
            else if (map[i][j] == 0){
                answer[i][j] = 0;
            }
        }
    }

    solve(destinationY, destinationX);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}