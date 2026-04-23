#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(vector<string> maps, int m, int n, int y, int x,
       vector<vector<bool>>& visited){
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    
    int food = 0;
    while (!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        food += maps[curY][curX] - '0';
        
        for (int d = 0; d < 4; d++){
            int nextY = curY + dirs[d][0];
            int nextX = curX + dirs[d][1];
            if (nextY < 0 || nextY >= m || nextX < 0 || nextX >= n ||
               maps[nextY][nextX] == 'X' || visited[nextY][nextX]){
                continue;
            }
            q.push({nextY, nextX});
            visited[nextY][nextX] = true;
        }
    }
    return food;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int m = maps.size();
    int n = maps[0].length();
    
    vector<vector<bool>> visited(m, vector<bool>(n));
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (!visited[i][j] && maps[i][j] != 'X'){
                answer.push_back(bfs(maps, m, n, i, j, visited));
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    if (answer.empty()){
        answer.push_back(-1);
    }
    
    return answer;
}