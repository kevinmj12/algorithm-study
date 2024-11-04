#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100001

vector<vector<int>> graph;
int root[MAX_N];

int Find(int a){
    if (a == root[a]){
        return a;
    }
    return root[a] = Find(root[a]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if (a < b){
        root[b] = a;
    }
    else{
        root[a] = b;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, a, b});
    }
    sort(graph.begin(), graph.end());

    for (int i = 1; i <= n; i++){
        root[i] = i;
    }

    int totalCosts = 0;
    int paths = 0;
    for (int i = 0; i < m; i++){
        if (paths >= n-2){
            break;
        }

        int c = graph[i][0];
        int a = graph[i][1];
        int b = graph[i][2];

        if (Find(a) == Find(b)){
            continue;
        }
        Union(a, b);
        paths++;

        totalCosts += c;
    }

    cout << totalCosts;
}