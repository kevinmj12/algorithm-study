#include <iostream>
using namespace std;

int studentsOrder[401];
int studentFriends[401][4];
int table[20][20];
int n;
int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void solve(int index){
    int y, x;
    int maxFriends = -1;
    int maxEmpty = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // 테이블이 비어있는 경우
            if (!table[i][j]){
                int tmpFriends = 0;
                int tmpEmpty = 0;
                for (int dir = 0; dir < 4; dir++){
                    int nextY = i + direction[dir][0];
                    int nextX = j + direction[dir][1];
                    if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n){
                        // 테이블이 비어있는 경우
                        if (!table[nextY][nextX]){
                            tmpEmpty++;
                        }
                        // 테이블에 누군가 앉아있는 경우
                        else{
                            for (int f = 0; f < 4; f++){
                                if (table[nextY][nextX] == studentFriends[studentsOrder[index]][f]){
                                    tmpFriends++;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (tmpFriends > maxFriends){
                    y = i; x = j;
                    maxFriends = tmpFriends;
                    maxEmpty = tmpEmpty;
                }
                else if (tmpFriends == maxFriends && tmpEmpty > maxEmpty){
                    y = i; x = j;
                    maxEmpty = tmpEmpty;
                }
            }
        }
    }
    table[y][x] = studentsOrder[index];
}

void printAnswer(){
    int answer = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int tmpFriends = 0;
            for (int dir = 0; dir < 4; dir++){
                int nextY = i + direction[dir][0];
                int nextX = j + direction[dir][1];
                if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n){
                    for (int f = 0; f < 4; f++){
                        if (table[nextY][nextX] == studentFriends[table[i][j]][f]){
                            tmpFriends++;
                            break;
                        }
                    }                    
                }
            }

            if (tmpFriends == 1){
                answer += 1;
            }
            else if (tmpFriends == 2){
                answer += 10;
            }
            else if (tmpFriends == 3){
                answer += 100;
            }
            else if (tmpFriends == 4){
                answer += 1000;
            }
        }
    }

    cout << answer;
}

int main(){
    cin >> n;
    for (int i = 0; i < n*n; i++){
        int student;
        cin >> student;

        studentsOrder[i] = student;
        for (int j = 0; j < 4; j++){
            cin >> studentFriends[student][j];
        }
    }

    for (int i = 0; i < n*n; i++){
        solve(i);
    }

    printAnswer();
}