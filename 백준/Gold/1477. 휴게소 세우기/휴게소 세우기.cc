#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int stores[50];

int main(){
    int n, m, l;
    cin >> n >> m >> l;

    for (int i = 0; i < n; i++){
        cin >> stores[i];
    }

    sort(stores, stores+n);
    priority_queue<vector<int>> pq;

    // 나누어진 거리, 원래 거리, 추가로 설치한 휴게소 수

    if (n == 0){
        pq.push({l, l, 0});
    }
    else {
        pq.push({stores[0], stores[0], 0});
        for (int i = 1; i < n; i++){
            pq.push({stores[i] - stores[i-1], stores[i] - stores[i-1], 0});
        }
        pq.push({l-stores[n-1], l-stores[n-1], 0});
    }

    while (m--){
        vector<int> tmp = pq.top();
        pq.pop();
        tmp[2]++;
        tmp[0] = (tmp[1]+tmp[2]) / (tmp[2]+1);
        pq.push(tmp);
    }
    
    cout << pq.top()[0];
}