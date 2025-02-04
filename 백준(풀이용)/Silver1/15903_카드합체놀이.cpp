#include <iostream>
#include <queue>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq;
    for (int i = 0; i < n; i++){
        unsigned long long a;
        cin >> a;
        pq.push(a);
    }

    while (m--){
        unsigned long long min1 = pq.top();
        pq.pop();
        unsigned long long min2 = pq.top();
        pq.pop();

        pq.push(min1+min2);
        pq.push(min1+min2);
    }

    unsigned long long answer = 0;
    while (!pq.empty()){
        answer += pq.top();
        pq.pop();
    }

    cout << answer;
}