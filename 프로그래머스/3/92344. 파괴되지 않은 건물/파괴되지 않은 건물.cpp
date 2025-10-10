#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    vector<vector<int>> boardSum(board.size()+1, vector<int>(board[0].size()+1, 0));
    for (vector<int> s: skill){
        int type = s[0];
        int r1 = s[1];
        int c1 = s[2];
        int r2 = s[3];
        int c2 = s[4];
        int degree = s[5];
        if (type == 1){
            degree *= -1;
        }
        
        boardSum[r1][c1] += degree;
        boardSum[r2+1][c1] -= degree;
        boardSum[r1][c2+1] -= degree;
        boardSum[r2+1][c2+1] += degree;
    }

    
    // base
    if (boardSum[0][0] + board[0][0] >= 1){
        answer++;
    }
    
    for (int i = 1; i < board.size(); i++){
        boardSum[i][0] += boardSum[i-1][0];
        if (boardSum[i][0] + board[i][0] >= 1){
            answer++;
        }
    };
    for (int j = 1; j < board[0].size(); j++){
        boardSum[0][j] += boardSum[0][j-1];
        if (boardSum[0][j] + board[0][j] >= 1){
            answer++;
        }
    }
    
    // 누적합
    for (int i = 1; i < board.size(); i++){
        for (int j = 1; j < board[0].size(); j++){
            boardSum[i][j] += (boardSum[i-1][j] + boardSum[i][j-1] - boardSum[i-1][j-1]);
            if (boardSum[i][j] + board[i][j] >= 1){
                answer++;
            }
        }
    }
    
    return answer;
}