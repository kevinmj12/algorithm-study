#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    
    int oCnt = 0;
    int xCnt = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == 'O'){
                oCnt++;
            }
            else if (board[i][j] == 'X'){
                xCnt++;
            }
        }
    }
    
    if (!(oCnt - xCnt == 0 || oCnt - xCnt == 1)){
        return 0;
    }
    
    int oBingo = 0;
    int xBingo = 0;
    // 가로
    for (int i = 0; i < 3; i++){
        if (board[i][0] == '.'){
            continue;
        }
        else if (board[i][0] == 'O'){
            if (board[i][1] == 'O' && board[i][2] == 'O'){
                oBingo++;
            }
        }
        else{
            if (board[i][1] == 'X' && board[i][2] == 'X'){
                xBingo++;
            }
        }
    }
    
    // 세로
    for (int i = 0; i < 3; i++){
        if (board[0][i] == '.'){
            continue;
        }
        else if (board[0][i] == 'O'){
            if (board[1][i] == 'O' && board[2][i] == 'O'){
                oBingo++;
            }
        }
        else{
            if (board[1][i] == 'X' && board[2][i] == 'X'){
                xBingo++;
            }
        }
    }
    
    // 대각선
    if (board[1][1] == 'O'){
        if (board[0][0] == 'O' && board[2][2] == 'O'){
            oBingo++;
        }
        if (board[0][2] == 'O' && board[2][0] == 'O'){
            oBingo++;
        }
    }
    else if (board[1][1] == 'X'){
        if (board[0][0] == 'X' && board[2][2] == 'X'){
            xBingo++;
        }
        if (board[0][2] == 'X' && board[2][0] == 'X'){
            xBingo++;
        }
    } 
    
    // 둘 다 빙고가 있음
    if (oBingo > 0 && xBingo > 0){
        return 0;
    }
    // x가 이겼는데 개수가 같지 않음
    if (xBingo > 0 && oCnt != xCnt){
        return 0;
    }
    // o가 이겼는데 1개 차이가 아님
    if (oBingo > 0 && oCnt - xCnt != 1){
        return 0;
    }
    
    
    return answer;
}