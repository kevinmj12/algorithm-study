#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    string* board = new string[N];

    for (int i = 0; i < N; i++){
        string str;
        cin >> str;
        board[i] = str;
    }

    int rowAns = 0;
    int colAns = 0;

    // rowAns 탐색
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-1; j++){
            if (board[i][j] == '.' && board[i][j+1] == '.'){
                rowAns++;
                while (j < N-1 && board[i][j+1] == '.'){
                    j++;
                }
            }
        }
    }

    // colAns 탐색
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-1; j++){
            if (board[j][i] == '.' && board[j+1][i] == '.'){
                colAns++;
                while (j < N-1 && board[j+1][i] == '.'){
                    j++;
                }
            }
        }
    }

    printf("%d %d", rowAns, colAns);
}