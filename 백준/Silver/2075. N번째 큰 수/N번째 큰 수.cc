#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        pq.push(k);
    }
    for (int i = n; i < n*n; i++){
        int k;
        cin >> k;
        pq.push(k);
        pq.pop();
    }

    cout << pq.top();
}