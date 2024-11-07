#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int graph[101][101];
bool visited[101][101];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for (int i = 0; i < rectangle.size(); i++){
        int dot1X = rectangle[i][0];
        int dot1Y = rectangle[i][1];
        int dot2X = rectangle[i][2];
        int dot2Y = rectangle[i][3];
        
        // 직사각형 내부를 -1로 채움(이동 불가)
        for (int x = dot1X*2+1; x < dot2X*2; x++){
            for (int y = dot1Y*2+1; y < dot2Y*2; y++){
                graph[y][x] = -1;
            }
        }
        // 직사각형 외곽은 1로 채움(이동 가능)
        for (int x = dot1X*2; x <= dot2X*2; x++){
            if (graph[dot1Y*2][x] != -1){
                graph[dot1Y*2][x] = 1;    
            }
            if (graph[dot2Y*2][x] != -1){
                graph[dot2Y*2][x] = 1;
            }
        }
        for (int y = dot1Y*2; y <= dot2Y*2; y++){
            if (graph[y][dot1X*2] != -1){
                graph[y][dot1X*2] = 1;
            }
            if (graph[y][dot2X*2] != -1){
                graph[y][dot2X*2] = 1;
            }
        }
    }
        
    // bfs로 탐색
    queue<pair<int, int>> que;
    que.push({characterY*2, characterX*2});
    visited[characterY*2][characterX*2] = true;

    while (!que.empty()){
        int size = que.size();
        for (int s = 0; s < size; s++){
            int curY = que.front().first;
            int curX = que.front().second;

            // cout << curY << " " << curX << " " << answer << endl;

            que.pop();

            if (curY == itemY*2 && curX == itemX*2){
                return answer/2;
            }

            for (int i = 0; i < 4; i++){
                int nextY = curY + dir[i][0];
                int nextX = curX + dir[i][1];

                if (nextY < 2 || nextY > 100 || nextX < 2 || nextX > 100 
                    || visited[nextY][nextX] == true){
                    continue;
                }
                if (graph[nextY][nextX] == 1){
                    que.push({nextY, nextX});
                    visited[nextY][nextX] = true;
                }
            }
        }
        answer++;   
    }
    
    
    return answer;
}