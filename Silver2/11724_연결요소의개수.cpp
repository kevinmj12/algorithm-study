#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
int nodes[MAX][MAX];
int visited[MAX];


int solve(int n){
    int ans = 0;
    for (int i = 1; i < n+1; i++){
        if (visited[i] == 0){
            queue<int> connected;
            connected.push(i);
            visited[i] = 1;
            while (!connected.empty()){
                int tmp = connected.front();
                for (int j = 1; j < n+1; j++){
                    if (visited[j] == 0 && nodes[tmp][j] == 1){
                        connected.push(j);
                        visited[j] = 1;
                    }
                }
                connected.pop();
            }
            ans++;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // nodes, visited 초기화
    for (int i = 1; i < n+1; i++){
        visited[i] = 0;
        for (int j = 1; j < n+1; j++){
            nodes[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        nodes[u][v] = 1;
        nodes[v][u] = 1;
    }

    cout << solve(n);
    
}