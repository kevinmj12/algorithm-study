#include <string>
#include <vector>
#include <algorithm>
#define MAX_FEE 30000000

using namespace std;

int minFee[201][201];

int findNext(int n, vector<int> dist, vector<bool> visited){
    int next = -1;
    int minDist = MAX_FEE;
    for (int i = 1; i <= n; i++){
        if (!visited[i] && dist[i] < minDist){
            next = i;
            minDist = dist[i];
        }
    }
    
    return next;
}

void dijkstra(int n, int s, vector<vector<pair<int, int>>> path){
    vector<int> dist(n+1, MAX_FEE);
    vector<bool> visited(n+1, false);
    dist[s] = 0;
    
    int cur = s;
    while (true){
        minFee[s][cur] = dist[cur];
        minFee[cur][s] = dist[cur];
        visited[cur] = true;
        for (int i = 0; i < path[cur].size(); i++){
            int n = path[cur][i].first;
            int fee = path[cur][i].second;
            dist[n] = min(dist[n], dist[cur] + fee);
        }
        
        int next = findNext(n, dist, visited);

        if (next == -1){
            return;
        }
        cur = next;
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX_FEE*3;
    
    vector<vector<pair<int ,int>>> path(n+1, vector<pair<int, int>>());
    for (vector<int> fare: fares){
        path[fare[0]].push_back({fare[1], fare[2]});
        path[fare[1]].push_back({fare[0], fare[2]});
    }
    
    for (int i = 1; i < n; i++){
        for (int j = i+1; j <= n; j++){
            minFee[i][j] = MAX_FEE;
            minFee[j][i] = MAX_FEE;
        }
    }
    
    for (int i = 1; i < n; i++){
        dijkstra(n, i, path);
    }
    
    for (int i = 1; i <= n; i++){
        int tmpFee = 0;
        tmpFee += minFee[s][i];
        tmpFee += minFee[i][a];
        tmpFee += minFee[i][b];
        
        answer = min(answer, tmpFee);
    }
    
    return answer;
}