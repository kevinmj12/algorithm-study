#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int people[50][50];
bool visited[50][50];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void resetVisited(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
}

// bfs를 통해 인구 이동
bool move(int n, int l, int r){
    bool isMoved = false;
    resetVisited(n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // 이미 방문한 경우
            if (visited[i][j]){
                continue;
            }
            int unionPeople = 0;

            vector<pair<int, int>> vec;
            vec.push_back({i, j});
            visited[i][j] = true;   


            for (int k = 0; k < vec.size(); k++){
                int curY = vec[k].first;
                int curX = vec[k].second;
                unionPeople += people[curY][curX];

                // 인접한 국가와의 인구 차이를 확인 후 vec에 추가
                for (int d = 0; d < 4; d++){
                    int nextY = curY + dir[d][0];
                    int nextX = curX + dir[d][1];
                    if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || visited[nextY][nextX]){
                        continue;
                    }
                    int diffPeople = abs(people[nextY][nextX]-people[curY][curX]);
                    if (l <= diffPeople && diffPeople <= r){
                        isMoved = true;
                        vec.push_back({nextY, nextX});
                        visited[nextY][nextX] = true;
                    }
                }
            }
            // 연합 인구 조정
            int nextPeople = unionPeople / vec.size();
            for (int k = 0; k < vec.size(); k++){
                people[vec[k].first][vec[k].second] = nextPeople;
            }
        }
    }
    return isMoved;
}

void solve(int n, int l, int r){
    int answer = 0;
    while (true){
        if (move(n, l, r)){
            answer++;
        }
        else{
            break;
        }
    }
    cout << answer;
    return;
}


int main(){
    int n, l, r;
    cin >> n >> l >> r;

    // input
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> people[i][j];
        }
    }

    solve(n, l, r);
    
}