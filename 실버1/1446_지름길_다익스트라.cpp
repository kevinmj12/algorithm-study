#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int graph[10001][10001];
int visited[10001];

void reset(int d){
    for (int i = 0; i < d; i++){
        graph[i][i+1] = 1;
        for (int j = i+2; j <= d; j++){
            graph[i][j] = -1;
        }

        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, d;
    cin >> n >> d;

    reset(d);

    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (graph[a][b] == -1){
            graph[a][b] = c;
        }
        else{
            graph[a][b] = min(graph[a][b], c);
        }
    }

    int pos = 0;
    visited[0] = true;

    while (pos != d){
        for (int i = pos+1; i <= d; i++){
            if (graph[pos][i] != -1 && !visited[i]){
                if (graph[0][i] == -1){
                    graph[0][i] = graph[0][pos]+graph[pos][i];
                }
                else{
                    graph[0][i] = min(graph[0][i], graph[0][pos]+graph[pos][i]);
                }
            }
        }
        int shortestH;
        int shortestD = INT_MAX;
        for (int i = 1; i <= d; i++){
            if (graph[0][i] != -1 && !visited[i] && graph[0][i] < shortestD){
                shortestH = i;
                shortestD = graph[0][i];
            }
        }
        pos = shortestH;
        visited[pos] = true;
        
    }

    cout << graph[0][pos];
}