#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dirs[9][2] = {{0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

struct Runner{
    int num;
    int dir;

    Runner(){
        num = 0;
        dir = 0;
    }
    Runner(int n, int d){
        num = n;
        dir = d;
    }
};

bool compare(Runner a, Runner b){
    return a.num < b.num;
}

bool canMove(int y, int x){
    if (y < 0 || y >= 4 || x < 0 || x >= 4){
        return false;
    }
    return true;
}

int answer = 0;
int maxAnswer = 0;

void moveRunners(vector<pair<int, int>>& r, vector<vector<Runner>>& b){
    for (int i = 1; i <= 16; i++){
        int y = r[i].first;
        int x = r[i].second;
        int d = b[y][x].dir;

        if (b[y][x].num != i){
            continue;
        }
        int endD = d + 8;
        for (d; d < endD; d++){
            int nextD = (d-1)%8+1;
            int nextY = y + dirs[nextD][0];
            int nextX = x + dirs[nextD][1];

            if (!canMove(nextY, nextX) || b[nextY][nextX].num == -1){
                continue;
            }
            // 다른 술래말이 있는 경우 교체
            if (b[nextY][nextX].num > 0){
                r[b[nextY][nextX].num] = {y, x};
            }
            b[y][x] = b[nextY][nextX];
            b[nextY][nextX] = Runner(i, nextD);
            r[i] = {nextY, nextX};
            break;
        }
        d %= 8;
    }
}

void solve(vector<pair<int, int>> r, vector<vector<Runner>> b){
    vector<pair<int, int >> nextRunners = r;
    vector<vector<Runner>> nextBoard = b;
    // 도둑말 이동
    moveRunners(nextRunners, nextBoard);

    // cout << "\n" << answer << "\n";
    // for (int i = 0; i < 4; i++){
    //     for (int j = 0; j < 4; j++){
    //         cout << nextBoard[i][j].num << " ";
    //     }
    //     cout << endl;
    // }

    // 술래말 이동
    // 1. 술래말이 이동 가능한 칸 조회
    int cY = nextRunners[0].first , cX = nextRunners[0].second;
    int cD = nextBoard[cY][cX].dir;
    vector<pair<int, int>> nextTiles;

    for (int distance = 1; distance <= 3; distance++){
        int nextY = cY+dirs[cD][0]*distance;
        int nextX = cX+dirs[cD][1]*distance;
        if (canMove(nextY, nextX) && nextBoard[nextY][nextX].num){
            nextTiles.push_back({nextY, nextX});
        }
    }

    // 2. 술래말이 이동할 수 없다면, 종료
    if (nextTiles.empty()){
        maxAnswer = max(maxAnswer, answer);
        // cout << answer << endl;
        return;
    }
    // 3. 술래말 이동 백트래킹
    for (int i = 0; i < nextTiles.size(); i++){
        int nextY = nextTiles[i].first;
        int nextX = nextTiles[i].second;

        Runner target = nextBoard[nextY][nextX];
        answer += target.num;
        nextBoard[cY][cX] = Runner(0, 0);
        nextBoard[nextY][nextX].num = -1;
        nextRunners[0] = {nextY, nextX};

        solve(nextRunners, nextBoard);

        answer -= target.num;
        nextBoard[cY][cX] = {-1, cD};
        nextBoard[nextY][nextX] = target;
        nextRunners[0] = {cY, cX};
    }
}

int main(){
    vector<pair<int, int>> runners(17);
    vector<vector<Runner>> board(4, vector<Runner>(4));

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            int p, d;
            cin >> p >> d;
            runners[p] = {i, j};
            board[i][j] = Runner(p, d);
        }
    }

    answer = board[0][0].num;
    runners[0] = {0, 0};
    board[0][0].num = -1;

    solve(runners, board);

    cout << maxAnswer;
}