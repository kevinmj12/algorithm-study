#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 600000

int graph[501][501];
int minDistance[501];
vector<int> minDPath[501];
bool visited[501];

void resetGraph(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            graph[i][j] = MAX;
        }
    }
}

void resetDistance(int n){
    for (int i = 0; i < n; i++){
        minDistance[i] = MAX;
        minDPath[i].clear();
    }
}

void resetVisited(int n){
    for (int i = 0; i < n; i++){
        visited[i] = {};
    }
}

int findNext(int n){
    int next = -1;
    int nextDistance = MAX;

    for (int i = 0; i < n; i++){
        if (!visited[i] && minDistance[i] < nextDistance){
            next = i;
            nextDistance = minDistance[i];
        }
    }

    return next;
}

int dijkstra(int n, int s, int d){
    minDistance[s] = 0;
    int cur = s;

    while (cur != -1 && cur != d){
        visited[cur] = true;
    
        for (int i = 0; i < n; i++){
            if (graph[cur][i] + minDistance[cur] < minDistance[i]){
                minDistance[i] = graph[cur][i] + minDistance[cur];
                minDPath[i].clear();
                minDPath[i].push_back(cur);
            }
            else if (graph[cur][i] + minDistance[cur] == minDistance[i]){
                minDPath[i].push_back(cur);
            }
        }
    
        cur = findNext(n);
    }

    if (cur == -1){
        return cur;
    }
    return minDistance[d];
}

void trace(int d){
    queue<int> q;
    q.push(d);
    visited[d] = true;

    while (!q.empty()){
        int cur = q.front();
        q.pop();

        for (auto i : minDPath[cur]){
            graph[i][cur] = MAX;
            if (visited[i]){
                continue;
            }
            q.push(i);
            visited[i] = true;
        }   
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, S, D;
    while (true){
        cin >> N >> M;
        if (N == 0 && M == 0){
            return 0;
        }
        resetGraph(N);
        resetDistance(N);
        resetVisited(N);

        cin >> S >> D;
        for (int i = 0; i < M; i++){
            int U, V, P;
            cin >> U >> V >> P;
            
            graph[U][V] = P;
        }

        int minAnswer = dijkstra(N, S, D);
        if (minAnswer == -1){
            cout << "-1\n";
            continue;
        }
        
        resetVisited(N);
        trace(D);

        resetDistance(N);
        resetVisited(N);

        int almostAnswer = dijkstra(N, S, D);

        cout << almostAnswer << "\n";
    }
}