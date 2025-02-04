#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> flowers;
priority_queue<pair<pair<int, int>, pair<int,int>>> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pq.push({{c, d}, {a, b}});
    }

    // 기간별 꽃이 피는 날짜, 지는 날짜를 저장
    int endMonth = 12;
    int endDay = 1;
    int startMonth = 12;
    int startDay = 1;
    int answer = 0;

    // 꽃이 피는 날짜가 3월 1일이 될 때 까지
    while (!pq.empty() && make_pair(startMonth, startDay) > make_pair(3, 1)){
        // 만약 중간에 꽃이 피어있는 기간이 빈다면 종료
        if (!pq.empty() && pq.top().first < make_pair(endMonth, endDay)){
            cout << 0;
            return 0;
        }
        // 꽃이 피는 날짜가 제일 작은 꽃을 선택
        while (!pq.empty() && pq.top().first >= make_pair(endMonth, endDay)){
            if (pq.top().second < make_pair(startMonth, startDay)){
                startMonth = pq.top().second.first;
                startDay = pq.top().second.second;
            }
            pq.pop();
        }
        // 꽃이 지는 날짜를 업데이트
        endMonth = startMonth;
        endDay = startDay;
        answer++;
    }

    if (make_pair(startMonth, startDay) <= make_pair(3, 1)){
        cout << answer;
    }
    else{
        cout << 0;
    }

}
