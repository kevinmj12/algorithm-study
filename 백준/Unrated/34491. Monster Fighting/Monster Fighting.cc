#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> beaver[200001];
pair<int, int> enemies[200001];
vector<int> ableEnemies[200001];
int assign[200001];
bool visited[200001];

void reset(int N){
    for (int i = 1; i <= N; i++){
        ableEnemies[i].clear();
        assign[i] = 0;
        visited[i] = false;
    }
}

bool dfs(int a){
    for (int i = 0; i < ableEnemies[a].size(); i++){
        int target = ableEnemies[a][i];
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

bool canDefeat(int p, int s, int q, int t) {    
    if (p >= q) {
        return true;
    }
    
    if (s == t && p * 2 >= q) {
        return true;
    }
    
    return false;
}

int main(){
    int T;
    cin >> T;

    while (T--){
        int N;
        cin >> N;

        reset(N);

        for (int i = 1; i <= N; i++){
            int p, s;
            cin >> p >> s;
            beaver[i] = {p, s};
        }
        for (int i = 1; i <= N; i++){
            int q, t;
            cin >> q >> t;
            enemies[i] = {q, t};
        }

        for (int i = 1; i <= N; i++){
            int p = beaver[i].first;
            int s = beaver[i].second;

            for (int j = 1; j <= N; j++){
                int q = enemies[j].first;
                int t = enemies[j].second;

                if (canDefeat(p, s, q, t)){
                    ableEnemies[i].push_back(j);
                }
            }
        }

        int answer = 0;
        for (int i = 1; i <= N; i++){
            for (int i = 0; i < N; i++){
                visited[i] = false;
            }
            if (dfs(i)){
                answer++;
            }
        }

        if (answer == N){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}