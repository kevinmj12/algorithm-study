#include <iostream>
#include <queue>
using namespace std;

bool graph[101][101];
bool visited[101];
int bfs(int n, int a, int b){
    queue<int> que;
    que.push(a);
    visited[a] = true;
    
    int answer = 0;
    while(!que.empty()){
        int size = que.size();
        for (int i = 0; i < size; i++){
            int cur = que.front();
            que.pop();

            if (cur == b){
                return answer;
            }

            for (int j = 1; j <= n; j++){
                if (!visited[j] && graph[cur][j]){
                    que.push(j);
                    visited[j] = true;
                }
            }
        }
        answer++;
    }
    return -1;
}

int main(){
    int n, a, b, m;
    cin >> n;
    cin >> a >> b;
    cin >> m;

    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        graph[x][y] = true;
        graph[y][x] = true;
    }

    cout << bfs(n, a, b);
}