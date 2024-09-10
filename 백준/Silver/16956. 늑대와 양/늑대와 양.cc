#include <iostream>
#include <queue>
using namespace std;

int r, c;
char graph[501][501];
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool solve(vector<pair<int, int>> wolfPos){
    for (int i = 0; i < wolfPos.size(); i++){
        int curY = wolfPos[i].first;
        int curX = wolfPos[i].second;
        for (int d = 0; d < 4; d++){
            int nextY = curY + direction[d][0];
            int nextX = curX + direction[d][1];
            if (nextY < 1 || nextY > r || nextX < 1 || nextX > c 
            || graph[nextY][nextX] == 'D' || graph[nextY][nextX] == 'W'){
                continue;
            }
            else if (graph[nextY][nextX] == 'S'){
                return false;
            }
            graph[nextY][nextX] = 'D';
        }
    }
    return true;
}

int main(){
    cin >> r >> c;

    vector<pair<int, int>> wolfPos;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> graph[i][j];

            if (graph[i][j] == 'W'){
                wolfPos.push_back({i, j});
            }
        }
    }

    bool answer = solve(wolfPos);

    if (answer){
        cout << 1 << "\n";
        for (int i = 1; i <= r; i++){
            for (int j = 1; j <= c; j++){
                cout << graph[i][j];
            }
            cout << "\n";
        }
    }
    else{
        cout << "0";
    }

}