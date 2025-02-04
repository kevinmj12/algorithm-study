#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 26
int graph[MAX][MAX];
int visited[MAX][MAX];
vector<int> answer;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int y, int x, int N){
    queue<pair<int, int>> order;
    int size = 0;

    if (graph[y][x]){
        order.push({y, x});
        graph[y][x] = 0;
        size++;
        while (!order.empty()){
            pair<int, int> cur = order.front();
            for (int i = 0; i < 4; i++){
                int nextY = cur.first + dir[i][0];
                int nextX = cur.second + dir[i][1];

                if (1 <= nextY && nextY <= N && 1 <= nextX && nextX <= N && graph[nextY][nextX]){
                    order.push({nextY, nextX});
                    graph[nextY][nextX] = 0;
                    size++;
                }
            }
            order.pop();
        }
    }
    if (size > 0){
        answer.push_back(size);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++){
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++){
            graph[i][j] = s[j-1]-'0';
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            bfs(i, j, N);
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << "\n";
    }
}