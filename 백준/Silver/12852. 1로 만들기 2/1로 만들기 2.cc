#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solve(int n){
    if (n == 1){
        return {};
    }
    queue<vector<int>> que;
    que.push({n});

    while (!que.empty()){
        vector<int> vec = que.front();
        que.pop();
        // 종료 조건
        if (vec.back() == 3 || vec.back() == 2){
            return vec;
        }
        // 3으로 나누어 떨어지는 경우
        if (vec.back() % 3 == 0){
            vec.push_back(vec.back() / 3);
            que.push(vec);
            vec.pop_back();
        }
        // 2로 나누어 떨어지는 경우
        if (vec.back() % 2 == 0){
            vec.push_back(vec.back() / 2);
            que.push(vec);
            vec.pop_back();
        }
        // 1을 뺀 값
        vec.push_back(vec.back()-1);
        que.push(vec);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> answer = solve(n);
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << 1;
}