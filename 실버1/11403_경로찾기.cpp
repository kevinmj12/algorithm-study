#include <iostream>
using namespace std;
#define MAX 101
int graph[MAX][MAX];
int answer[MAX][MAX];
int visited[MAX];

void resetVisited(int n){
    for (int i = 1; i <= n; i++){
        visited[i] = 0;
    }
}

void dfs(int start, int curr, int n){
    for (int next = 1; next <= n; next++){
        if (!visited[next] && graph[curr][next]){
            visited[next] = 1;
            answer[start][next] = 1;
            dfs(start, next, n);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i<= N; i++){
        resetVisited(N);
        dfs(i, i, N);
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}