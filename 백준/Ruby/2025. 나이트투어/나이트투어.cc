#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int** marking;
vector<pair<int, int>> answer;

int dirY[10][8] = {{2, 2, -2, -2, 1, 1, -1, -1}, {1, -1, 1, -1 ,2, -2, 2, -2}, {-1, -1, 1, 1, -2, -2, 2, 2}, {-2, 2, -2, 2, -1, 1, -1, 1},
{1, 1, 2, 2, -1, -1, -2, -2}, {-2, -2, -1, -1, 2, 2, 1, 1}, {1, 1, -2, -2, -1, -1, 2, 2}, {2, 2, -1, -1, -2, -2, 1, 1},
{-1, 1, -2, 2, -1, 1, -2, 2}, {2, -2, 1, -1, 2, -2, 1, -1}};
int dirX[10][8] = {{1, -1, 1, -1, 2, -2, 2, -2}, {2, 2, -2, -2, 1, 1, -1, -1}, {-2, 2, -2, 2, -1, 1, -1, 1}, {-1, -1, 1, 1, -2, -2, 2, 2},
{-2, 2, -1, 1, -2, 2, -1, 1}, {1, -1, 2, -2, 1, -1, 2, -2}, {2, -2, 1, -1, 2, -2, 1, -1}, {-1, 1, -2, 2, -1, 1, -2, 2},
{-2, 2, -1, 1, 2, -2, 1, -1}, {-1, 1, -2, 2, 1, -1, 2, -2}};

// // int dirY[8] = {2, 2, 1, 1, -1, -1, -2, -2};
// // int dirX[8] = {1, -1, 2, -2, 2, -2, 1 ,-1};

// int dirY[8] = {2, 2, 1, 1, -2, -2, -1, -1};
// int dirX[8] = {1, -1, 2, -2, 1, -1, 2 ,-2};

bool canMove(int s, int t){
    if (s > 0 && s <= N && t > 0 && t <= N && marking[s][t] == -1){
        return true;
    }
    else{
        return false;
    }
}

int warnsdorff(int s, int t, int dirIdx){
    int degree = 0;

    for (int i = 0; i < 8; i++){
        int nextS = s + dirY[dirIdx][i];
        int nextT = t + dirX[dirIdx][i];
        if (canMove(nextS, nextT)){
            degree++;
        }
    }
    
    return degree;
}


void printAnswer(){
    for (int i = 0; i < answer.size(); i++){
        printf("%d %d\n", answer[i].first, answer[i].second);
    }
}

bool solve(int s, int t, int dirIdx){
    // isMarked를 전부 -1로 마킹
    marking = new int*[N+1];
    for (int i = 0; i < N+1; i++){
        marking[i] = new int[N+1];
    }
    for (int i = 0; i < N+1; i++){
        for (int j = 0; j < N+1; j++){
            marking[i][j] = -1;
        }
    }
    answer.clear();
    
    // 처음 위치 1로 마킹
    marking[s][t] = 1;
    answer.push_back({s, t});
    
    int mark = 1;
    int tmp = N*N;
    while (tmp > mark){
        // Warnsdorff's Rule
        int numNextMove = 0;
        int minValue = 9;
        int minIdx;
        for (int i = 0; i < 8; i++){
            int nextS = s + dirY[dirIdx][i];
            int nextT = t + dirX[dirIdx][i];
            if (canMove(nextS, nextT)){
                numNextMove++;
                int tmp = warnsdorff(nextS, nextT, dirIdx);
                if (minValue > tmp){
                    minValue = tmp;
                    minIdx = i;
                }
            }
        }

        if (!numNextMove){
            return false;
        }

        s += dirY[dirIdx][minIdx];
        t += dirX[dirIdx][minIdx];

        // 다음 위치 마킹
        marking[s][t] = 1;
        answer.push_back({s, t});

        mark++;
    }


    return true;
}



int main(){
    int s, t;
    scanf("%d", &N);

    scanf("%d %d", &s, &t);

    int dirIdx = 0;
    while (true){
        bool isSuccess = solve(s, t, dirIdx);
        if (isSuccess){
            printAnswer();
            return 0;
        }
        else{
            if (dirIdx == 9){
                printf("-1 -1");
                return 0;
            }
        }
        dirIdx++;
    }

}