#include <iostream>
#include <queue>
#include <stack>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        // 서류심사 순위가 낮은 지원자순으로 정렬 
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;

            pq.push({a, b});
        }
        
        stack<pair<int, int>> s;
        // 첫 번째 원소를 집어넣음
        s.push(pq.top());
        pq.pop();

        while (!pq.empty()){
            pair<int, int> target = pq.top();
            pq.pop();
            
            // 면접시험 점수가 더 높은 사람이 나올때까지 스택을 pop
            while (!s.empty() && s.top().second > target.second){
                s.pop();
            }
            s.push(target);
        }

        cout << s.size() << '\n';
    }
}