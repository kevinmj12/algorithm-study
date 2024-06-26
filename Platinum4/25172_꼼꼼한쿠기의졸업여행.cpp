#include <iostream>
using namespace std;
int root[200001];

int find(int x){
    if (root[x] == x){
        return x;
    }
    else{
        return find(root[x]);
    }
}

void merge(int x, int y){
    root[y] = x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        root[i] = i;
    }

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        merge(a, b);
    }

    int j = 1;
    int tmp = 0;
    while (true){
        tmp++;
        if (j == root[j]){
            break;
        }
        j = root[j];
    }
    if (tmp == n){
        cout << "CONNECT" << "\n";
    }
    else{
        cout << "DISCONNECT" << "\n";
    }

    ///////

    for (int i = 0; i < n; i++){
        int k;
        cin >> k;

        root[k] = -1;

        int j = 1;
        for (j; j <= n; j++){
            if (root[j] != -1){
                break;
            }
        }

        if (j > n){
            cout << "DISCONNECT" << "\n";
        }
        else{
            int tmp = 1;
            while (root[j] != -1){
                tmp++;
                if (j == root[j]){
                    break;
                }
                j = root[j];
            }
            if (tmp == n-i){
                cout << "CONNECT" << "\n";
            }
            else{
                cout << "DISCONNECT" << "\n";
            }
        }
    }

}