#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nodes[10001];
vector<int> tree[10001];

int dp[10001][2];
bool visited[10001];
vector<int> answer;

void resetVisited(int n){
    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }
}

void dfs(int cur){
    // dp[1][0]은 1번 노드가 포함되지 않았을 때 최댓값
    // dp[1][1]은 1번 노드가 포함되었을 때 최댓값
    dp[cur][0] = 0;
    dp[cur][1] = nodes[cur];
    visited[cur] = true;

    for (int i = 0; i < tree[cur].size(); i++){
        int next = tree[cur][i];
        if (!visited[next]){
            dfs(next);
            dp[cur][0] += max(dp[next][0], dp[next][1]);
            dp[cur][1] += dp[next][0];
        }    
    }
}

void trace(int cur, int prev){
    if (dp[cur][1] > dp[cur][0] && !visited[prev]){
        answer.push_back(cur);
        visited[cur] = true;
    }

    for (int i = 0; i < tree[cur].size(); i++){
        int next = tree[cur][i];
        if (next != prev){
            trace(next, cur);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> nodes[i];
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);
    resetVisited(n);
    trace(1, 0);
    sort(answer.begin(), answer.end());

    cout << max(dp[1][0], dp[1][1]) << "\n";
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
}