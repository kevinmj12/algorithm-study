#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<int, vector<int>, greater<int>> times;
    for (int i = 0; i < N; i++){
        int s, t;
        cin >> s >> t;

        pq.push({s, t});
    }

    // 첫 번째 강의의 끝나는 시각을 넣어줌
    times.push(pq.top().second);
    pq.pop();

    while (!pq.empty()){
        if (pq.top().first >= times.top()){
            times.pop();
            times.push(pq.top().second);
            pq.pop();
        }
        else{
            times.push(pq.top().second);
            pq.pop();
        }
    }

    cout << times.size();
}