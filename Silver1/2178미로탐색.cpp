#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int **maze;
int N, M;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int answer = 0;

// BFS로 최단 거리 찾기
void solve(int y, int x){
    queue<pair<int, int>> order;
    order.push({y,x});
    maze[y][x] = 0;

    while (!order.empty()){
        answer++;
        int size = order.size();
        for (int i = 0; i < size; i++){
            for (int j = 0; j < 4; j++){
                int nextY = order.front().first + dir[j][0], nextX = order.front().second +dir[j][1];
                if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M 
                && maze[nextY][nextX] == 1){
                    // N, M에 도달한 경우
                    if (nextY == N-1 && nextX == M-1){
                        printf("%d", answer+1);
                        return;
                    }
                    // 이외의 경우 큐에 push
                    order.push({nextY, nextX});
                    // 방문한 곳의 maze는 0으로 처리
                    maze[nextY][nextX] = 0;
                }
            }
            order.pop();
        }
    }
    // 도착하지 못한경우(문제에는 항상 이동 가능하다고 되어있음)
    printf("-1");
    return;
}

int main(){
    scanf("%d %d", &N, &M);

    // maze와 visited 공간 설정
    maze = new int*[N];

    for (int i = 0; i < N; i++){
        maze[i] = new int[M];
    }

    // maze와 visited 값 채워넣기
    for (int i = 0; i < N; i++){
        string str;
        cin >> str;
        for (int j = 0; j < M; j++){
            maze[i][j] = str[j]-'0';
        }
    }
    
    solve(0, 0);

}