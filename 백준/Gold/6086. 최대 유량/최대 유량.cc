#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

struct Flow{
    int cur;
    int total;

    Flow(){
        cur = 0;
        total = 0;
    }
    Flow(int c, int t){
        cur = c;
        total = t;
    }
};

vector<int> dirs[53];
Flow graph[53][53];
int path[53];

int charToInt(char c){
    if ('A' <= c && c <= 'Z'){
        return c-64;
    }
    else{
        return c-70;
    }
}

int solve(){
    int answer = 0;

    while (true){
        memset(path, 0, sizeof(path));
    
        queue<int> q;
        q.push(1);
        path[1] = 1;
        bool findFlag = false;
    
        // BFS로 경로 찾기
        while (!q.empty()){
            if (findFlag){
                break;
            }
    
            int cur = q.front();
            q.pop();
    
            for (int next: dirs[cur]){
                Flow nextFlow = graph[cur][next];
                int flow = nextFlow.total - nextFlow.cur;
                if (flow > 0 && path[next] == 0){
                    q.push(next);
                    path[next] = cur;
    
                    if (next == 26){
                        findFlag = true;
                        break;
                    }
                }
            }
        }
        // 더 이상 유량이 없음
        if (!findFlag){
            return answer;
        }
        // 경로를 역추적하며 유량을 계산
        int maxFlow = 1000;
        int cur = 26;
        while (cur != 1){
            maxFlow = min(maxFlow, graph[path[cur]][cur].total - graph[path[cur]][cur].cur);
            cur = path[cur];
        }
        cur = 26;
        while (cur != 1){
            graph[path[cur]][cur].cur += maxFlow;
            graph[cur][path[cur]].cur -= maxFlow;
            cur = path[cur];
        }
        answer += maxFlow;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++){
        char a, b;
        int c;
        cin >> a >> b >> c;

        int iA = charToInt(a);
        int iB = charToInt(b);
        dirs[iA].push_back(iB);
        dirs[iB].push_back(iA);
        graph[iA][iB].total += c;
        graph[iB][iA].total += c;
    }

    cout << solve();
}