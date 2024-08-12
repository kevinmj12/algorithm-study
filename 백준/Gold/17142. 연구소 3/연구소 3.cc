#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, numViruses, numAreas;
int answer = 5000;
int graph[51][51];
bool visited[51][51];
vector<pair<int, int>> viruses;
int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void solve(vector<int> selected);

void resetVisited(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            visited[i][j] = false;
        }
    }
}

void backTracking(int idx, vector<int> selected){
    if (selected.size() == m){
        solve(selected);
        return;
    }
    for (int i = idx; i < numViruses; i++){
        selected.push_back(i);
        backTracking(i+1, selected);
        selected.pop_back();
    }
}

void solve(vector<int> selected){
    resetVisited();
    queue<pair<int, int>> que;
    int cnt = numViruses;
    int date = 0;

    for (int i = 0; i < m; i++){
        que.push(viruses[selected[i]]);
        visited[viruses[selected[i]].first][viruses[selected[i]].second] = true;
    }

    while (!que.empty() && cnt < numAreas){
        date++;
        int size = que.size();
        for (int i = 0; i < size; i++){
            int curY = que.front().first;
            int curX = que.front().second;
            que.pop();

            for (int j = 0; j < 4; j++){
                int nextY = curY + direction[j][0];
                int nextX = curX + direction[j][1];
                if (nextY < 1 || nextY > n || nextX < 1 || nextX > n 
                || visited[nextY][nextX] || graph[nextY][nextX] == 1){
                    continue;
                }
                if (graph[nextY][nextX] == 0){
                    cnt++;
                }
                que.push({nextY, nextX});
                visited[nextY][nextX] = true;
            }
        }
    }

    if (cnt == numAreas){
        answer = min(answer, date);
    }
}

int main(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 2){
                viruses.push_back({i, j});
                numViruses++;
                numAreas++;
            }
            else if (graph[i][j] == 0){
                numAreas++;
            }
        }
    }

    backTracking(0, {});
    if (answer == 5000){
        cout << -1;
    }
    else{
        cout << answer;
    }
}