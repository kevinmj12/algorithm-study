#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool graph[51][51];
bool visited[51];

void resetVisited(int n){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            visited[i] = false;
        }
    }
}

int solve(int n, int a){
    queue<int> que;
    que.push(a);
    visited[a] = true;
    int rank = 0;

    while (!que.empty()){
        rank++;
        int size = que.size();
        while (size--){
            int target = que.front();
            que.pop();

            for (int i = 1; i <= n; i++){
                if (graph[target][i] && !visited[i]){
                    que.push(i);
                    visited[i] = true;
                }    
            }
        }
    }

    return rank-1;
}

int main(){
    int n;
    cin >> n;

    while (true){
        int a, b;
        cin >> a >> b;
        if (a == -1){
            break;
        }

        graph[a][b] = true;
        graph[b][a] = true;
    }

    vector<pair<int, int>> scores;
    for (int i = 1; i <= n; i++){
        resetVisited(n);
        int score = solve(n, i);
        scores.push_back({score, i});
    }
    sort(scores.begin(), scores.end());

    int answer = scores[0].first;
    vector<int> answerList;
    for (int i = 0; i < scores.size(); i++){
        if (scores[i].first == answer){
            answerList.push_back(scores[i].second);
        }
        else{
            break;
        }
    }

    cout << answer << " " << answerList.size() << "\n";
    for (int i = 0; i < answerList.size(); i++){
        cout << answerList[i] << " ";
    }
}