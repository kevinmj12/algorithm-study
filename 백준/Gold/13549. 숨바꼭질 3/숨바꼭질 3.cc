#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001
bool visited[MAX];

int main(){
    int N, K;
    cin >> N >> K;

    priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, N});

    int answer = 0;

    if (N >= K){
        answer = N-K;
    }
    else{
        while (true){
            int val = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
    
            visited[cur] = true;
            if (cur == K){
                answer = val;
                break;
            }

            if (cur*2 < MAX && !visited[cur*2]){
                pq.push({val, cur*2});
            }
            if (cur > 0 && !visited[cur-1]){
                pq.push({val+1, cur-1});
            }
            if (cur < MAX && !visited[cur+1]){
                pq.push({val+1, cur+1});
            }
        }
    }
    cout << answer;
    return 0;
}