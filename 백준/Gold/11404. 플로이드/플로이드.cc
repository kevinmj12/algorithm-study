#include <iostream>
#include <algorithm>
#define MAX 10000001
using namespace std;

int cost[101][101];

void init(int n){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cost[i][j] = MAX;
        }
        cost[i][i] = 0;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    init(n);

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        cost[a][b] = min(cost[a][b], c);
    }

    for (int middle = 1; middle <= n; middle++){
        for (int start = 1; start <= n; start++){
            for (int end = 1; end <= n; end++){
                if (cost[start][end] > cost[start][middle] + cost[middle][end]){
                    cost[start][end] = cost[start][middle] + cost[middle][end];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (cost[i][j] == MAX){
                cout << 0 << " ";
            }
            else{
                cout << cost[i][j] << " ";
            }
        }
        cout << endl;
    }
}