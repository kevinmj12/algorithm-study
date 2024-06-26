#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int>* graph;
bool* visited;
queue<int> order;

void dfs(int v){
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < graph[v].size(); i++){
        if (!visited[graph[v][i]]){
            dfs(graph[v][i]);
        }
    }
}

void bfs(int v){
    order.push(v);
    visited[v] = true;
    
    while (!order.empty()){
        int tmp = order.front();
        for (int i = 0; i < graph[tmp].size(); i++){
            if (!visited[graph[tmp][i]]){
                order.push(graph[tmp][i]);
                visited[graph[tmp][i]] = true;
            }
        }
        printf("%d ", tmp);
        order.pop();
    }
}

int main(){
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    graph = new vector<int>[N+1];
    visited = new bool[N+1];
    
    for (int i = 0; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < N+1; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    for (int i = 0; i < N+1; i++){
        visited[i] = false;
    }
    dfs(V);

    printf("\n");

    for (int i = 0; i < N+1; i++){
        visited[i] = false;
    }
    bfs(V);
}