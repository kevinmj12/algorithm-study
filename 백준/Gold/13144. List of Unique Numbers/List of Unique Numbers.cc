#include <iostream>
#include <queue>
using namespace std;

bool numbers[100001];

int main(){
    int N;
    cin >> N;

    int left = 0;
    long long answer = 0;
    queue<int> q;

    for (int i = 0; i < N; i++){
        int cur;
        cin >> cur;

        if (!numbers[cur]){
            numbers[cur] = true;
            answer += q.size();
        }
        else{
            while (q.front() != cur){
                numbers[q.front()] = false;
                q.pop();
            }
            q.pop();

            answer += q.size();
        }
        q.push(cur);
    }

    cout << answer + N;
}