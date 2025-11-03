#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];

int main(){
    int N;
    cin >> N;

    long long answer = 0;
    queue<int> q;

    for (int i = 0; i < N; i++){
        int a;
        cin >> a;

        if (!visited[a]){
            visited[a] = true;
            answer += q.size();
        }
        else{
            while (q.front() != a){
                visited[q.front()] = false;
                q.pop();
            }
            q.pop();

            answer += q.size();
        }
        
        q.push(a);
    }

    cout << answer + N;
}