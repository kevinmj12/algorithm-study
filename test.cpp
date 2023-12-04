#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10001
int** graph;
int* visited;
int* dfsNumber;
int* back;
int dfsOrder;
vector<int> articulations;

void dfsTree(int node, int numNodes){
    // 방문 처리
    visited[node] = 1;
    // dfsNumber 처리
    dfsNumber[node] = dfsOrder;
    dfsOrder++;
    // back 기본값 처리
    back[node] = dfsNumber[node];

    // 기본 처리 이후 DFS 탐색
    for (int next = 1; next <= numNodes; next++){
        if (graph[node][next]){
            if (!visited[next]){
                // 그래프의 선을 끊어버림
                graph[node][next] = 0;
                graph[next][node] = 0;
                // 재귀로 계속 탐색
                dfsTree(next, numNodes);

                // 탐색 이후 articulation 및 back 처리
                if (back[next] >= dfsNumber[node]){
                    articulations.push_back(node);
                }
                else{
                    back[node] = min(back[node], back[next]);
                }
            }
            else {
                // 그래프의 선을 끊어버림
                graph[node][next] = 0;
                graph[next][node] = 0;
                // back 처리
                back[node] = min(back[node], dfsNumber[next]);
            }
        }
    }

}

void printAnswer(){
    sort(articulations.begin(), articulations.end());
    int cnt = 0;
    int curr = 0;
    vector<int> answer;
    for (int i = 1; i < articulations.size(); i++){
        if (curr != articulations[i]){
            cnt++;
            curr = articulations[i];
            answer.push_back(curr);
        }
    }

    cout << cnt << "\n";
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    graph = new int*[v+1];
    visited = new int[v+1];
    dfsNumber = new int[v+1];
    back =  new int[v+1];
    for (int i = 1; i <= v; i++){
        visited[i] = 0;
        dfsNumber[i] = 0;
        back[i] = 0;
        graph[i] = new int[v+1];
        for (int j = 1; j <= v; j++){
            graph[i][j] = 0;
        }
    }

    // 입력을 받음
    for (int i = 1; i <= e; i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int i = 1; i <= v; i++){
        if (!visited[i]){
            dfsOrder = 1;
            dfsTree(i, v);
        }
    }
    printAnswer();
}