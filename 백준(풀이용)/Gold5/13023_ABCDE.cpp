#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> friends[2000];
bool visited[2000];
bool isABCDE = false;


void solve(int target, int size){
    if (size >= 5){
        isABCDE = true;
        return;
    }
    for (int i = 0; i < friends[target].size(); i++){
        int next = friends[target][i];
        if (!visited[next]){
            visited[next] = true;
            solve(next, size+1);
            visited[next] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 0; i < n; i++){
        visited[i] = true;
        solve(i, 1);
        visited[i] = false;
        if (isABCDE){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}