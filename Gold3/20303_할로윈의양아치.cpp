#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int candy[30001];
vector<int> friends[30001];
bool visited[30001];
int dp[30001][3001];

int n, m, k;

// 우는 아이들의 수와 사탕의 수를 BFS로 탐색해 반환해주는 함수
pair<int, int> bfs(int a){
    int numFriends = 0;
    int candies = 0;
    queue<int> q;
    q.push(a);
    visited[a] = true;

    while(!q.empty()){
        int child = q.front();
        q.pop();
        numFriends++;
        candies += candy[child];

        for (int i = 0; i < friends[child].size(); i++){
            int next = friends[child][i];
            if (!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return make_pair(numFriends, candies);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> candy[i];
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    // 우는 아이의 수와 사탕의 수 정보를 vec에 저장
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            vec.push_back(bfs(i));
        }
    }

    // dp로 최대 사탕의 수를 구하기 (배낭 문제)
    for (int i = 1; i <= vec.size(); i++){
        for (int j = 1; j < vec[i-1].first; j++){
            dp[i][j] = dp[i-1][j];
        }
        for (int j = vec[i-1].first; j < k; j++){
            dp[i][j] = max(dp[i-1][j], vec[i-1].second+dp[i-1][j-vec[i-1].first]);
        }
    }

    cout << dp[vec.size()][k-1];
}