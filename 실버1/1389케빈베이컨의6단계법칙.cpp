#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
bool **friends;
bool *visited;

// visited를 초기화하는 함수
void reset(){
    visited = new bool[N+1];
    for (int v = 0; v < N+1; v++){
        visited[v] = false;
    }
}

// bfs로 친구를 찾는 함수
int Kevin(int a, int b){
    reset();
    int val = 0;
    queue<int> order;
    order.push(a);

    while (!order.empty()){
        val++; // 깊이 증가
        queue<int> tmp = order;

        int tmpSize = order.size();
        for (int size = 0; size < tmpSize; size++){
            int friendA = order.front();
            for (int friendB = 1; friendB < N+1; friendB++){
                if (visited[friendB] == false & friends[friendA][friendB] == true){
                    // 친구 a와 b가 연결된 경우
                    if (friendB == b){
                        return val;
                    }
                    // b가 아닌 다른 친구인 경우
                    order.push(friendB);
                    visited[friendB] = true;
                }
            }
            order.pop();
        }
    }
    // 친구가 없는 경우 0을 리턴
    // 문제에는 모든 사람은 친구 관계로 연결되어 있다 명시되어 있음
    return 0;
}

void solve(){
    int minValue = 2147483647;
    int answer;

    for (int i = 1; i < N+1; i++){
        int value = 0;
        for (int j = 1; j < N+1; j++){
            // a와 a가 친구인 경우는 조사할 필요 없음
            if (i == j){
                continue;
            }
            else{
                // 케빈베이컨값이 가장 작은 친구를 구함
                value += Kevin(i, j);
            }
        }
        // value가 작은 친구를 정답으로 설정
        if (value < minValue){
            minValue = value;
            answer = i;
        }
    }

    printf("%d", answer);
}

int main(){
    scanf("%d %d", &N, &M);
    
    // friends, visited 설정
    friends = new bool* [N+1];
    for (int i = 0; i < N+1; i++){
        friends[i] = new bool[N+1];
    }

    // 배열의 기본값을 전부 false로 설정
    for (int i = 0; i < N+1; i++){
        for (int j = 0; j < N+1; j++){
            friends[i][j] = false;
        }
    }


    for (int tCase = 0; tCase < M; tCase++){
        int a, b;
        scanf("%d %d", &a, &b);
        friends[a][b] = true;
        friends[b][a] = true;
    }

    solve();
}