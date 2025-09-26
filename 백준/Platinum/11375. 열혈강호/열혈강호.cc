#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> able[1001];
int assign[1001];
bool visited[1001];

bool dfs(int a){
    for (int i = 0; i < able[a].size(); i++){
        int target = able[a][i];
        if (visited[target]){
            continue;
        }

        visited[target] = true;
 
        if (assign[target] == 0 || dfs(assign[target])){
            assign[target] = a;
            return true;
        }
    }
    return false;
}

int main(){
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        int counts;
        cin >> counts;
        for (int j = 0; j < counts; j++){
            int task;
            cin >> task;

            able[i].push_back(task);
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            visited[j] = false;
        }
        if (dfs(i)){
            answer++;
        }
        
        if (answer == N || answer == M){
            break;
        }
    }

    cout << answer;
}