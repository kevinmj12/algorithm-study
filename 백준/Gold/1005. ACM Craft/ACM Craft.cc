#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int times[1001];
int before[1001];
vector<int> after[1001];
int visited[1001];
int dp[1001];

void reset(int N){
    for (int i = 1; i <= N; i++){
        before[i] = 0;
        after[i].clear();
        visited[i] = 0;
        dp[i] = 0;
    }
}

int solve(int w, int n){
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (before[i] == 0){
            q.push(i);
            dp[i] = times[i];
        }
    }

    while (true){
        int size = q.size();
        for (int i = 0; i < size; i++){
            int cur = q.front();
            q.pop();

            if (cur == w){
                return dp[cur];
            }

            for (int j = 0; j < after[cur].size(); j++){
                int next = after[cur][j];
                dp[next] = max(dp[next], dp[cur]+times[next]);
                
                visited[next]++;
                if (visited[next] == before[next]){
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;

    while (T--){
        int N, K;
        cin >> N >> K;
        reset(N);

        for (int i = 1; i <= N; i++){
            cin >> times[i];
        }
        for (int i = 1; i <= K; i++){
            int X, Y;
            cin >> X >> Y;

            before[Y]++;
            after[X].push_back(Y);
        }

        int W;
        cin >> W;
        cout << solve(W, N) << "\n";
    }   
}