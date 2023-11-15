#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int answer = 0;
vector<pair<int,int>> meetings;

void solve(){
    // 정렬된 회의들 중 첫 번째 회의를 처음로 잡음
    int endT = meetings[0].first;
    answer++;
    // 회의의 종료시각보다 시작시각이 같거나 느린 회의를 찾음
    // (1 4)가 진행되었을 때 (4 4)도 가능함에 주의
    for (int i = 1; i < N; i++){
        if (meetings[i].second >= endT){
            answer++;
            endT = meetings[i].first;
        }
    }
    
    printf("%d", answer);
    return;
}

int main(){
    scanf("%d", &N);
    

    // 시작 시각과 종료 시각을 입력받아 벡터에 추가
    // 종료 시각을 우선으로 정렬해야 하기 때문에 end, begin을 추가
    for (int i = 0; i < N; i++){
        int begin, end;
        scanf("%d %d", &begin, &end);
        
        meetings.push_back({end, begin});
    }

    sort(meetings.begin(), meetings.end());

    solve();
}