#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class bridgeInfo{
public:
    int desti;
    int weight;
    
    bridgeInfo(int d, int c){
        desti = d;
        weight = c;
    }
};

int n, m, s, e;
vector<bridgeInfo> graph[100001];
bool visited[100001];

void resetVisited(){
    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }
}

bool bfs(int bb){
    resetVisited();
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()){
        int cur = q.front();
        if (cur == e){
            return true;
        }
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++){
            if (!visited[graph[cur][i].desti] && bb <= graph[cur][i].weight){
                q.push(graph[cur][i].desti);
                visited[graph[cur][i].desti] = true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    cin >> s >> e;
    for (int i = 0; i < m; i++){
        int h1, h2, k;
        cin >> h1 >> h2 >> k;
        
        graph[h1].push_back(bridgeInfo(h2, k));
        graph[h2].push_back(bridgeInfo(h1, k));
    }

    
    int left = 0;
    int right = 1000000;
    while (left <= right){
        int mid = (left + right) / 2;
        if (bfs(mid) == true){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    if (right == -1){
        cout << 0;
    }
    else{
        cout << right;
    }
}