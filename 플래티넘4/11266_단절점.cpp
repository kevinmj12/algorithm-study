#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10001
vector<int> graph[MAX];
vector<int> rootNode;
int visited[MAX];
int dfsNumber[MAX];
int dfsOrder = 1;
int back[MAX];
int articulations[MAX];

void dfsTree(int node, int numNodes){
    // 방문 처리
    visited[node] = 1;
    // dfsNumber 처리
    dfsNumber[node] = dfsOrder;
    dfsOrder++;
    // back 기본값 처리
    back[node] = dfsNumber[node];

    // 기본 처리 이후 DFS 탐색
    for (int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if (!visited[next]){
            // 재귀로 계속 탐색
            dfsTree(next, numNodes);

            // 탐색 이후 articulation 및 back 처리
            if (back[next] >= dfsNumber[node]){
                articulations[node]++;
            }
            else{
                back[node] = min(back[node], back[next]);
            }
        }
        else {
            // back 처리
            back[node] = min(back[node], dfsNumber[next]);
        }
        
    }

}

void printAnswer(int numNodes){
    vector<int> answer;
    // 이후 노드들은 한 번만 카운트되어도 단절점
    int rootIdx = 0;
    for (int i = 1; i <= numNodes; i++){
        if (i == rootNode[rootIdx]){
            if (articulations[i] >= 2){
                answer.push_back(i);
            }
            if (rootIdx < rootNode.size()-1){
                rootIdx++;
            }
        }
        else{
            if (articulations[i]){
                answer.push_back(i);
            }
        }
    }

    cout << answer.size() << "\n";

    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int v, e;
    cin >> v >> e;

    // 입력을 받음
    for (int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    

    for (int i = 1; i <= v; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    for (int i = 1; i <= v; i++){
        if (!visited[i]){
            rootNode.push_back(i);
            dfsTree(i, v);
        }
    }
    printAnswer(v);
}