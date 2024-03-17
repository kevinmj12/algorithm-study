#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int graph[21][21];
bool visited[21][21];
int passengers[401][4];
int n, m, fuel, taxiY, taxiX;
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void resetVisited(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            visited[i][j] = false;
        }
    }
}

int bfsPassenger(){
    resetVisited();
    queue<pair<int, int>> q;
    q.push({taxiY, taxiX});
    visited[taxiY][taxiX] = true;
    
    int findPassenger = 0;
    while (!q.empty() && fuel >= 0){
        int size = q.size();
        for (int j = 0; j < size; j++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            // 승객이 존재한다면
            if (graph[y][x] > 0){
                if (findPassenger){
                    if (y > taxiY || (y == taxiY && x > taxiX)){
                        continue;
                    }
                }
                findPassenger = graph[y][x];
                taxiY = y; taxiX = x;
            }
            
            for (int i = 0; i < 4; i++){
                int nextY = y+dir[i][0];
                int nextX = x+dir[i][1];
                if (0 < nextY && nextY <= n && 0 < nextX && nextX <= n
                && !visited[nextY][nextX] && graph[nextY][nextX] != -1){
                    q.push({nextY, nextX});
                    visited[nextY][nextX] = true;
                }
            }
        }
        if (findPassenger){
            graph[taxiY][taxiX] = 0;
            return findPassenger;
        }
        fuel--;
    }
    return findPassenger;
}

bool bfsDestination(int pasIndex){
    resetVisited();
    queue<pair<int, int>> q;
    q.push({taxiY, taxiX});
    visited[taxiY][taxiX] = true;

    int f = fuel;
    while (!q.empty() && fuel >= 0){
        int size = q.size();
        for (int j = 0; j < size; j++){
            int y = q.front().first;
            int x = q.front().second;
            
            q.pop();

            if (passengers[pasIndex][2] == y && passengers[pasIndex][3] == x){
                taxiY = y; taxiX = x;
                fuel += (f-fuel)*2;
                return true;
            }

            for (int i = 0; i < 4; i++){
                int nextY = y+dir[i][0];
                int nextX = x+dir[i][1];
                if (0 < nextY && nextY <= n && 0 < nextX && nextX <= n
                && !visited[nextY][nextX] && graph[nextY][nextX] != -1){
                    q.push({nextY, nextX});
                    visited[nextY][nextX] = true;
                }
            }
        }
        fuel--;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> fuel;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int g;
            cin >> g;
            g == 0 ? graph[i][j] = 0 : graph[i][j] = -1;
        }
    }

    cin >> taxiY >> taxiX;

    for (int i = 1; i <= m; i++){
        for (int j = 0; j < 4; j++){
            cin >> passengers[i][j];
        }
        graph[passengers[i][0]][passengers[i][1]] = i;
    }

    for (int i = 0; i < m; i++){
        int passenger = bfsPassenger();
        if (passenger == 0){
            cout << -1;
            return 0;
        }
        bool canMove = bfsDestination(passenger);
        if (!canMove){
            cout << -1;
            return 0;
        }
    }
    cout << fuel;
    return 0;
}