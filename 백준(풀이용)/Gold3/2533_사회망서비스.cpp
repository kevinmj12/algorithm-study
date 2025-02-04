#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<int> graph[1000001];
int visited[1000001];
int answer = 0;

bool dfs(int pos){
    // 방문 처리
    visited[pos] = true;

    bool mustEarlyAdapter = false;
    for (int i = 0; i < graph[pos].size(); i++){
        int next = graph[pos][i];
        if (!visited[next]){
            // 자식이 얼리 어답터가 아니라면
            if (!dfs(next)){
                mustEarlyAdapter = true;
            }
        }
    }
    // 반드시 얼리 어답터여야 하는 경우
    if (mustEarlyAdapter){
        answer++;
        return true;
    }
    else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    cout << answer;

}