#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++){
        int card;
        cin >> card;
        pq.push(card);
    }

    unsigned long long answer = 0;
    
    while (true){
        int a = pq.top();
        pq.pop();
        if (pq.empty()){
            break;
        }
        int b = pq.top();
        pq.pop();
        answer += (a+b);
        pq.push(a+b);
    }

    cout << answer;
}