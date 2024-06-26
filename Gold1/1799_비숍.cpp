#include <iostream>
#include <algorithm>
using namespace std;

int board[11][11];
int leftUp[21];
int rightUp[21];
int n;
int answer1 = 0, answer2 = 0;

bool isPossible(int y, int x){
    if (!board[y][x] || leftUp[y-x+n+1] || rightUp[y+x]){
        return false;
    }
    return true;
}

void solve(int cnt, int y, int x, int ver){
    int nextY = y;
    int nextX = x;

    if (y > n){
        if (ver){
            answer1 = max(cnt, answer1);
        }
        else{
            answer2 = max(cnt, answer2);
        }
        return;
    }

    
    if (x + 2 <= n){
        nextX = x + 2;
    }
    else{
        nextY++;
        nextX = ((nextY+ver) % 2) ? 1 : 2;
    }

    if (isPossible(y, x)){
        leftUp[y-x+n+1] = 1;
        rightUp[y+x] = 1;
        solve(cnt+1, nextY, nextX, ver);
        leftUp[y-x+n+1] = 0;
        rightUp[y+x] = 0;
    }
    solve(cnt, nextY, nextX, ver);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }

    solve(0, 1, 1, 0);
    solve(0, 1, 2, 1);

    cout << answer1 + answer2;
}