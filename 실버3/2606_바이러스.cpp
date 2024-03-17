#include <iostream>
#include <queue>
using namespace std;

int N;
int answer = 0;
int** computers;
bool* visited;

// BFS로 감염된 컴퓨터 수를 측정
void solve(){
    queue<int> order;
    order.push(1);
    visited[1] = true;

    while(!order.empty()){
        int tmp = order.front();
        for (int i = 1; i < N+1; i++){
            if (computers[tmp][i] == 1 && visited[i] == false){
                order.push(i);
                answer++;
                visited[i] = true;
            }
        }
        order.pop();
    }

    printf("%d", answer);
}

int main(){
    scanf("%d", &N);

    // 연결된 컴퓨터들을 확인하기 위한 2차원 배열 설정
    computers = new int*[N+1];
    for (int i = 1; i < N+1; i++){
        computers[i] = new int[N+1];
    }

    // 기본값으로 -1로 설정
    for (int i = 1; i < N+1; i++){
        for (int j = 1; j < N+1; j++){
            computers[i][j] = -1;
        }
    }

    // visited 설정
    visited = new bool[N+1];
    for (int i = 1; i < N+1; i++){
        visited[i] = false;
    }

    int connectedComputers;
    scanf("%d", &connectedComputers);

    // 연결된 컴퓨터들을 입력받음
    for (int i = 0; i < connectedComputers; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        computers[a][b] = 1;
        computers[b][a] = 1;
    }

    solve();
}