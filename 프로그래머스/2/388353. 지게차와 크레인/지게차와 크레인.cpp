#include <string>
#include <vector>
#include <queue>

using namespace std;

char graph[52][52];
bool visited[52][52];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void resetVisited(){
    for (int i = 0; i < 52; i++){
        for (int j = 0; j < 52; j++){
            visited[i][j] = false;
        }
    }
}

void bfs(int n, int m, string request){
    char r = request[0];
    // 지게차
    if (request.size() == 1){
        char tmpGraph[52][52];
        
        for (int i = 0; i <= n+1; i++){
            for (int j = 0; j <= m+1; j++){
                tmpGraph[i][j] = graph[i][j];
            }
        }
        
        resetVisited();
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        while(!q.empty()){
            int curY = q.front().first;
            int curX = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++){
                int nextY = curY + dir[d][0];
                int nextX = curX + dir[d][1];
                if (nextY < 0 || nextY > n+1 || nextX < 0 || nextX > m+1
                   || visited[nextY][nextX]){
                    continue;
                }
                if (graph[nextY][nextX] == '0'){
                    q.push({nextY, nextX});
                    visited[nextY][nextX] = true;
                }
                else if (graph[nextY][nextX] == r){
                    tmpGraph[nextY][nextX] = '0';
                }
            }
        }
        for (int i = 0; i <= n+1; i++){
            for (int j = 0; j <= m+1; j++){
                graph[i][j] = tmpGraph[i][j];
            }
        }
    }
    // 크레인
    else{
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (graph[i][j] == r){
                    graph[i][j] = '0';
                }
            }
        }
    }
}

int getAnswer(int n, int m){
    int rtn = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (graph[i][j] != '0'){
                rtn++;
            }
        }
    }
    
    return rtn;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    int n = storage.size();
    int m = storage[0].size();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            graph[i][j] = storage[i-1][j-1];
        }
    }
    for (int i = 0; i <= n+1; i++){
        graph[i][0] = '0';
        graph[i][m+1] = '0';
    }
    for (int j = 0; j <= m+1; j++){
        graph[0][j] = '0';
        graph[n+1][j] = '0';
    }
    
    for (int i = 0; i < requests.size(); i++){
        bfs(n, m, requests[i]);
    }
    
    
    answer = getAnswer(n, m);
    return answer;
}