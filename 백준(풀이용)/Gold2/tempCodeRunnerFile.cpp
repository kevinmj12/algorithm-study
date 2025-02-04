#include <iostream>
#include <queue>
using namespace std;

bool books[1001];

void resetBooks(int n){
    for (int i = 1; i <= n; i++){
        books[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        resetBooks(n);
        int answer = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            pq.push({b-a, {a, b}});
        }

        while (!pq.empty()){
            int start = pq.top().second.first;
            int end = pq.top().second.second;
            pq.pop();

            for (int i = end; i >= start; i--){
                if (!books[i]){
                    books[i] = true;
                    answer++;
                    break;
                }
            }
        }

        cout << answer << "\n";
    }
}