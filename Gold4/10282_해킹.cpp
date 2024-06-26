#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


vector<pair<int, int>> graph[10001];
int times[10001];
bool visited[10001];

void reset(int n){
    for (int i = 1; i <= n; i++){
        graph[i].clear();
        times[i] = INT_MAX;
        visited[i] = false;
    }
}

void solve(int n, int trg){
    // 방문 처리
    visited[trg] = true;

    for (int i = 0; i < graph[trg].size(); i++){
        int next = graph[trg][i].first;
        if (!visited[next] && graph[trg][i].second + times[trg] < times[next]){
            times[next] = graph[trg][i].second + times[trg];
        }
    }

    // 다음으로 가장 먼저 해킹되는 컴퓨터를 찾음
    int minNextCom;
    int minNextTime = INT_MAX;
    for (int i = 0; i < n; i++){
        if (!visited[i] && times[i] < minNextTime){
            minNextCom = i;
            minNextTime = times[i];
        }
    }
    
    // 더 이상 없는 경우
    if (minNextTime == INT_MAX){
        return;
    }
    else{
        solve(n, minNextCom);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int n, d, c;
        cin >> n >> d >> c;

        reset(n);

        for (int i = 0; i < d; i++){
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }

        times[c] = 0;
        visited[c] = true;

        solve(n, c);

        int answerCnt = 0;
        int answerTime = 0;
        for (int i = 1; i <= n; i++){
            if (times[i] < INT_MAX){
                answerCnt++;
                answerTime = max(answerTime, times[i]);
            }
        }

        cout << answerCnt << " " << answerTime << "\n";
    }

}

