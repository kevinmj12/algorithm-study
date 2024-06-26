#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 300001
using namespace std;
pair<int, int> jewels[MAX];
int bags[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    priority_queue<int> values;

    for (int i = 0; i < N; i++){
        int m, v;
        cin >> m >> v;
        jewels[i] = {m, v};
    }
    for (int i = 0; i < K; i++){
        cin >> bags[i];
    }
    sort(jewels, jewels+N);
    sort(bags, bags+K);

    long long answer = 0;
    int jewelIdx = 0;

    for (int i = 0; i < K; i++){
        if (jewelIdx >= N){
            if (!values.empty()){
                answer += values.top();
                values.pop();
            }
        }
        else if (bags[i] >= jewels[jewelIdx].first){
            while (jewelIdx < N && bags[i] >= jewels[jewelIdx].first){
                values.push(jewels[jewelIdx].second);
                jewelIdx++;
            }
            answer += values.top();
            values.pop();
        }
        else{
            if (!values.empty()){
                answer += values.top();
                values.pop();
            }
        }
    }
    
    cout << answer;
}