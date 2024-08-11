#include <iostream>
#include <queue>
using namespace std;

bool graph[501][501];
bool visited[501];

int solve(int n){
    queue<int> que;
    que.push(1);
    visited[1] = true;

    for (int i = 0; i < 2; i++){
        int size = que.size();
        for (int j = 0; j < size; j++){
            int cur = que.front();
            que.pop();
            for (int k = 1; k <= n; k++){
                if (graph[cur][k] && !visited[k]){
                    que.push(k);
                    visited[k] = true;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 2; i <= n; i++){
        if (visited[i]){
            answer++;
        }
    }
    return answer;
}

int main(){
    int n, m;
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        graph[a][b] = true;
        graph[b][a] = true;
    }

    cout << solve(n);
}