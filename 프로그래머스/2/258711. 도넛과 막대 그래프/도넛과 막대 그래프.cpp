#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 나가는 간선의 개수, 들어오는 간선의 개수 저장
int nodeInfo[1000001][2];
// 그래프 정보 저장
vector<int> graph[1000001];
// 방문 처리
bool visited[1000001];


vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    vector<int> nodes;
    for (int i = 0; i < edges.size(); i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        nodes.push_back(edges[i][0]);
        nodes.push_back(edges[i][1]);
        // 위상 정렬(나가는 간선의 개수, 들어오는 간선의 개수 count)
        nodeInfo[edges[i][0]][0]++;
        nodeInfo[edges[i][1]][1]++;
    }
    unique(nodes.begin(), nodes.end());
    sort(nodes.begin(), nodes.end());
    
    // 나가는 간선의 개수가 2 이상이면서 들어오는 간선의 개수가 0이라면 생성된 정점임
    int createdNode, numGraphs;
    for (int i = 0; i < nodes.size(); i++){
        if (nodeInfo[nodes[i]][0] >= 2 && nodeInfo[nodes[i]][1] == 0){
            createdNode = nodes[i];
            numGraphs = nodeInfo[nodes[i]][0];
            break;
        }
    }
    visited[createdNode] = true;
    
    int numStick = 0, numEight = 0;
    
    // BFS로 탐색하며 각 그래프의 모양을 판단
    for (int i = 0; i < nodes.size(); i++){
        int cur = nodes[i];
        bool isStick = false;
        bool isEight = false;
        queue<int> q;
        if (!visited[cur]){
            q.push(cur);
            
            while (!q.empty()){
                int node = q.front();
                visited[node] = true;
                q.pop();
                // 막대인지 판단
                if (graph[node].size() == 0){
                    isStick = true;
                }
                // 8자인지 판단
                else if (graph[node].size() == 2){
                    isEight = true;
                }
                
                for (int j = 0; j < graph[node].size(); j++){
                    int nextNode = graph[node][j];
                    if (!visited[nextNode]){
                        q.push(nextNode);
                    }
                }
            }
            if (isStick){
                numStick++;
            }
            else if (isEight){
                numEight++;
            }
        }
    }
    
    answer = {createdNode, numGraphs-numStick-numEight, numStick, numEight};
    
    
    return answer;
}