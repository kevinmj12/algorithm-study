#include <iostream>
using namespace std;

int sudoku[10][10];
bool findAnswer = false;

// 스도쿠의 조건을 만족하는지를 검사하는 함수
bool checkValue(int v, int y, int x){
    // 가로 방향 체크
    for (int c = 1; c <= 9; c++){
        if (sudoku[y][c] == v){
            return false;
        }
    }
    // 세로 방향 체크
    for (int r = 1; r <= 9; r++){
        if (sudoku[r][x] == v){
            return false;
        }
    }
    // 3×3 사각형 체크
    int yStart, yEnd, xStart, xEnd;
    if (y <= 3){
        yStart = 1;
        yEnd = 3;
    }
    else if (y <= 6){
        yStart = 4;
        yEnd = 6;
    }
    else{
        yStart = 7;
        yEnd = 9; 
    }
    if (x <= 3){
        xStart = 1;
        xEnd = 3;
    }
    else if (x <= 6){
        xStart = 4;
        xEnd = 6;
    }
    else{
        xStart = 7;
        xEnd = 9;
    }
    for (int r = yStart; r <= yEnd; r++){
        for (int c = xStart; c <= xEnd; c++){
            if (sudoku[r][c] == v){
                return false;
            }
        }
    }
    // 위 조건들을 모두 통과했다면 true 리턴
    return true;
}

// 재귀로 백트래킹을 구현
void solve(int y, int x){
    // y, x가 모두 9이거나 이미 정답을 찾았다면 탐색 종료
    if ((y == 9 && x == 9) || findAnswer){
        findAnswer = true;
        return;
    }
    // 사전식으로 앞서는 것을 출력해야 함에 유의
    // 스도쿠가 이미 채워져 있다면 다음을 탐색
    if (sudoku[y][x] > 0){
        if (x == 9){
            solve(y+1, 1);
        }
        else{
            solve(y, x+1);
        }
    }
    // 스도구카 채워져 있지 않다면 1~9까지 차례대로 대입
    else{
        for (int trg = 1; trg <= 9; trg++){
            if (checkValue(trg, y, x)){
                sudoku[y][x] = trg;
                if (x == 9){
                    solve(y+1, 1);
                }
                else{
                    solve(y, x+1);
                }
                if (findAnswer){
                    return;
                }
                sudoku[y][x] = 0;
            }
        }
    }
}

int main(){
    for (int i = 1; i <= 9; i++){
        string input;
        cin >> input;
        for (int j = 1; j <= 9; j++){
            sudoku[i][j] = input[j-1]-'0';
        }
    }

    solve(1, 1);

    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= 9; j++){
            cout << sudoku[i][j];
        }
        cout << "\n";
    }
}