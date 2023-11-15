#include <iostream>
#include <queue>
using namespace std;

// 방문 중복 처리를 위한 배열
bool visited[200001] = {false};
int answer = 0;

void solve(int n, int k){
    // 처음부터 위치가 같은 경우 종료
    if (n == k){
        printf("%d", answer);
        return;
    }
    // BFS로 탐색
    queue<int> order;
    order.push(n);
    visited[n] = true;
    while (true){
        answer++;
        int size = order.size();
        for (int i = 0; i < size; i++){
            int tmp = order.front();
            if (tmp*2 == k || tmp+1 == k || tmp-1 == k){
                printf("%d", answer);
                return;
            }
            // 범위 조건에 맞춰 큐에 추가
            if (tmp <= 100000){
                if (visited[tmp*2] == false){
                    order.push(tmp*2);
                    visited[tmp*2] = true;
                }
            }
            if (tmp + 1 <= 200000){
                if (visited[tmp+1] == false){
                order.push(tmp+1);
                visited[tmp+1] = true;
                }
            }
            
            if (tmp > 1 && tmp -1 <= 200000){
                if (visited[tmp-1] == false){
                    order.push(tmp-1);
                    visited[tmp-1] = true;
                }
            }
            order.pop();
        }
    }
}


int main(){
    int N, K;
    scanf("%d %d", &N, &K);

    solve(N, K);
}