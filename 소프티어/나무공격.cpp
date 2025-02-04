#include<iostream>
#include<algorithm>

using namespace std;

int graph[101][101];
int destroyers[101];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> graph[i][j];
            if (graph[i][j]){
                destroyers[i]++;
            }
        }
    }

    int l1, r1, l2, r2;
    cin >> l1 >> r1;
    cin >> l2 >> r2;

    for (int i = l1; i <= r1; i++){
        destroyers[i] = max(destroyers[i]-1, 0);
    }
    for (int i = l2; i <= r2; i++){
        destroyers[i] = max(destroyers[i]-1, 0);
    }

    int answer = 0;
    for (int i = 1; i <= n; i++){
        answer += destroyers[i];
    }
    cout << answer;

    return 0;
}