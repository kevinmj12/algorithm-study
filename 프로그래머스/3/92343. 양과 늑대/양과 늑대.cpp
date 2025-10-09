#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> board[18];
int parent[18];
bool visited[18];

int sheep = 0;
int wolf = 0;
int answer = 0;

void dfs(int cur, vector<int> path, int s, int w, vector<int> info){
    if (info[cur] == 0){
        s++;
    }
    else{
        w++;
        if (w >= s){
            return;
        }
    }
    answer = max(answer, s);
    
    for (int next: board[cur]){
        path.push_back(next);
    }
    
    for (int i = 0; i < path.size(); i++){
        int next = path[i];
        if (!visited[next]){
            visited[next] = true;
            dfs(next, path, s, w, info);
            visited[next] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) { 
    for (int i = 0; i < edges.size(); i++){
        board[edges[i][0]].push_back(edges[i][1]);
    }
    
    dfs(0, {}, 0, 0, info);
    
    return answer;
}