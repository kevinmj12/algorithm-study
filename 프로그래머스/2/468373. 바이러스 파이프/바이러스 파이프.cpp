#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int maxNode = 0;

vector<bool> spread(vector<bool> nodes, vector<vector<int>> graph, int type){
    vector<bool> visited(nodes.size(), false);
    queue<int> q;
    for (int i = 1; i < nodes.size(); i++){
        if (nodes[i]){
            q.push(i);
            visited[i] = true;
        }
    }
    
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i = 1; i < nodes.size(); i++){
            if (graph[cur][i] == type && !visited[i]){
                visited[i] = true;
                nodes[i] = true;
                q.push(i);
            }
        }
    }
    
    return nodes;
}

void backtracking(vector<vector<int>> graph, int before, int round, int k,
                vector<bool> nodes, vector<int> trace){
    // 종료 조건
    if (round == k){
        int totalNodes = 0;
        
        for (int i = 1; i < nodes.size(); i++){
            if (nodes[i]){
                totalNodes++;
            }
        }
        
        maxNode = max(maxNode, totalNodes);
        return;
    }
    vector<bool> curNodes = nodes;
    // A를 열었다 닫음
    if (before != 1){
        nodes = spread(curNodes, graph, 1);
        trace.push_back(1);
        backtracking(graph, 1, round+1, k, nodes, trace);
        trace.pop_back();
    }
    // B를 열었다 닫음
    if (before != 2){
        nodes = spread(curNodes, graph, 2);
        trace.push_back(2);
        backtracking(graph, 2, round+1, k, nodes, trace);
        trace.pop_back();
    }
    // C를 열었다 닫음
    if (before != 3){
        nodes = spread(curNodes, graph, 3);
        trace.push_back(3);
        backtracking(graph, 3, round+1, k, nodes, trace);
        trace.pop_back();
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < edges.size(); i++){
        int first = edges[i][0];
        int second = edges[i][1];
        int type = edges[i][2];
        graph[first][second] = type;
        graph[second][first] = type;
    }
    
    vector<bool> nodes(n+1, false);
    nodes[infection] = true;
    
    backtracking(graph, 0, 0, k, nodes, {});
    
    answer = maxNode;
    
    return answer;
}