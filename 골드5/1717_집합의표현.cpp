#include <iostream>
using namespace std;
#define MAX 1000001

int root[MAX];


int find(int x){
    if (root[x] == x){
        return x;
    }
    else{
        return root[x] = find(root[x]);
    }
}

void merge(int x, int y){
    x = find(x);
    y = find(y);

    root[y] = x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++){
        root[i] = i;
    }

    while (m--){
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0){
            merge(b, c);
        }
        else{
            if (find(b) == find(c)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}