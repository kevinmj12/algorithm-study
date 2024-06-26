#include <iostream>
using namespace std;
int board[15];
int n;
int answer = 0;

bool isPossible(int row, int col){
    for (int i = 1; i < row; i++){
        if (board[i] == col || abs(board[i]-col) == row-i){
            return false;
        }
    }
    return true;
}

void solve(int row){
    if (n+1 == row){
        answer++;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (isPossible(row, i)){
            board[row] = i;
            solve(row+1);
        }
    }
}


int main(){
    cin >> n;

    solve(1);

    cout << answer;
}