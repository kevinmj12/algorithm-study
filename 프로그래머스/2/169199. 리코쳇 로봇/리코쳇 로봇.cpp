#include <string>
#include <vector>
#include <queue>
#include <vector>

using namespace std;

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(vector<vector<int>> graph, int rY, int rX, int gY, int gX){
    queue<pair<int, int>> q;
    int m = graph.size();
    int n = graph[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    
    int cnt = 0;
    q.push({rY, rX});
    visited[rY][rX] = true;
    
    while (!q.empty()){
        int size = q.size();
        for (int i = 0; i < size; i++){
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();
            
            if (curY == gY && curX == gX){
                return cnt;
            }
            
            for (int d = 0; d < 4; d++){
                int nextY = curY;
                int nextX = curX;
                while (true){
                    if (nextY + dirs[d][0] < 0 || nextY + dirs[d][0] >= m ||
                       nextX + dirs[d][1]< 0 || nextX + dirs[d][1] >= n || 
                        graph[nextY + dirs[d][0]][nextX + dirs[d][1]] == -1){
                        break;
                    }
                    nextY += dirs[d][0];
                    nextX += dirs[d][1];
                }
                if (visited[nextY][nextX]){
                    continue;
                }
                q.push({nextY, nextX});
                visited[nextY][nextX] = true;
            }
        }
        cnt++;
    }
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    
    vector<vector<int>> graph(board.size(), vector<int>(board[0].length()));
    
    int rY, rX, gY, gX;
    
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].length(); j++){
            if (board[i][j] == '.'){
                graph[i][j] = 0;
            }
            else if (board[i][j] == 'D'){
                graph[i][j] = -1;
            }
            else if (board[i][j] == 'R'){
                rY = i;
                rX = j;
                graph[i][j] = 0;
            }
            else if (board[i][j] == 'G'){
                gY = i;
                gX = j;
                graph[i][j] = 0;
            }
        }
    }
    
    answer = bfs(graph, rY, rX, gY, gX);
    
    return answer;
}