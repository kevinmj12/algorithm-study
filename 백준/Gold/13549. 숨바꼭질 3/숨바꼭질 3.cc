#include <iostream>
#include <deque>
#include <climits>
using namespace std;
#define MAX 100001

bool visited[MAX];

int main(){
    int N, K;
    cin >> N >> K;

    int answer = 0;
    if (N >= K){
        answer = N-K;
    }
    else{
        deque<pair<int ,int>> dq;
        dq.push_back({N, 0});

        while (true){
            int cur = dq.front().first;
            int val = dq.front().second;
            dq.pop_front();

            if (visited[cur]){
                continue;
            }
            visited[cur] = true;

            if (cur == K){
                answer = val;
                break;
            }
            if (cur*2 < MAX && !visited[cur*2]){
                dq.push_front({cur*2, val});
            }
            if (cur > 0 && !visited[cur-1]){
                dq.push_back({cur-1, val+1});
            }
            if (cur+1 < MAX && !visited[cur+1]){
                dq.push_back({cur+1, val+1});
            }
        }
    }

    cout << answer;
    return 0;
}