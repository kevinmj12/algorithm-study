#include <iostream>
#include <vector>
using namespace std;

pair<int, int> getCompleted(string str){
    vector<vector<char>> board(3, vector<char>(3, '.'));
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = str[i*3+j];
        }
    }

    int oCompleted = 0;
    int xCompleted = 0;

    // 가로 세로
    for (int i = 0; i < 3; i++){
        if (board[i][0] != '.'){
            char trg = board[i][0];
            bool flag = true;
            for (int j = 1; j < 3; j++){
                if (trg != board[i][j]){
                    flag = false;
                    break;
                }
            }

            if (flag){
                if (trg == 'O'){
                    oCompleted++;
                }
                else{
                    xCompleted++;
                } 
            }
        }
        if (board[0][i] != '.'){
            char trg = board[0][i];
            bool flag = true;
            for (int j = 1; j < 3; j++){
                if (trg != board[j][i]){
                    flag = false;
                    break;
                }
            }

            if (flag){
                if (trg == 'O'){
                    oCompleted++;
                }
                else{
                    xCompleted++;
                } 
            }
        }
    }
    // 대각선
    char trg = board[1][1];
    if (trg != '.'){
        bool flag = true;
        for (int j = 0; j < 3; j+=2){
            if (trg != board[j][j]){
                flag = false;
                break;
            }
        }
        if (flag){
            if (trg == 'O'){
                oCompleted++;
            }
            else{
                xCompleted++;
            } 
        }
        
        flag = true;
        for (int j = 0; j < 3; j+=2){
            if (trg != board[2-j][j]){
                flag = false;
                break;
            }
        }
        if (flag){
            if (trg == 'O'){
                oCompleted++;
            }
            else{
                xCompleted++;
            } 
        }
    }

    return {xCompleted, oCompleted};
}

bool judge(string str){
    int oCnt = 0, xCnt = 0;
    for (int i = 0; i < 9; i++){
        if (str[i] == 'O'){
            oCnt++;
        }
        else if (str[i] == 'X'){
            xCnt++;
        }
    }
    int dotCnt = 9-oCnt-xCnt;

    if (!(0 <= xCnt - oCnt && xCnt - oCnt <= 1)){
        return false;
    }

    pair<int, int> result = getCompleted(str);
    if (result.first > 0 && result.second > 0){
        return false;
    }
    else if (result.first == 0 && result.second == 0 && dotCnt > 0){
        return false;
    }
    else if (result.second > 0 && xCnt > oCnt){
        return false;
    }
    else if (result.first > 0 && xCnt == oCnt){
        return false;
    }
    else{
        for (int i = 0; i < 9; i++){
            char tmp = str[i];
            if (tmp != '.'){
                str[i] = '.';
                pair<int, int> before = getCompleted(str);

                if (before.first == 0 && before.second == 0){
                    return true;
                }
                str[i] = tmp;
            }
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true){
        string input;
        cin >> input;

        if (input == "end"){
            return 0;
        }

        bool isValid = judge(input);
        if (isValid){
            cout << "valid\n";
        }
        else{
            cout << "invalid\n";
        }
    }
}