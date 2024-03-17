#include <iostream>
#include <vector>
using namespace std;
int n, m;

void solve(int start, int length, vector<int> v){
    if (length > m){
        for (int i = 0; i < m; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = start; i <= n; i++){
        v.push_back(i);
        solve(i, length+1, v);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    solve(1, 1, {});
}