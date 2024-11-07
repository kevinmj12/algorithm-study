#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> oils[10000];

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        oils[i] = {a, b};
    }

    int l, p;
    cin >> l >> p;

    sort(oils, oils+n);

    priority_queue<int> pq;
    int cur = 0;
    int oilIdx = 0;
    int answer = 0;


    cur += p;
    while (oilIdx < n && oils[oilIdx].first <= cur){
        pq.push(oils[oilIdx].second);
        oilIdx++;   
    }
    while (!pq.empty() && cur < l){
        p = pq.top();
        pq.pop();
        answer++;

        cur += p;
        while (oilIdx < n && oils[oilIdx].first <= cur){
            pq.push(oils[oilIdx].second);
            oilIdx++;   
        }
    }

    if (cur >= l){
        cout << answer;
    }
    else{
        cout << -1;
    }

}