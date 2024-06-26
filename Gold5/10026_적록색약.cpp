#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
#define MAX 101
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char painting1[MAX][MAX];
char painting2[MAX][MAX];
int answer1 = 0;
int answer2 = 0;

void bfsNormal(int y, int x, int N){
    char curColor = painting1[y][x];
    if (curColor != 'X'){
        answer1++;
        queue<pair<int, int>> order1;
        order1.push({y, x});
        painting1[y][x] = 'X';

        while (!order1.empty()){
            int curY = order1.front().first;
            int curX = order1.front().second;
            for (int i = 0; i < 4; i++){
                int nextY = curY+dir[i][0];
                int nextX = curX+dir[i][1];
                if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N){
                    char nextColor = painting1[nextY][nextX];
                    if (curColor == nextColor){
                        order1.push({nextY, nextX});
                        painting1[nextY][nextX] = 'X';
                    }
                }
            }
            order1.pop();
        }
    }
}

void bfsRG(int y, int x, int N){
    char curColor = painting2[y][x];
    if (curColor != 'X'){
        bool rg = false;
        if (curColor == 'R' || curColor == 'G'){
            rg = true;
        }
        answer2++;
        queue<pair<int, int>> order2;
        order2.push({y, x});
        painting2[y][x] = 'X';

        while (!order2.empty()){
            int curY = order2.front().first;
            int curX = order2.front().second;
            for (int i = 0; i < 4; i++){
                int nextY = curY+dir[i][0];
                int nextX = curX+dir[i][1];
                if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N){
                    char nextColor = painting2[nextY][nextX];
                    if (curColor == nextColor || (rg && (nextColor == 'R' || nextColor == 'G'))){
                        order2.push({nextY, nextX});
                        painting2[nextY][nextX] = 'X';
                    }
                }
            }
            order2.pop();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        string s;
        cin >> s;
        for (int j = 0; j < N; j++){
            painting1[i][j] = s[j];
            painting2[i][j] = s[j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            bfsNormal(i, j, N);
            bfsRG(i, j, N);
        }
    }
    cout << answer1 << " " << answer2;

}