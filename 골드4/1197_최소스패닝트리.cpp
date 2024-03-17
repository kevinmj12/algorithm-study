#include <iostream>
#include <queue>
using namespace std;

int v, e;
// 우선순위 큐를 이용하여 간선의 가중치순대로 정렬
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
int root[10001];

// find 함수 구현
int Find(int x){
    if (x == root[x]){
        return x;
    }
    return root[x] = Find(root[x]);
}

// union 함수 구현
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    root[y] = x;
}

void solve(){
    // root 기본값 설정
    for (int i = 1; i < v; i++){
        root[i] = i;
    }

    int visitedNode = 1;
    long long answer = 0;

    // 간선을 모두 방문한다면 while문 탈출
    // 만약 모든 노드가 연결되지 않을 수 있다는 조건이 있다면 !pq.empty()를 추가하면 된다.
    while (visitedNode < v){
        int distance = pq.top().first;
        int start = pq.top().second.first;
        int finish = pq.top().second.second;
        pq.pop();
        
        // 사이클이 발생하지 않는다면
        if (Find(start) != Find(finish)){
            Union(start, finish);
            answer += distance;
            visitedNode++;
        }
    }

    cout << answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> v >> e;
    for (int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;

        pq.push({c,{a,b}});
    }

    solve();
}