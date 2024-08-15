#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int graph[101][101];
int items[101];

int dis[101];
bool visited[101];

void reset(int n){
    for (int i = 1; i <= n; i++){
        visited[i] = 0;
        dis[i] = INT_MAX;
    }
}

int solve(int n, int m, int target){
    reset(n);
    visited[target] = true;

    int totalItems = items[target];
    int plusVal = 0;
    while (true){
        int minDis = INT_MAX;
        int minIdx;

        for (int i = 1; i <= n; i++){
            if (graph[target][i] && !visited[i]){
                dis[i] = min(dis[i], graph[target][i]+plusVal);
            }
            if (!visited[i] && dis[i] < minDis){
                minDis = dis[i];
                minIdx = i;
            }
        }

        if (minDis > m) {
            break;
        }
        totalItems += items[minIdx];
        visited[minIdx] = true;
        target = minIdx;
        plusVal = minDis;
    }

    return totalItems;
}

int main(){
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++){
        cin >> items[i];
    }
    for (int i = 1; i <= r; i++){
        int a, b, l;
        cin >> a >> b >> l;
        graph[a][b] = l;
        graph[b][a] = l;
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++){
        answer = max(answer, solve(n, m, i));
    }
    cout << answer;
}